#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from f1tenth_msgs.srv import Aeb

from enum import Enum
import numpy as np
# TODO: include needed ROS msg type headers and libraries
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped, AckermannDrive
import time
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

class MODE(Enum):
    FREE = 0
    WARNING = 1
    DANGER = 2

class SimpleServiceServer(Node):
    def __init__(self):
        super().__init__("AEB")
        self.group = ReentrantCallbackGroup()
        self.service_ = self.create_service(Aeb, "aeb",self.serviceCallback)
        self.get_logger().info('Service AEB Ready')
        self.publisher_ = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.sub1= self.create_subscription(Odometry, '/odom',self.odom_callback, 10, callback_group=self.group)
        self.sub2= self.create_subscription(LaserScan, '/scan',self.scan_callback,10, callback_group=self.group)
        self.speed = 0.0
        self.t = None
        self.mode = MODE.FREE
        self.distance=0
        self.count=0
        self.ttc=0
        self.desired_distance=0

    def serviceCallback(self, req, res):                
        self.get_logger().info('New Request Received desired distance: %f, ttc: %f' % (req.desired_distance,req.ttc))

        self.desired_distance=req.desired_distance
        self.ttc=req.ttc

        stop = AckermannDriveStamped()
        stop.drive.speed=1.0
        self.publisher_.publish(stop)
                
        self.speed=self.odom_msgs.twist.twist.linear.x

        while (1):
            self.speed=self.odom_msgs.twist.twist.linear.x
            if self.count==0:
                self.x = self.odom_msgs.pose.pose.position.x 
                self.y = self.odom_msgs.pose.pose.position.y
                print("no da nhay vo day")
                self.count=1   
            self.distance = ((self.odom_msgs.pose.pose.position.x - self.x)**2 + (self.odom_msgs.pose.pose.position.y - self.y)**2)**(1/2)
            # print("distance: ",self.distance)
            self.mode =MODE.FREE
            for i in range (len(self.laserScan_msg.ranges)):
                angle_deg = np.degrees(self.laserScan_msg.angle_min + i * self.laserScan_msg.angle_increment)
                if -10< angle_deg < 10:
                    self.t = self.laserScan_msg.ranges[i] / max(self.speed * np.cos(angle_deg), 0.8)
                    print(f'lidar: {self.laserScan_msg.ranges[i]}')
                    if self.t< self.ttc:
                        self.mode = MODE.DANGER
                        break
                    elif self.ttc<self.t<2.0:
                        self.mode = MODE.WARNING
                        break
                    else: 
                        break      

            if (self.mode == MODE.DANGER):
                print("Stop")
                stop = AckermannDriveStamped()
                stop.drive.speed=0.0
                self.publisher_.publish(stop)
                self.count=0
                res.result='FAIL'
                break    
            elif (self.mode == MODE.WARNING):
                print("Slow")
                stop = AckermannDriveStamped()
                stop.drive.speed=0.5
                self.publisher_.publish(stop)
            else:
                if self.distance <= self.desired_distance:
                    stop = AckermannDriveStamped()
                    stop.drive.speed=1.0
                    print(f'distance: {self.distance}')
                    self.publisher_.publish(stop)
                else:
                    stop = AckermannDriveStamped()
                    stop.drive.speed=0.0
                    self.count=0
                    self.publisher_.publish(stop)
                    res.result='SUCCESS'
                    break
        self.get_logger().info('Returning sum: %s' % res.result)
        return res
        

    def odom_callback(self, msg:Odometry):
        
        self.odom_msgs= msg

        
        # self.speed=msg.twist.twist.linear.x
        # print("speed: ", self.speed)

        
        # if self.count==0:
        #     self.x = msg.pose.pose.position.x 
        #     self.y = msg.pose.pose.position.y
        #     self.count=1   
               
        # self.distance = ((msg.pose.pose.position.x - self.x)**2 + (msg.pose.pose.position.y - self.y)**2)**(1/2)
        
        
        
    def scan_callback(self, msg:LaserScan):

        self.laserScan_msg = msg 
        # print(f"tia giua: {self.laserScan_msg.ranges[512]}")
        


        # self.mode =MODE.FREE
        
        # for i in range (len(msg.ranges)):
        #     angle_deg = np.degrees(msg.angle_min + i * msg.angle_increment)
        #     if -10 < angle_deg < 10:
        #         self.t = msg.ranges[i] / max(self.speed * np.cos(angle_deg), 0.8)
        #         if self.t< self.ttc:
        #             self.mode = MODE.DANGER
        #             break
        #         elif self.ttc<self.t<2.0:
        #             self.mode = MODE.WARNING
        #             break
        #         else: 
        #             break

            
                  
        # if (self.mode == MODE.DANGER):
        #     print("Stop")
        #     stop = AckermannDriveStamped()
        #     stop.drive.speed=0.0
        #     self.publisher_.publish(stop)
            
        # elif (self.mode == MODE.WARNING):
        #     print("Slow")
        #     stop = AckermannDriveStamped()
        #     stop.drive.speed=0.5
        #     self.publisher_.publish(stop)
        # else:
        #     if self.distance <= self.desired_distance:
        #         stop = AckermannDriveStamped()
        #         stop.drive.speed=1.0
        #         print(f'distance: {self.distance}')
        #         self.publisher_.publish(stop)
            
        #     else:
        #         stop = AckermannDriveStamped()
                
        #         stop.drive.speed=0.0
        #         self.flag=1
        #         print("dang cho nayyyyyyyy")
        #         self.publisher_.publish(stop)

    

def main():
    rclpy.init()

    simple_service_server = SimpleServiceServer()
    # rclpy.spin(simple_service_server)
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(simple_service_server)
    executor.spin()

    simple_service_server.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()  