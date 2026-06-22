#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry

class Control(Node):
    def __init__(self):
        super().__init__('control_node')

        self.subscriber_ = self.create_subscription(Odometry, '/odom',self.moveForward,10)
        self.drive_publish = self.create_publisher(AckermannDriveStamped,"/drive",10)

        self.get_logger().info('subscriber_node has been started.')
        # self.create_timer(1.0,self.move_robot)
        # self.create_timer(1.0,self.moveForward)
        self.x = None
        self.y = None
        
        self.count=0
    def move_robot(self):
        robot_msg = AckermannDriveStamped()

        

        # robot_msg.drive.speed=0.0
        # robot_msg.drive.steering_angle=0.0
        # self.drive_publish.publish(robot_msg)


    def moveForward(self, msg):
        # self.get_logger().info(f'Received: "{msg.pose.pose.position}"')
        

        if self.count==0:
            self.x = msg.pose.pose.position.x 
            self.y = msg.pose.pose.position.y
            self.count=1
        
        robot_msg = AckermannDriveStamped()
        
        self.distance = ((msg.pose.pose.position.x - self.x)**2 + (msg.pose.pose.position.y - self.y))**(1/2)



        if self.distance <= 2.0:

            robot_msg.drive.speed=0.0
            self.drive_publish.publish(robot_msg)
        else:
            robot_msg.drive.speed=0.0
            self.drive_publish.publish(robot_msg)
            self.get_logger().info(f'da chay xong"')

        
        self.get_logger().info(f'distance: "{self.distance}"')
        
    

def main(args=None):
    rclpy.init(args=args)

    node = Control()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()