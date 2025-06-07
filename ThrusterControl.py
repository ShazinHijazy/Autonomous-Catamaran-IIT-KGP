import pigpio
import time
import sys
import csv
import curses

ESC_LEFT_PIN = 17
ESC_RIGHT_PIN = 18

PWM_NEUTRAL = 1500
PWM_STEP = 10
PWM_MIN = 1000
PWM_MAX = 2000

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

def main(stdscr):
    left_pwm = PWM_NEUTRAL
    right_pwm = PWM_NEUTRAL
    paused = False
    emergency_stop = False

    stdscr.nodelay(False)  # Wait for keypress during startup
    stdscr.keypad(True)
    curses.noecho()
    curses.cbreak()

    # --- ESC ARMING: Send neutral at startup ---
    send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
    stdscr.clear()
    stdscr.addstr(0, 0, "--- Thruster Control ---")
    stdscr.addstr(2, 0, "ESCs are being armed with neutral signal (1500us).")
    stdscr.addstr(3, 0, "Press Enter to START the system...")
    stdscr.refresh()

    # --- Wait for Enter key to start ---
    while True:
        key = stdscr.getch()
        if key in (10, 13, curses.KEY_ENTER):
            break

    stdscr.nodelay(True)  # Switch to non-blocking mode for main loop

    stdscr.clear()
    stdscr.addstr(0, 0, "--- Arrow/WASD Key Thruster Control ---")
    stdscr.addstr(1, 0, "Left/Right: Decrease/Increase LEFT thruster")
    stdscr.addstr(2, 0, "Up/Down:   Increase/Decrease RIGHT thruster")
    stdscr.addstr(3, 0, "w/s:       Both thrusters forward/backward")
    stdscr.addstr(4, 0, "a/d:       Rotate left/right")
    stdscr.addstr(5, 0, "Space:     Pause/Resume")
    stdscr.addstr(6, 0, "r:         Reset both to 1500us (neutral)")
    stdscr.addstr(7, 0, "x:         Emergency stop (toggle)")
    stdscr.addstr(8, 0, "q:         Quit and save log")
    stdscr.refresh()

    while True:
        key = stdscr.getch()
        updated = False

        # Emergency stop toggle
        if key in (ord('x'), ord('X')):
            emergency_stop = not emergency_stop
            if emergency_stop:
                send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
            updated = True

        if emergency_stop:
            if key in (ord('q'), ord('Q')):
                break
            stdscr.addstr(10, 0, f"EMERGENCY STOP: ACTIVE! Press x to release.   ")
            stdscr.addstr(11, 0, f"Left PWM : {PWM_NEUTRAL} us      ")
            stdscr.addstr(12, 0, f"Right PWM: {PWM_NEUTRAL} us      ")
            stdscr.addstr(13, 0, f"Paused   : {'YES' if paused else 'NO '}      ")
            stdscr.refresh()
            time.sleep(0.05)
            continue

        if key == curses.KEY_LEFT:
            if not paused:
                left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
                updated = True
        elif key == curses.KEY_RIGHT:
            if not paused:
                left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
                updated = True
        elif key == curses.KEY_UP:
            if not paused:
                right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
                updated = True
        elif key == curses.KEY_DOWN:
            if not paused:
                right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
                updated = True
        elif key in (ord('w'), ord('W')):
            if not paused:
                left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
                right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
                updated = True
        elif key in (ord('s'), ord('S')):
            if not paused:
                left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
                right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
                updated = True
        elif key in (ord('a'), ord('A')):
            if not paused:
                left_pwm = max(PWM_MIN, left_pwm - PWM_STEP)
                right_pwm = min(PWM_MAX, right_pwm + PWM_STEP)
                updated = True
        elif key in (ord('d'), ord('D')):
            if not paused:
                left_pwm = min(PWM_MAX, left_pwm + PWM_STEP)
                right_pwm = max(PWM_MIN, right_pwm - PWM_STEP)
                updated = True
        elif key in (ord('r'), ord('R')):
            left_pwm = PWM_NEUTRAL
            right_pwm = PWM_NEUTRAL
            paused = False
            updated = True
        elif key == ord(' '):
            paused = not paused
            if paused:
                send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
            updated = True
        elif key in (ord('q'), ord('Q')):
            break

        # Always show status
        stdscr.addstr(10, 0, f"EMERGENCY STOP: {'ACTIVE!' if emergency_stop else 'INACTIVE'}                ")
        stdscr.addstr(11, 0, f"Left PWM : {left_pwm} us      ")
        stdscr.addstr(12, 0, f"Right PWM: {right_pwm} us      ")
        stdscr.addstr(13, 0, f"Paused   : {'YES' if paused else 'NO '}      ")
        stdscr.refresh()

        if updated and not paused and not emergency_stop:
            send_pwm(left_pwm, right_pwm)
        elif updated and (paused or emergency_stop):
            send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)

        time.sleep(0.05)

# Logging setup
csvfile = open('thruster_log.csv', 'w', newline='')
writer = csv.writer(csvfile)
writer.writerow(['timestamp', 'left_pwm', 'right_pwm'])

try:
    curses.wrapper(main)
except KeyboardInterrupt:
    print("[INTERRUPTED]")
finally:
    send_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
    pi.set_servo_pulsewidth(ESC_LEFT_PIN, 0)
    pi.set_servo_pulsewidth(ESC_RIGHT_PIN, 0)
    pi.stop()
    csvfile.close()
    print("[GPIO CLEANED UP] Log saved as thruster_log.csv")