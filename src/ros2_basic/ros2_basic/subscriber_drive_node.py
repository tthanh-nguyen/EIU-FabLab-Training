#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped


class SubscribeNode(Node):
    def __init__(self):
        super().__init__('subscriber_drive_node')
        self.drive_subscriber = self.create_subscription(AckermannDriveStamped, '/ego_racecar/odom',self.listener_callback,10)
        self.get_logger().info('subscriber_drive_node has been started.')

    def listener_callback(self, msg):
        self.get_logger().info(f'Received: "{robot_msg}"')


def main(args=None):
    rclpy.init(args=args)

    node = SubscribeNode()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()