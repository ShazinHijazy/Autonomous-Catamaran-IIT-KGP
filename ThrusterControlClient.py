from pynput import keyboard
import socket

HOST = 'raspberrypi.local'  # Or use your Pi's IP address
PORT = 65432

def send_command(cmd):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            s.sendall(cmd.encode())
            response = s.recv(1024).decode()
            print(response.strip())
    except Exception as e:
        print(f"Error: {e}")

def on_press(key):
    try:
        if key.char in ['w', 'a', 's', 'd', 'x', 'r', 'q']:
            send_command(key.char)
            if key.char == 'q':
                print("Quitting client.")
                return False  # Stop listener
    except AttributeError:
        if key == keyboard.Key.up:
            send_command('up')
        elif key == keyboard.Key.down:
            send_command('down')
        elif key == keyboard.Key.left:
            send_command('left')
        elif key == keyboard.Key.right:
            send_command('right')
        elif key == keyboard.Key.space:
            send_command(' ')

print("Use arrow keys, space, or w/a/s/d/x/r/q to control. Press 'q' to quit.")
with keyboard.Listener(on_press=on_press) as listener:
    listener.join()
