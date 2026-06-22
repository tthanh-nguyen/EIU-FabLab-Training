#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from enum import Enum
import numpy as np
# TODO: include needed ROS msg type headers and libraries
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive
import time


    
class PID(Node):
    
    def __init__(self):
        super().__init__('AEB')
        self.publisher_ = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        # self.sub1= self.create_subscription(Odometry, 'ego_racecar/odom',self.odom_callback, 10)
        self.sub2= self.create_subscription(LaserScan, '/scan',self.scan_callback,10)
        self.theta=70

    def scan_callback(self,msg:LaserScan):
        idx_0=int((-np.pi/2-0-msg.angle_min)/msg.angle_increment)
        idx_theta=int((np.pi*(-1/2+self.theta/180)-msg.angle_min)/msg.angle_increment)

        #xu li de khong bi over ranges 
        self.index_0 = max(0,min(idx_0, len(msg.ranges)-1))
        self.index_theta=max(0,min(idx_theta, len(msg.ranges)-1))

        # print(f"tia o tiado: {self.index_0}")
        # print(f"tia o 70 do: {self.index_theta}")

        print(f"tia o 0 do: {msg.ranges[self.index_0]}")
        print(f"tia o 70 do: {msg.ranges[self.index_theta]}")


        
        
    
    
        
       


def main(args=None):
    rclpy.init(args=args)
    brake = PID()
    rclpy.spin(brake)
    brake.destroy_node()
    rclpy.shutdown()

 
if __name__ == '__main__':
    main()

             
