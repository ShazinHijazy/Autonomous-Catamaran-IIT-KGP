import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, FancyArrowPatch

fig, ax = plt.subplots(figsize=(10, 6))

# Block positions and sizes
blocks = {
    "Sensors": (0.1, 0.6, 0.18, 0.18),
    "Sensor Nodes": (0.35, 0.6, 0.18, 0.18),
    "Planner (Nav / PID)": (0.6, 0.6, 0.22, 0.18),
    "Thruster Controller": (0.85, 0.6, 0.18, 0.18),
    "Power Monitor": (0.35, 0.3, 0.18, 0.13),
    "Logger / Diag": (0.6, 0.3, 0.22, 0.13),
}

# Draw blocks
for label, (x, y, w, h) in blocks.items():
    ax.add_patch(Rectangle((x, y), w, h, fill=True, color='#e0e0e0', ec='black', lw=2, zorder=2))
    ax.text(x + w/2, y + h/2, label, ha='center', va='center', fontsize=13, fontweight='bold', zorder=3)

# Draw arrows
def arrow(start, end, **kwargs):
    ax.add_patch(FancyArrowPatch(start, end, arrowstyle='-|>', mutation_scale=25, lw=2, color='black', **kwargs))

# Main horizontal flow
arrow((0.28, 0.69), (0.35, 0.69))
arrow((0.53, 0.69), (0.6, 0.69))
arrow((0.82, 0.69), (0.85, 0.69))

# Downward from Sensor Nodes to Power Monitor
arrow((0.44, 0.6), (0.44, 0.43))

# Downward from Planner to Logger/Diag
arrow((0.71, 0.6), (0.71, 0.43))

# Adjust plot
ax.set_xlim(0, 1.1)
ax.set_ylim(0.15, 0.85)
ax.axis('off')
plt.tight_layout()
plt.show()
