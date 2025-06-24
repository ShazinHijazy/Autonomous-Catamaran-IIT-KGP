import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import networkx as nx

# Abbreviated node names for clarity
components = {
    "LIDAR": "sensor",
    "USONIC": "sensor",
    "USERVO": "sensor",
    "GNSS": "sensor",
    "IMU": "sensor",
    "VSENSE": "sensor",
    "CSENSE": "sensor",
    "FUSION": "processing",
    "NAV2": "processing",
    "AVOID": "processing",
    "PWRMON": "processing",
    "PID": "processing",
    "THRUSTER": "actuator",
    "ROS2CORE": "infra"
}

edges = [
    ("LIDAR", "AVOID", "LaserScan"),
    ("USONIC", "AVOID", "Range"),
    ("USERVO", "AVOID", "ScanRange"),
    ("GNSS", "FUSION", "GPS"),
    ("IMU", "FUSION", "IMU"),
    ("VSENSE", "PWRMON", "Volt"),
    ("CSENSE", "PWRMON", "Curr"),
    ("FUSION", "NAV2", "Pose"),
    ("AVOID", "NAV2", "Costmap"),
    ("NAV2", "PID", "VelCmd"),
    ("PID", "THRUSTER", "PWM"),
    ("ROS2CORE", "NAV2", "DDS"),
    ("ROS2CORE", "PWRMON", "DDS"),
    ("ROS2CORE", "AVOID", "DDS"),
]

# Manual grid positions for clarity
positions = {
    # Sensors (left column)
    "LIDAR": (0, 6),
    "USONIC": (0, 5),
    "USERVO": (0, 4),
    "GNSS": (0, 3),
    "IMU": (0, 2),
    "VSENSE": (0, 1),
    "CSENSE": (0, 0),
    # Processing (middle columns)
    "AVOID": (2, 5),
    "FUSION": (2, 3),
    "PWRMON": (2, 1),
    "NAV2": (4, 4),
    "PID": (6, 4),
    # Actuator
    "THRUSTER": (8, 4),
    # Infra
    "ROS2CORE": (8, 1)
}

color_map = {
    "sensor": "#84c1ff",
    "processing": "#ffe084",
    "actuator": "#a1e3a1",
    "infra": "#d5a6ff"
}

G = nx.DiGraph()
for node, group in components.items():
    G.add_node(node, group=group)
for src, dst, label in edges:
    G.add_edge(src, dst, label=label)

node_colors = [color_map[G.nodes[n]['group']] for n in G.nodes]

plt.figure(figsize=(15, 8))
nx.draw_networkx_nodes(G, positions, node_color=node_colors, node_size=1800, edgecolors='black', linewidths=1.5)
nx.draw_networkx_labels(G, positions, font_size=12, font_weight="bold")
nx.draw_networkx_edges(G, positions, arrows=True, arrowstyle='-|>', arrowsize=15, width=2, connectionstyle='arc3,rad=0.1')

# Edge labels (optional, can be omitted for more clarity)
edge_labels = {(u, v): d['label'] for u, v, d in G.edges(data=True)}
nx.draw_networkx_edge_labels(G, positions, edge_labels=edge_labels, font_size=10, label_pos=0.4, rotate=False,
    bbox=dict(boxstyle="round,pad=0.2", fc="white", ec="none", alpha=0.7)
)

# Legend below the plot
patches = [mpatches.Patch(color=color, label=label.title()) for label, color in color_map.items()]
plt.legend(
    handles=patches,
    loc='upper center',
    bbox_to_anchor=(0.5, -0.08),
    ncol=4,
    fontsize='large',
    frameon=True
)

plt.title("Autonomous Catamaran – Data Flow Diagram (Manual Grid Layout)", fontsize=18, pad=20)
plt.axis('off')
plt.tight_layout(rect=[0.03, 0.03, 0.97, 0.97])
plt.show()

# Print abbreviation mapping for reference
print("\nNode abbreviation mapping:")
for k, v in {
    "LIDAR": "Lidar (RPLidar A1M8)",
    "USONIC": "Ultrasonic (AJ-SRO4M)",
    "USERVO": "Ultrasonic Servo (HC-SR04 + SG92R)",
    "GNSS": "GNSS (DFRobot DFR1103)",
    "IMU": "IMU (Phidgets Spatial 3/3/3)",
    "VSENSE": "Voltage Sensor",
    "CSENSE": "Current Sensor",
    "FUSION": "Sensor Fusion Node",
    "NAV2": "Navigation Stack (ROS2 Nav2)",
    "AVOID": "Obstacle Avoidance Node",
    "PWRMON": "Power Monitoring Node",
    "PID": "PID Control Node",
    "THRUSTER": "Thruster Controller (PWM to ESC)",
    "ROS2CORE": "ROS 2 Core (DDS)"
}.items():
    print(f"{k}: {v}")
