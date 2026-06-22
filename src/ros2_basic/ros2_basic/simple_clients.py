#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from f1tenth_msgs.srv import AddTwoInts

class SimpleServiceClients(Node):
    def __init__(self):
        super().__init__("Simple_service_client")
        self.client_ = self.create_client(AddTwoInts, "add_two_ints")

        while not self.client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Wait for service...')
        self.request_= AddTwoInts.Request()



    def sendRequest(self):
        self.request_.a=10
        self.request_.b=20
        self.future_=self.client_.call_async(self.request_)
        

def main():
    rclpy.init()
    client=SimpleServiceClients()
    client.sendRequest()

    rclpy.spin_until_future_complete(client, client.future_)

    response=client.future_.result()

    
    client.get_logger().info('result: %d'%response.sum)

    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()