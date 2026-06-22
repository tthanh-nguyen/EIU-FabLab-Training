#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from f1tenth_msgs.srv import Aeb

class SimpleServiceClients(Node):
    def __init__(self):
        super().__init__("service_client_detect")
        self.client_ = self.create_client(Aeb, "aeb")

        while not self.client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Wait for service...')
        self.request_= Aeb.Request()



    def sendRequest(self):
        self.request_.desired_distance=10.0
        self.request_.ttc=1.4
        self.future_=self.client_.call_async(self.request_)
        

def main():
    rclpy.init()
    client=SimpleServiceClients()
    client.sendRequest()

    rclpy.spin_until_future_complete(client, client.future_)

    response=client.future_.result()

    
    client.get_logger().info('result: %s'%response.result)

    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()