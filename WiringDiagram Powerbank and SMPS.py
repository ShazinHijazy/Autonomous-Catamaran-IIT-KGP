from graphviz import Digraph

dot = Digraph('WiringDiagram', format='png')
dot.attr(rankdir='LR', size='10,6')

# SMPS block
dot.node('SMPS', '''SMPS (12V)\n+12V     GND(COM)''', shape='box', style='filled', fillcolor='lightyellow')

# ESC blocks
dot.node('ESC1', '''ESC 1\n+12V  GND  PWM''', shape='box', style='filled', fillcolor='lightblue')
dot.node('ESC2', '''ESC 2\n+12V  GND  PWM''', shape='box', style='filled', fillcolor='lightblue')

# Thruster blocks
dot.node('T1', 'T100 Thruster 1', shape='ellipse', style='filled', fillcolor='lightgrey')
dot.node('T2', 'T100 Thruster 2', shape='ellipse', style='filled', fillcolor='lightgrey')

# Pi/Arduino block
dot.node('MCU', 'Raspberry Pi / Arduino\n(GPIOs)', shape='box', style='filled', fillcolor='palegreen')

# Power wiring
dot.edge('SMPS', 'ESC1', label='+12V\nGND', color='brown')
dot.edge('SMPS', 'ESC2', label='+12V\nGND', color='brown')

# ESC to Thruster
dot.edge('ESC1', 'T1', label='Motor Wires', color='black')
dot.edge('ESC2', 'T2', label='Motor Wires', color='black')

# PWM wiring
dot.edge('MCU', 'ESC1', label='PWM', color='blue')
dot.edge('MCU', 'ESC2', label='PWM', color='blue')

# GND common
dot.edge('MCU', 'ESC1', label='GND', style='dashed', color='gray')
dot.edge('MCU', 'ESC2', label='GND', style='dashed', color='gray')

# Render diagram
dot.render('wiring_diagram', view=True)
