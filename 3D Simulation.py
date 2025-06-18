import pybullet as p
import pybullet_data
import time
import math
import matplotlib.pyplot as plt
from collections import deque
import threading

# --- PyBullet Setup ---
p.connect(p.GUI)
p.setAdditionalSearchPath(pybullet_data.getDataPath())
p.setGravity(0, 0, -9.8)
p.loadURDF("plane.urdf")

# --- Basic Box as Catamaran ---
box_col = p.createCollisionShape(p.GEOM_BOX, halfExtents=[0.3, 0.2, 0.1])
box_vis = p.createVisualShape(p.GEOM_BOX, halfExtents=[0.3, 0.2, 0.1], rgbaColor=[0.2, 0.5, 0.8, 1])
catamaran = p.createMultiBody(baseMass=10,
                               baseCollisionShapeIndex=box_col,
                               baseVisualShapeIndex=box_vis,
                               basePosition=[0, 0, 0.2])

# --- Physical Parameters ---
thruster_offset = 0.25
water_density = 1000
drag_coefficient = 0.5
frontal_area = 0.2 * 0.6
buoyancy_force = 98

# --- Data Recording ---
trajectory = deque(maxlen=500)
pwm_left = deque(maxlen=500)
pwm_right = deque(maxlen=500)
time_vals = deque(maxlen=500)

# --- Real-time Plotting Thread ---
def live_plot():
    plt.ion()
    fig, axs = plt.subplots(2, 1, figsize=(8, 6))

    while True:
        if time_vals:
            axs[0].cla()
            axs[0].plot(time_vals, pwm_left, label="Left Thruster PWM", color='blue')
            axs[0].plot(time_vals, pwm_right, label="Right Thruster PWM", color='green')
            axs[0].legend()
            axs[0].set_ylabel("PWM Signal")
            axs[0].set_ylim(1000, 2000)

            axs[1].cla()
            xs, ys = zip(*trajectory)
            axs[1].plot(xs, ys, label="Trajectory", color='red')
            axs[1].set_xlabel("X Position (m)")
            axs[1].set_ylabel("Y Position (m)")
            axs[1].legend()

            plt.pause(0.01)

plot_thread = threading.Thread(target=live_plot, daemon=True)
plot_thread.start()

# --- Force Application Logic ---
def apply_drag_and_buoyancy(body_id):
    lin_vel, _ = p.getBaseVelocity(body_id)
    vel_mag = math.sqrt(sum(v*v for v in lin_vel))
    drag_mag = 0.5 * water_density * drag_coefficient * frontal_area * vel_mag**2

    # Drag (opposite to velocity vector)
    drag_force = [-v * drag_mag for v in lin_vel]
    p.applyExternalForce(body_id, -1, drag_force, [0, 0, 0], p.WORLD_FRAME)

    # Buoyancy (constant upward)
    p.applyExternalForce(body_id, -1, [0, 0, buoyancy_force], [0, 0, 0], p.WORLD_FRAME)

# --- Simulation Loop ---
t = 0
base_pwm = 1500
delta_pwm = 100

left_pwm = base_pwm
right_pwm = base_pwm

while True:
    keys = p.getKeyboardEvents()
    thrust = 0
    turn = 0

    # --- Thruster Directional Controls ---
    if ord('w') in keys and keys[ord('w')] & p.KEY_IS_DOWN:
        thrust = 1
    elif ord('s') in keys and keys[ord('s')] & p.KEY_IS_DOWN:
        thrust = -1

    if ord('a') in keys and keys[ord('a')] & p.KEY_IS_DOWN:
        turn = 1
    elif ord('d') in keys and keys[ord('d')] & p.KEY_IS_DOWN:
        turn = -1

    # --- PWM Signal Controls ---
    if p.B3G_LEFT_ARROW in keys and keys[p.B3G_LEFT_ARROW] & p.KEY_WAS_TRIGGERED:
        left_pwm = max(1100, left_pwm - delta_pwm)
    if p.B3G_RIGHT_ARROW in keys and keys[p.B3G_RIGHT_ARROW] & p.KEY_WAS_TRIGGERED:
        left_pwm = min(1900, left_pwm + delta_pwm)
    if p.B3G_UP_ARROW in keys and keys[p.B3G_UP_ARROW] & p.KEY_WAS_TRIGGERED:
        right_pwm = min(1900, right_pwm + delta_pwm)
    if p.B3G_DOWN_ARROW in keys and keys[p.B3G_DOWN_ARROW] & p.KEY_WAS_TRIGGERED:
        right_pwm = max(1100, right_pwm - delta_pwm)

    # --- Convert PWM to Force (Linear Mapping) ---
    def pwm_to_force(pwm):
        if pwm > 1500:
            return (pwm - 1500) * 0.05
        elif pwm < 1500:
            return -1 * (1500 - pwm) * 0.05
        else:
            return 0

    f_left = pwm_to_force(left_pwm) + thrust + turn
    f_right = pwm_to_force(right_pwm) + thrust - turn

    # Apply forces
    p.applyExternalForce(catamaran, -1, [f_left, 0, 0], [0, thruster_offset, 0], p.WORLD_FRAME)
    p.applyExternalForce(catamaran, -1, [f_right, 0, 0], [0, -thruster_offset, 0], p.WORLD_FRAME)

    apply_drag_and_buoyancy(catamaran)

    # Record for plotting
    pos, _ = p.getBasePositionAndOrientation(catamaran)
    trajectory.append((pos[0], pos[1]))
    pwm_left.append(left_pwm)
    pwm_right.append(right_pwm)
    time_vals.append(t)
    t += 1

    p.stepSimulation()
    time.sleep(1 / 60)
