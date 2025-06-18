from graphviz import Digraph

dot = Digraph(comment="Catamaran Software Flow", format='png')

# Set graph attributes for high resolution and neat layout
dot.graph_attr.update(
    rankdir='TB',
    size='8,10',
    dpi='300',  # High DPI for clear text
    fontname='Arial'
)

# Nodes with clear, wrapped labels and larger font
dot.node('A', 'Start:\nUser presses key\n(arrow, w/a/s/d, space, etc.)',
         shape='oval', style='filled', fillcolor='#D6EAF8', fontsize='20', fontname='Arial')
dot.node('B', 'Client script sends command\nover WiFi (TCP)',
         shape='box', style='filled', fillcolor='#FCF3CF', fontsize='18', fontname='Arial')
dot.node('C', 'Server script (on Pi)\nreceives command',
         shape='box', style='filled', fillcolor='#FCF3CF', fontsize='18', fontname='Arial')
dot.node('D', 'Is command "q"?',
         shape='diamond', style='filled', fillcolor='#FADBD8', fontsize='18', fontname='Arial')
dot.node('E', 'Update PWM for ESCs/thrusters\nvia pigpio',
         shape='box', style='filled', fillcolor='#D5F5E3', fontsize='18', fontname='Arial')
dot.node('F', 'Send status back to client',
         shape='box', style='filled', fillcolor='#D5F5E3', fontsize='18', fontname='Arial')
dot.node('G', 'End (quit)',
         shape='oval', style='filled', fillcolor='#D6EAF8', fontsize='20', fontname='Arial')

# Edges for logical flow
dot.edge('A', 'B')
dot.edge('B', 'C')
dot.edge('C', 'D')
dot.edge('D', 'E', label='No', fontsize='16', fontname='Arial')
dot.edge('E', 'F')
dot.edge('F', 'A', label='Next key', fontsize='16', fontname='Arial')
dot.edge('D', 'G', label='Yes', fontsize='16', fontname='Arial')

# Save and render as PNG in the specified directory
output_path = r'D:\Autonomous-Catamaran-IIT-KGP\media\softwareflowchart'
dot.render(filename=output_path, cleanup=True)

print(f"Flowchart saved as {output_path}.png")
