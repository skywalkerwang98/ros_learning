#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv){
    //节点初始化
    ros::init(argc, argv, "velocity_publisher");

    //创建节点
    ros::NodeHandle n;

    //创建publisher，发布/trutle1/cmd_vel的topic，消息类型为geometry_msgs, 队列长度为10
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    //设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()){
        //初始化topic的数据
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;
        //发布消息
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        //按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}