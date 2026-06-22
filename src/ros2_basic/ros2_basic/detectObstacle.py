#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
import numpy as np 
from enum import Enum

class MODE(Enum):
    FREE =0
    DANGER=1
    WARNING=2

class AEB(Node):
    def __init__(self):
        super().__init__('control_node')

        
        self.drive_publish = self.create_publisher(AckermannDriveStamped,"/drive",10)
        # self.subscriber_ = self.create_subscription(Odometry, '/odom',self.move,10)
        self.scan_subscriber1 = self.create_subscription(Odometry, 'ego_racecar/odom',self.odom_callback,10)
        self.scan_subscriber = self.create_subscription(LaserScan, '/scan',self.lidar_callback,10)

        self.get_logger().info('AEB_node has been started.')
        # self.create_timer(1.0,self.move_robot)
        # self.create_timer(1.0,self.moveForward)
        self.count=0
        self.distance=0
        self.speed=0
        self.ttc=0
        self.mode=MODE.FREE

        
    def odom_callback(self,msg):
        self.speed=msg.twist.twist.linear.x
        self.get_logger().info(f'SPEED          : {self.speed}')
        if self.count==0:
            self.x = msg.pose.pose.position.x 
            self.y = msg.pose.pose.position.y
            self.count=1        
        self.distance = ((msg.pose.pose.position.x - self.x)**2 + (msg.pose.pose.position.y - self.y)**2)**(1/2)
        
        self.get_logger().info(f'distance: {self.distance}')
          
        
    def lidar_callback(self, msg):
        # self.index1=len(msg.ranges)//2
        # self.lidar=msg.ranges[self.index1]
        # TTC=self.lidar/msg.twist.twist.linear.x
        self.get_logger().info(f'trogn day')
        self.ttc_list=[]
        if self.distance < 3:
            self.mode=MODE.FREE
            
            for i in range(len(msg.ranges)):
                # if not np.isfinite(msg.ranges[i]):
                angle_degree=np.degrees(msg.angle_min + i*msg.angle_increment) #day la goc tao boi truc x so voi voi tia thu i
                self.get_logger().info(f'trogn dayl3n eqwh')
                if -10 < angle_degree <10:                        
                    self.relative_speed=self.speed * np.cos(msg.angle_min + i*msg.angle_increment)
                    if self.relative_speed<=0:
                        continue
                    self.ttc= msg.ranges[i]/self.relative_speed
                    self.ttc_list.append(self.ttc)
                

            if not self.ttc_list:
                return       
            
            self.ttc_min=min(self.ttc_list)
            if self.ttc_min<=1.4:
                self.mode=MODE.DANGER
                
            elif 1.4 <self.ttc_min<=2.0:
                self.mode=MODE.WARNING
                
            else:
                self.mode=MODE.FREE

            
            
            
            if self.mode == MODE.DANGER:

                robot_msg = AckermannDriveStamped()
                robot_msg.drive.speed=0.0
                self.drive_publish.publish(robot_msg)
                self.get_logger().info('------------DANGER------------')
            elif self.mode == MODE.WARNING:
                robot_msg = AckermannDriveStamped()
                robot_msg.drive.speed=0.5
                self.drive_publish.publish(robot_msg)
                self.get_logger().info(f'-------------WARNING------------')
            else:
                robot_msg = AckermannDriveStamped()
                robot_msg.drive.speed=1.0
                self.drive_publish.publish(robot_msg)

                
                    
                    
            print(f' MODE: {self.mode}')
        else:
            robot_msg = AckermannDriveStamped()
            robot_msg.drive.speed=0.0
            self.drive_publish.publish(robot_msg)
            self.get_logger().info(f'-------------STOP------------')
            
    



def main(args=None):
    rclpy.init(args=args)

    node = AEB()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()





















