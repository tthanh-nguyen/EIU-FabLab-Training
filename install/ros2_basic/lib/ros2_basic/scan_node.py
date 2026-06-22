#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan

class LidarControl(Node):
    def __init__(self):
        super().__init__('control_node')

        
        self.drive_publish = self.create_publisher(AckermannDriveStamped,"/drive",10)
        self.subscriber_ = self.create_subscription(Odometry, '/odom',self.moveForward,10)
        self.scan_subscriber = self.create_subscription(LaserScan, '/scan',self.lidar_callback,10)

        self.get_logger().info('subscriber_node has been started.')
        # self.create_timer(1.0,self.move_robot)
        # self.create_timer(1.0,self.moveForward)
        self.count=0
        self.distance=0
        
    
    def moveForward(self, msg):
        # self.get_logger().info(f'Received: "{msg.pose.pose.position}"')
        

        if self.count==0:
            self.x = msg.pose.pose.position.x 
            self.y = msg.pose.pose.position.y
            self.count=1
        
        self.distance = ((msg.pose.pose.position.x - self.x)**2 + (msg.pose.pose.position.y - self.y))**(1/2)



    def lidar_callback(self,msg):
        
        self.lidar=[]
        # for i in range(1,10):
        #     self.index=(len(msg.ranges)//10)*i
        #     self.lidar=msg.ranges[self.index]
        self.index1=len(msg.ranges)//2
        self.index2=len(msg.ranges)//2
        for i in range(0,20):
            self.index1-=1
            self.lidar.append(msg.ranges[self.index1])
            
        
        for i in range(0,20):
            self.index2+=1
            self.lidar.append(msg.ranges[self.index2])
        
        
      
        robot_msg = AckermannDriveStamped()
       

        

    

   
        
    

def main(args=None):
    rclpy.init(args=args)

    node = LidarControl()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()





















