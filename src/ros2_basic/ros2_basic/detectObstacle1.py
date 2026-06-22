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

class MODE(Enum):
    FREE = 0
    WARNING = 1
    DANGER = 2
    
class AEB(Node):
    
    def __init__(self):
        super().__init__('AEB')
        self.publisher_ = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.sub1= self.create_subscription(Odometry, 'ego_racecar/odom',self.odom_callback, 10)
        self.sub2= self.create_subscription(LaserScan, '/scan',self.scan_callback,10)
        self.speed = 0.0
        self.t = None
        self.mode = MODE.FREE
        time.sleep(1)
        self.distance=0
        self.count=0
        
        
        
        
    def odom_callback(self, msg:Odometry):
        
        self.speed=msg.twist.twist.linear.x

        
        if self.count==0:
            self.x = msg.pose.pose.position.x 
            self.y = msg.pose.pose.position.y
            self.count=1   
               
        self.distance = ((msg.pose.pose.position.x - self.x)**2 + (msg.pose.pose.position.y - self.y)**2)**(1/2)
        
        
        
    def scan_callback(self, msg:LaserScan):
        self.mode =MODE.FREE
        
        for i in range (len(msg.ranges)):
            angle_deg = np.degrees(msg.angle_min + i * msg.angle_increment)
            if -10 < angle_deg < 10:
                self.t = msg.ranges[i] / max(self.speed * np.cos(angle_deg), 0.8)
                if self.t< 1.4:
                    self.mode = MODE.DANGER
                    break
                elif 1.4<self.t<2.0:
                    self.mode = MODE.WARNING
                    break
                else: 
                    break

            
                  
        if (self.mode == MODE.DANGER):
            print("Stop")
            stop = AckermannDriveStamped()
            stop.drive.speed=0.0
            self.publisher_.publish(stop)
            
        elif (self.mode == MODE.WARNING):
            print("Slow")
            stop = AckermannDriveStamped()
            stop.drive.speed=0.5
            self.publisher_.publish(stop)
        else:
            if self.distance <= 2.0:
                stop = AckermannDriveStamped()
                print("dang chay 1.0")
                print(f"distance: {self.distance}")
                stop.drive.speed=1.0
                self.publisher_.publish(stop)
            
            else:
                stop = AckermannDriveStamped()
                
                stop.drive.speed=0.0
                self.publisher_.publish(stop)


    
    
    
        
       


def main(args=None):
    rclpy.init(args=args)
    brake = AEB()
    rclpy.spin(brake)
    brake.destroy_node()
    rclpy.shutdown()

 
if __name__ == '__main__':
    main()

             
