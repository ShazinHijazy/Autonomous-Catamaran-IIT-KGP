import pigpio
import time
import sys
import csv
import socket
import threading

ESC_LEFT_PIN = 17
ESC_RIGHT_PIN = 18

PWM_NEUTRAL = 1500
PWM_STEP = 10
PWM_MIN = 1100
PWM_MAX = 1900

# Initialize pigpio
pi = pigpio.pi()
if not pi.connected:
    print("Could not connect to pigpio daemon. Is it running?")
    sys.exit(1)

def send_pwm(l, r):
    pi.set_servo_pulsewidth(ESC_LEFT_PIN, l)
    pi.set_servo_pulsewidth(ESC_RIGHT_PIN, r)
    now = time.strftime('%Y-%m-%d %H:%M:%S')
    writer.writerow([now, l, r])
    csvfile.flush()

left_pwm = PWM_NEUTRAL
right_pwm = PWM_NEUTRAL
paused = False
emergency_stop = False

def handle_command(cmd):
    global left_pwm, right_pwm, paused, emergency_stop
    cmd = cmd.strip().lower()
    updated = False

    if cmd == 'w':
        if not paused and not emergency_stop:
            left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
            right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
            updated = True
    elif cmd == 's':
        if not paused and not emergency_stop:
            left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
            right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
            updated = True
    elif cmd == 'a':
        if not paused and not emergency_stop:
            left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
            right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
            updated = True
    elif cmd == 'd':
        if not paused and not emergency_stop:
            left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
            right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
            updated = True
    elif cmd == 'up':
        if not paused and not emergency_stop:
            right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
            updated = True
    elif cmd == 'down':
        if not paused and not emergency_stop:
            right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
            updated = True
    elif cmd == 'left':
        if not paused and not emergency_stop:
            left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
            updated = True
    elif cmd == 'right':
        if not paused and not emergency_stop:
            left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
            updated = True
    elif cmd == ' ':
        paused = not paused
        if paused:
            send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
        updated = True
    elif cmd == 'x':
        emergency_stop = not emergency_stop
        if emergency_stop:
            send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
        updated = True
    elif cmd == 'r':
        left_pwm = PWM_NEUTRAL
        right_pwm = PWM_NEUTRAL
        paused = False
        updated = True
    elif cmd == 'q':
        return 'quit'
    else:
        return 'unknown'

    if updated and not paused and not emergency_stop:
        send_pwm(left_pwm, right_pwm)
    elif updated and (paused or emergency_stop):
        send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
    return 'ok'

def client_thread(conn, addr):
    conn.sendall(b"Thruster control connected. Use keyboard client to send commands.\n")
    while True:
        data = conn.recv(1024)
        if not data:
            break
        cmd = data.decode().strip()
        result = handle_command(cmd)
        if result == 'quit':
            conn.sendall(b"Quitting server.\n")
            break
        elif result == 'unknown':
            conn.sendall(b"Unknown command.\n")
        else:
            status = f"Left: {left_pwm} Right: {right_pwm} Paused: {paused} Emergency: {emergency_stop}\n"
            conn.sendall(status.encode())
    conn.close()

# Logging setup
csvfile = open('thruster_log.csv', 'w', newline='')
writer = csv.writer(csvfile)
writer.writerow(['timestamp', 'left_pwm', 'right_pwm'])

# Socket server setup
HOST = ''  # Listen on all interfaces
PORT = 65432

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)
print(f"Thruster server listening on port {PORT}...")

try:
    while True:
        conn, addr = server.accept()
        print(f"Connected by {addr}")
        threading.Thread(target=client_thread, args=(conn, addr)).start()
except KeyboardInterrupt:
    print("[INTERRUPTED]")
finally:
    send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
    pi.set_servo_pulsewidth(ESC_LEFT_PIN, 0)
    pi.set_servo_pulsewidth(ESC_RIGHT_PIN, 0)
    pi.stop()
    csvfile.close()
    server.close()
    print("[GPIO CLEANED UP] Log saved as thruster_log.csv")
