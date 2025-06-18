import pygame
import sys
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque

# --- Pygame Initialization ---
pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Catamaran Thruster Simulation")

WHITE = (255, 255, 255)
BLUE = (0, 150, 255)
RED = (255, 0, 0)
GRAY = (200, 200, 200)
BLACK = (0, 0, 0)

font = pygame.font.SysFont(None, 24)

# --- Catamaran State Variables ---
x, y = 400, 300
trajectory = []
angle = 0
speed_left = 1500
speed_right = 1500

paused = False
running = True

# PWM Range
max_pwm = 1900
min_pwm = 1100
neutral_pwm = 1500

# Water drag coefficient
drag = 0.95

# --- Real-time PWM Logging ---
pwm_log_len = 200
pwm_left_log = deque([neutral_pwm]*pwm_log_len, maxlen=pwm_log_len)
pwm_right_log = deque([neutral_pwm]*pwm_log_len, maxlen=pwm_log_len)

# --- Matplotlib Setup for PWM Plot ---
fig, ax = plt.subplots()
line_left, = ax.plot([], [], label='Left Thruster PWM', color='red')
line_right, = ax.plot([], [], label='Right Thruster PWM', color='blue')
ax.set_ylim(1000, 2000)
ax.set_xlim(0, pwm_log_len)
ax.legend()
ax.set_title("PWM Signal Over Time")

def update_plot(frame):
    line_left.set_ydata(pwm_left_log)
    line_right.set_ydata(pwm_right_log)
    line_left.set_xdata(range(len(pwm_left_log)))
    line_right.set_xdata(range(len(pwm_right_log)))
    return line_left, line_right

ani = animation.FuncAnimation(fig, update_plot, interval=100)

# --- Simulation Loop ---
while running:
    pygame.time.Clock().tick(30)
    screen.fill(WHITE)

    keys = pygame.key.get_pressed()

    if not paused:
        # Calculate thrust from PWM
        thrust_left = (speed_left - neutral_pwm) / 400.0
        thrust_right = (speed_right - neutral_pwm) / 400.0

        # Water drag
        thrust_left *= drag
        thrust_right *= drag

        # Update logs
        pwm_left_log.append(speed_left)
        pwm_right_log.append(speed_right)

        # Movement calculations
        linear = (thrust_left + thrust_right) / 2.0
        angular = (thrust_right - thrust_left) / 4.0

        # Update position
        x += linear * 10
        y += angular * 20

        # Save trajectory
        trajectory.append((int(x), int(y)))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_w:
                speed_left = min(speed_left + 100, max_pwm)
                speed_right = min(speed_right + 100, max_pwm)

            elif event.key == pygame.K_s:
                speed_left = max(speed_left - 100, min_pwm)
                speed_right = max(speed_right - 100, min_pwm)

            elif event.key == pygame.K_a:
                speed_left = max(speed_left - 100, min_pwm)
                speed_right = min(speed_right + 100, max_pwm)

            elif event.key == pygame.K_d:
                speed_left = min(speed_left + 100, max_pwm)
                speed_right = max(speed_right - 100, min_pwm)

            elif event.key == pygame.K_UP:
                speed_right = min(speed_right + 50, max_pwm)
            elif event.key == pygame.K_DOWN:
                speed_right = max(speed_right - 50, min_pwm)

            elif event.key == pygame.K_LEFT:
                speed_left = max(speed_left - 50, min_pwm)
            elif event.key == pygame.K_RIGHT:
                speed_left = min(speed_left + 50, max_pwm)

            elif event.key == pygame.K_SPACE:
                paused = not paused

            elif event.key == pygame.K_x:
                speed_left = neutral_pwm
                speed_right = neutral_pwm
                print("EMERGENCY STOP")

            elif event.key == pygame.K_q:
                running = False

    # Draw trajectory
    for point in trajectory:
        pygame.draw.circle(screen, GRAY, point, 2)

    # Draw catamaran
    pygame.draw.rect(screen, BLUE, (x - 20, y - 10, 40, 20))
    pygame.draw.circle(screen, RED, (x - 30, y), 5)  # Left thruster
    pygame.draw.circle(screen, RED, (x + 30, y), 5)  # Right thruster

    # Status Text
    text1 = font.render(f"Left PWM: {speed_left}", True, BLACK)
    text2 = font.render(f"Right PWM: {speed_right}", True, BLACK)
    screen.blit(text1, (10, 10))
    screen.blit(text2, (10, 30))

    pygame.display.flip()
    plt.pause(0.001)

pygame.quit()
plt.close()
sys.exit()
