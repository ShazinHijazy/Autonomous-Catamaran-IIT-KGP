from urdfpy import URDF

# Replace this path with the path to your generated URDF file
robot = URDF.load("D:/Autonomous-Catamaran-IIT-KGP/updated_tested_and_debugged_code/sensor_nodes/catamaran.urdf")
# Display the robot model
robot.show()
