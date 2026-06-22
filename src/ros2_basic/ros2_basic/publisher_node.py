#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class PublisherNode(Node):
    def __init__(self):
        super().__init__('publisher_node')

        self.publisher_ = self.create_publisher(String,'/chatter',10)
        self.counter_ = 0
        self.timer_ = self.create_timer(1.0,self.publish_message)
        self.get_logger().info('publisher_node has been started.')

    def publish_message(self):
        msg = String()
        msg.data = f'Hello ROS 2: {self.counter_}'
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')
        self.counter_ += 1


def main(args=None):
    rclpy.init(args=args)

    node = PublisherNode()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()