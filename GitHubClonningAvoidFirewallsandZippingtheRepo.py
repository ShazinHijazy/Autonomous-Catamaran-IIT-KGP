import os
import shutil
import zipfile
import subprocess

# Config
repo_url = "https://github.com/micro-ROS/micro_ros_espidf_component.git"
branch = "humble"
clone_dir = "micro_ros_espidf_component_humble"
output_dir = r"D:\Autonomous-Catamaran-IIT-KGP"
zip_filename = os.path.join(output_dir, f"{clone_dir}.zip")

# Remove existing directory if it exists
if os.path.exists(clone_dir):
    print(f"🧹 Removing existing folder: {clone_dir}")
    shutil.rmtree(clone_dir)

# Clone with submodules
print("🔄 Cloning repository with submodules...")
subprocess.run([
    "git", "clone", "--recurse-submodules", "-b", branch,
    repo_url, clone_dir
], check=True)
print("✅ Clone complete.")

# Zip the folder
print(f"🗜️  Creating ZIP at: {zip_filename}")
with zipfile.ZipFile(zip_filename, "w", zipfile.ZIP_DEFLATED) as zipf:
    for root, _, files in os.walk(clone_dir):
        for file in files:
            file_path = os.path.join(root, file)
            arcname = os.path.relpath(file_path, start=clone_dir)
            zipf.write(file_path, arcname)
print("✅ Archive created successfully.")
