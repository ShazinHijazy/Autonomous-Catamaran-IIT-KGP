import pybullet as p
import pybullet_data
import time
import numpy as np

# === Constants ===
GRAVITY = -9.81
THRUSTER_FORCE_SCALE = 5     # Scale thruster effect (tune as needed)
DRAG_COEFF = 2.0              # Water resistance factor
BUOYANCY_FORCE = 50           # Force upwards to simulate floating
TIME_STEP = 1. / 240.

# === Connect to PyBullet GUI ===
physicsClient = p.connect(p.GUI)
p.setAdditionalSearchPath(pybullet_data.getDataPath())
p.setGravity(0, 0, GRAVITY)

# === Load Environment and Object ===
planeId = p.loadURDF("plane.urdf")
startPos = [0, 0, 0.3]  # Slightly above ground
startOrientation = p.getQuaternionFromEuler([0, 0, 0])
cubeId = p.loadURDF("cube.urdf", startPos, startOrientation, globalScaling=1)

# === Add Damping to Simulate Water Resistance ===
p.changeDynamics(cubeId, -1, linearDamping=0.5, angularDamping=0.5)

# === Initial PWM Values and Flags ===
left_pwm = 1500
right_pwm = 1500
pause = False

# === Convert PWM to Force ===
def pwm_to_force(pwm):
    if pwm > 1500:
        return (pwm - 1500) / 400 * THRUSTER_FORCE_SCALE
    elif pwm < 1500:
        return -(1500 - pwm) / 400 * THRUSTER_FORCE_SCALE
    return 0

# === Simulation Loop ===
for _ in range(20000):
    keys = p.getKeyboardEvents()

    # --- Handle Controls ---
    if ord('W') in keys and keys[ord('W')] & p.KEY_IS_DOWN:
        left_pwm += 5
        right_pwm += 5
    if ord('S') in keys and keys[ord('S')] & p.KEY_IS_DOWN:
        left_pwm -= 5
        right_pwm -= 5
    if ord('A') in keys and keys[ord('A')] & p.KEY_IS_DOWN:
        left_pwm -= 5
        right_pwm += 5
    if ord('D') in keys and keys[ord('D')] & p.KEY_IS_DOWN:
        left_pwm += 5
        right_pwm -= 5

    if p.B3G_LEFT_ARROW in keys and keys[p.B3G_LEFT_ARROW] & p.KEY_IS_DOWN:
        left_pwm += 5
    if p.B3G_RIGHT_ARROW in keys and keys[p.B3G_RIGHT_ARROW] & p.KEY_IS_DOWN:
        left_pwm -= 5
    if p.B3G_UP_ARROW in keys and keys[p.B3G_UP_ARROW] & p.KEY_IS_DOWN:
        right_pwm += 5
    if p.B3G_DOWN_ARROW in keys and keys[p.B3G_DOWN_ARROW] & p.KEY_IS_DOWN:
        right_pwm -= 5

    if p.B3G_SPACE in keys and keys[p.B3G_SPACE] & p.KEY_WAS_TRIGGERED:
        pause = not pause
    if ord('X') in keys and keys[ord('X')] & p.KEY_WAS_TRIGGERED:
        left_pwm = 1500
        right_pwm = 1500
    if ord('Q') in keys and keys[ord('Q')] & p.KEY_WAS_TRIGGERED:
        break

    # --- PWM Clipping ---
    left_pwm = np.clip(left_pwm, 1100, 1900)
    right_pwm = np.clip(right_pwm, 1100, 1900)

    if pause:
        p.stepSimulation()
        time.sleep(TIME_STEP)
        continue

    # === Convert PWM to Force ===
    lf = pwm_to_force(left_pwm)
    rf = pwm_to_force(right_pwm)

    # === Apply Forces to Simulate Thrusters ===
    p.applyExternalForce(cubeId, -1, [lf, 0, 0], [-0.3, 0.1, 0], p.LINK_FRAME)
    p.applyExternalForce(cubeId, -1, [rf, 0, 0], [-0.3, -0.1, 0], p.LINK_FRAME)

    # === Apply Buoyancy (centered) ===
    p.applyExternalForce(cubeId, -1, [0, 0, BUOYANCY_FORCE], [0, 0, 0], p.LINK_FRAME)

    # === Apply Drag ===
    lin_vel, _ = p.getBaseVelocity(cubeId)
    drag = -DRAG_COEFF * np.array(lin_vel)
    p.applyExternalForce(cubeId, -1, drag.tolist(), [0, 0, 0], p.LINK_FRAME)

    # === Step Simulation ===
    p.stepSimulation()
    time.sleep(TIME_STEP)

# === Disconnect ===
p.disconnect()
