#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

ros::Publisher pub;

void chatterCallback(const sensor_msgs::LaserScan::ConstPtr& msg){

	//printf("%f", msg -> angle_min);
	geometry_msgs::Twist speed;
	speed.linear.x = 5;
	speed.angular.x = .2
	pub.publish(speed);
}

int main(int argc, char** argv){

ros::init(argc, argv, "publisher");
ros::NodeHandle n;
pub = n.advertise<geometry_msgs::Twist>("/robot/cmd_vel",5);
ros::Subscriber sub = n.subscribe("/robot/base_scan", 1000, chatterCallback);
ros::spin(); 

//while(ros::ok()){

//}

return 0;
}






