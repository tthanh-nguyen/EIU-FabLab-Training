#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry



class SubscriberNode(Node):
    def __init__(self):
        super().__init__('subscriber_node')

        self.subscriber_ = self.create_subscription(Odometry, '/ego_racecar/odom',self.listener_callback,10)
        self.get_logger().info('subscriber_node has been started.')

    def listener_callback(self, msg):
        self.get_logger().info(f'Received: "{msg.pose.pose.position}"')
        self.get_logger().info(f'Received: "{msg.pose.pose.orientation}"')


def main(args=None):
    rclpy.init(args=args)

    node = SubscriberNode()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()