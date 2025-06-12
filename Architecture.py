from diagrams import Diagram, Cluster, Edge
from diagrams.custom import Custom
import os

# Ensure the output directory exists
output_dir = r"D:\Autonomous-Catamaran-IIT-KGP\media"
os.makedirs(output_dir, exist_ok=True)

def LargeCustom(label, icon_name):
    # All icons are in media\icons, and output is in media, so use relative path from output file
    return Custom(label, f"icons/{icon_name}", width="3.2", height="3.2", imagescale="true")

graph_attr = {
    "fontsize": "26",
    "bgcolor": "white",
    "pad": "2.5",
    "nodesep": "2.5",
    "ranksep": "3.2",
    "overlap": "false",
    "splines": "polyline",
    "rankdir": "LR",  # Landscape orientation
    "page": "44,28",  # Very large page size for landscape and clarity
}

output_file = os.path.join(output_dir, "autonomous_catamaran_architecture")

with Diagram(
    "Autonomous Catamaran Architecture",
    filename=output_file,
    show=True,
    direction="LR",
    graph_attr=graph_attr
):
    # Central processing units
    pi = LargeCustom("Raspberry Pi 3B\n(Main Computer)", "raspberry_pi.png")
    esp32 = LargeCustom("ESP32\n(Microcontroller)", "esp_32.png")

    # Buck converters for Pi and ESP32
    buck_pi = LargeCustom("Buck Converter\n(for Pi)", "buck_converter.png")
    buck_esp = LargeCustom("Buck Converter\n(for ESP32)", "buck_converter.png")

    # Sensors cluster
    with Cluster("Sensors", graph_attr={"bgcolor": "#e8f0fe", "style": "filled", "labeljust": "l"}):
        gps = LargeCustom("GNSS/GPS\nModule", "gps.png")
        imu = LargeCustom("IMU\n(Accel/Gyro/Mag)", "imu.png")
        lidar = LargeCustom("LiDAR", "lidar.png")
        ultrasonic = LargeCustom("Ultrasonic\nSensors", "ultrasonic.png")
        power_sensors = LargeCustom("Voltage & Current\nSensor", "power_sensor.png")

    # Actuators cluster
    with Cluster("Actuators", graph_attr={"bgcolor": "#fff4e5", "style": "filled", "labeljust": "l"}):
        thrusters = LargeCustom("T100 Thrusters\n+ ESCs", "thruster.png")
        servos = LargeCustom("Servo Motors", "servo.png")

    # Communication and power
    telemetry = LargeCustom("Telemetry\nModule", "telemetry.png")
    battery = LargeCustom("Battery Pack", "battery.png")

    # Sensor data flow
    gps >> Edge(label="Position Data", fontsize="22") >> pi
    lidar >> Edge(label="Obstacle Data", fontsize="22") >> pi
    imu >> Edge(label="IMU Data", fontsize="22") >> esp32
    ultrasonic >> Edge(label="Ultrasonic Data", fontsize="22") >> pi
    power_sensors >> Edge(label="Power Data", fontsize="22") >> pi

    # ESP32 sends PWM control signals to thrusters
    esp32 >> Edge(label="PWM Control Signals", fontsize="22") >> thrusters

    # Raspberry Pi sends control signals to servos
    pi >> Edge(label="Servo Control", fontsize="22") >> servos

    # Telemetry data flow
    pi >> Edge(label="Telemetry Data", fontsize="22") >> telemetry

    # Power distribution with buck converters
    battery >> Edge(label="Power to Pi", fontsize="22") >> buck_pi
    buck_pi >> Edge(label="Regulated Power", fontsize="22") >> pi

    battery >> Edge(label="Power to ESP32", fontsize="22") >> buck_esp
    buck_esp >> Edge(label="Regulated Power", fontsize="22") >> esp32

    # Direct battery lines for other components
    battery >> gps
    battery >> imu
    battery >> lidar
    battery >> ultrasonic
    battery >> power_sensors
    battery >> thrusters
    battery >> servos
    battery >> telemetry

    # Power monitoring taps into battery supply
    battery >> Edge(label="Monitored Power", fontsize="22") >> power_sensors

print(f"Diagram saved to {output_file}.png")
