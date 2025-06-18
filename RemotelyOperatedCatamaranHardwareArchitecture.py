from graphviz import Digraph

dot = Digraph(comment="Remote-Controlled Catamaran Hardware Architecture", format='png')

# Graph attributes for clarity and high resolution
dot.graph_attr.update(
    rankdir='LR',  # Left-to-right layout
    dpi='300',
    fontname='Arial',
    size='12,8'
)

# Base node style
base_style = {'style': 'filled', 'fontname': 'Arial', 'fontsize': '20'}

# Nodes with unique fillcolors, no duplication
dot.node('A', 'Remote Control Station\n(Laptop/PC)\n(Client Software)', fillcolor='#AED6F1', shape='box', **base_style)
dot.node('B', 'WiFi Router/\nAccess Point', fillcolor='#D6DBDF', shape='ellipse', **base_style)
dot.node('C', 'Raspberry Pi\n(Server Software)\nPWM Generation', fillcolor='#F9E79F', shape='box', **base_style)
dot.node('D', 'ESC\n(Left)', fillcolor='#FADBD8', shape='box', **base_style)
dot.node('E', 'ESC\n(Right)', fillcolor='#FADBD8', shape='box', **base_style)
dot.node('F', 'T-100 Thruster\n(Left)', fillcolor='#D5F5E3', shape='box', **base_style)
dot.node('G', 'T-100 Thruster\n(Right)', fillcolor='#D5F5E3', shape='box', **base_style)
dot.node('H', 'Main Power Supply\n(12–16V, ESCs & Thrusters)', fillcolor='#D7BDE2', shape='cylinder', **base_style)
dot.node('I', 'Power Bank\n(5V USB, Pi only)', fillcolor='#85C1E9', shape='cylinder', **base_style)
dot.node('J', 'Optional Sensors\n(GPS, IMU, Camera, etc.)', fillcolor='#ABEBC6', shape='box', **base_style)

# Edges (Signals and Power)
dot.edge('A', 'B', label='WiFi\nTCP/IP', color='#2874A6', fontsize='18', fontname='Arial')
dot.edge('B', 'C', label='WiFi\nTCP/IP', color='#2874A6', fontsize='18', fontname='Arial')
dot.edge('C', 'D', label='PWM (GPIO17)', color='#B9770E', fontsize='18', fontname='Arial')
dot.edge('C', 'E', label='PWM (GPIO18)', color='#B9770E', fontsize='18', fontname='Arial')
dot.edge('D', 'F', label='Motor Power\n(DC)', color='#229954', fontsize='18', fontname='Arial')
dot.edge('E', 'G', label='Motor Power\n(DC)', color='#229954', fontsize='18', fontname='Arial')
dot.edge('H', 'D', label='12–16V', color='#8E44AD', fontsize='18', fontname='Arial')
dot.edge('H', 'E', label='12–16V', color='#8E44AD', fontsize='18', fontname='Arial')
dot.edge('I', 'C', label='5V USB', color='#2874A6', fontsize='18', fontname='Arial')
dot.edge('J', 'C', label='Sensor Data\n(I2C/UART/USB)', color='#117864', fontsize='18', fontname='Arial')

# Save and render as PNG in the specified directory
output_path = r'D:\Autonomous-Catamaran-IIT-KGP\media\RemoteControlledCatamaranArchitecture'
dot.render(filename=output_path, cleanup=True)

print(f"Architecture diagram saved as {output_path}.png")
