#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped

class DriveVehicle(Node):    
    def __init__(self):        
        super().__init__('drive_node')    

        self.get_logger().info('drive_node is initialized')
        self.drive_publish = self.create_publisher(AckermannDriveStamped,"/drive",10)

        self.create_timer(1.0,self.move_robot)

    def move_robot(self):
        robot_msg=AckermannDriveStamped()
        robot_msg.drive.speed=0.0
        robot_msg.drive.steering_angle=0.2
        self.drive_publish.publish(robot_msg)
def main(args=None):    
    rclpy.init(args=args)
    node = DriveVehicle()    
    rclpy.spin(node)
    node.destroy_node()    
    rclpy.shutdown()
if __name__ == '__main__':    
    main()