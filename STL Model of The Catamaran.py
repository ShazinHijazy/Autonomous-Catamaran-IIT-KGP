import trimesh
from trimesh.creation import cylinder, box

# === Parameters ===
hull_length = 1.5
hull_radius = 0.05
hull_thickness = 0.005  # Hull wall thickness
deck_length = 0.25
deck_width = 0.1
deck_thickness = 0.005
hull_gap = 0.125  # Center-to-center gap between hulls

# === Hull with Open Top ===
def create_hollow_hull(length, radius, thickness):
    # Outer cylinder
    outer = cylinder(radius=radius, height=length, sections=64)
    # Inner cylinder (for hollow)
    inner = cylinder(radius=radius - thickness, height=length - thickness, sections=64)
    inner.apply_translation([0, 0, thickness])
    hull = outer.difference(inner)
    # Cut open the top (remove upper half)
    z_cut = box([radius*2, radius*2, length*1.1], 
                transform=trimesh.transformations.translation_matrix([0, 0, length/2]))
    z_cut.apply_translation([0, 0, radius/2])
    hull = hull.difference(z_cut)
    return hull

# === Hulls ===
left_hull = create_hollow_hull(hull_length, hull_radius, hull_thickness)
right_hull = create_hollow_hull(hull_length, hull_radius, hull_thickness)

# Position hulls (parallel, open tops up)
left_hull.apply_translation([0, -hull_gap/2, hull_radius])
right_hull.apply_translation([0, hull_gap/2, hull_radius])

# === Thruster Holes at Rear Top ===
thruster_radius = 0.02
thruster_distance = 0.04  # Distance between two holes (y direction)
thruster_hole_depth = hull_thickness * 2
rear_x = hull_length/2 - thruster_radius
thruster_z = hull_radius * 2 - hull_thickness / 2  # Top surface of hull

def add_thruster_holes(hull, y_offset):
    for i in [-thruster_distance/2, thruster_distance/2]:
        hole = cylinder(radius=thruster_radius, height=thruster_hole_depth, sections=32)
        # Place at rear, correct y, top surface
        hole.apply_translation([
            rear_x, 
            y_offset + i, 
            thruster_z - thruster_hole_depth / 2
        ])
        hull = hull.difference(hole)
    return hull

left_hull = add_thruster_holes(left_hull, -hull_gap/2)
right_hull = add_thruster_holes(right_hull, hull_gap/2)

# === Deck ===
deck = box(extents=[deck_length, deck_width, deck_thickness])
# Place deck so its bottom sits at the top of the hulls
deck.apply_translation([0, 0, hull_radius * 2 + deck_thickness / 2])

# === Combine all ===
catamaran = trimesh.util.concatenate([
    left_hull, right_hull, deck
])

# === Export STL ===
catamaran.export(r"D:\Autonomous-Catamaran-IIT-KGP\catamaran_model_25cm_deck.stl")
print("✅ Exported 'catamaran_model_25cm_deck.stl' to D:\\Autonomous-Catamaran-IIT-KGP")