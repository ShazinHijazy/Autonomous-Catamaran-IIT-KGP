from pyflowchart import *

# Start node
st = StartNode('Remote Catamaran Control')

# Input: User presses key on remote computer
io1 = InputOutputNode(InputOutputNode.INPUT, 'User presses key (arrow, w/a/s/d, space, etc.)')

# Operation: Client sends command over WiFi
op1 = OperationNode('Client script sends command over WiFi (TCP)')

# Operation: Server receives command
op2 = OperationNode('Server script (on Pi) receives command')

# Condition: Is command "q" (quit)?
cond1 = ConditionNode('Command == "q"?')

# Operation: Handle thruster control
op3 = OperationNode('Update PWM for ESCs/thrusters via pigpio')

# Output: Send status back to client
io2 = InputOutputNode(InputOutputNode.OUTPUT, 'Send status back to client')

# End node
e = EndNode('End (quit)')

# Connect nodes
st.connect(io1)
io1.connect(op1)
op1.connect(op2)
op2.connect(cond1)
cond1.connect_no(op3)
op3.connect(io2)
io2.connect(io1)  # Loop back for next key press
cond1.connect_yes(e)

# Create flowchart object
fc = Flowchart(st)

# Print flowchart.js code (can be pasted into http://flowchart.js.org for visualization)
print(fc.flowchart())

# Optionally, output to HTML for visual viewing:
from pyflowchart import output_html
output_html('catamaran_flowchart.html', 'Remote Catamaran Control', fc.flowchart())
