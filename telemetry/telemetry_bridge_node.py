import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial
import threading

class TelemetryBridgeNode(Node):
    def __init__(self):
        super().__init__('telemetry_bridge_node')

        # --- Serial Port Settings ---
        serial_port = '/dev/ttyUSB0'  # Adjust based on your system
        baud_rate = 57600             # Default for SiK radios

        try:
            self.ser = serial.Serial(serial_port, baud_rate, timeout=1)
            self.get_logger().info(f'✅ Serial port {serial_port} opened at {baud_rate} baud.')
        except serial.SerialException as e:
            self.get_logger().error(f'❌ Failed to open serial port: {e}')
            rclpy.shutdown()
            return

        # --- ROS 2 Communication ---
        self.pub_from_serial = self.create_publisher(String, 'telemetry/in', 10)
        self.sub_to_serial = self.create_subscription(String, 'telemetry/out', self.serial_write_callback, 10)

        # --- Serial Read Thread ---
        self.running = True
        self.thread = threading.Thread(target=self.read_serial, daemon=True)
        self.thread.start()

    def read_serial(self):
        while self.running:
            try:
                if self.ser.in_waiting > 0:
                    raw_data = self.ser.readline().decode('utf-8', errors='ignore').strip()
                    if raw_data:
                        msg = String()
                        msg.data = raw_data
                        self.pub_from_serial.publish(msg)
                        self.get_logger().info(f"⬅️ [FROM BASE] {raw_data}")
            except Exception as e:
                self.get_logger().error(f"Serial Read Error: {e}")

    def serial_write_callback(self, msg: String):
        try:
            message = msg.data.strip() + '\n'
            self.ser.write(message.encode('utf-8'))
            self.get_logger().info(f"➡️ [TO BASE] {message.strip()}")
        except Exception as e:
            self.get_logger().error(f"Serial Write Error: {e}")

    def destroy_node(self):
        self.running = False
        self.ser.close()
        self.get_logger().info('🛑 Serial port closed and node shut down.')
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = TelemetryBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 Keyboard interrupt received. Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
