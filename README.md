# Autonomous Catamaran Thruster Control System

This project demonstrates a Python-based thruster control system for an autonomous catamaran, developed using a Raspberry Pi 3B and T100 Thrusters from Blue Robotics. It enables both manual and future autonomous control using real-time keyboard input via SSH or a local interface.

The aim of this project is to establish a foundational control layer for a maritime surface vehicle, supporting future integration with sensors, navigation algorithms, and autonomy frameworks.

## 🚀 Features

- Real-time control of dual thrusters via keyboard (WASD + arrow keys)
- Adjustable speed control for each thruster independently
- Safety features:
  - Emergency stop (X)
  - Pause and resume (Spacebar)
  - Reset all speeds (R)
- Terminal dashboard with thruster status
- Raspberry Pi-compatible (tested with headless setup)
- PWM signal generation through pigpio

## 🔧 Hardware Requirements

- 1 × Raspberry Pi 3B (with Raspberry Pi OS 32-bit)
- 2 × Blue Robotics T100 Thrusters
- 2 × Electronic Speed Controllers (ESCs)
- 4 × 3.7V Li-Ion Batteries (connected in series for 14.8V total)
- 1 × Powerbank (for Raspberry Pi)
- Jumper wires, connectors, and waterproof enclosures
- Catamaran hull built by the Ocean Engineering and Naval Architecture team

## 🧠 Software Requirements

- Python 3.7 or higher
- pigpio library (PWM control)
- keyboard library (for keyboard input)
- SSH setup for remote access (optional)
- Tested on both Windows and Raspberry Pi OS

## 🔹 Controls

| Key         | Action                            |
|-------------|------------------------------------|
| W           | Move forward                       |
| S           | Move backward                      |
| A           | Turn left                          |
| D           | Turn right                         |
| ↑ (Up)      | Increase speed (left thruster)     |
| ↓ (Down)    | Decrease speed (left thruster)     |
| → (Right)   | Increase speed (right thruster)    |
| ← (Left)    | Decrease speed (right thruster)    |
| Space       | Pause/Resume thrusters             |
| X           | Emergency Stop/Resume              |
| R           | Reset both thrusters to 0          |
| Q           | Quit program                       |

## ⚙️ How to Run

1. Enable pigpio daemon on the Raspberry Pi:
   ```bash
   sudo pigpiod
   ```

2. Clone this repository:
   ```bash
   git clone https://github.com/your-username/thruster-control-catamaran.git
   cd thruster-control-catamaran
   ```

3. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

4. Run the main control script:
   ```bash
   python ThrusterControl.py
   ```

## 📦 File Structure

| File                     | Description                             |
|--------------------------|-----------------------------------------|
| ThrusterControl.py       | Main control script for the thrusters   |
| README.md                | This documentation file                 |
| requirements.txt         | Python dependencies                     |

## 🎓 Project Contributors

This project was developed by:

- Mohamed Hijazy Shazin Hassan  
  B.Tech CSE, A1-3/4  
  Department of Computer Science and Systems Engineering  
  Andhra University

- Bobbadi Jaswanth Kumar  
  B.Tech CSE, 2/6  
  Department of Computer Science and Systems Engineering  
  Andhra University

## 👯 Supervision

This work was carried out under the guidance of:

- Prof. K. Lakshmi Vasudev  
  Assistant Professor  
  Department of Ocean Engineering and Naval Architecture  
  Andhra University

With technical mentorship from:

- Mr. Sharad Kumar  
  Department of Ocean Engineering and Naval Architecture  
  Indian Institute of Technology Kharagpur (IIT KGP)

## 📌 Future Work

- Integrate IMU and GPS for navigation
- Add wireless control via GUI (e.g., Streamlit or WebSocket)
- Implement obstacle avoidance and autonomous route planning
- Sensor fusion and data logging
- ROS or ArduPilot integration

## 📝 License

This project is licensed under the MIT License – see the LICENSE file for details.
