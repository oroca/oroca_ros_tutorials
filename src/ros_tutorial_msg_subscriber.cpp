#include "ros/ros.h"
#include "ros_tutorial/msgTutorial.h"

void msgCallback(const ros_tutorial::msgTutorial::ConstPtr& msg)
{
  ROS_INFO("recieve msg: %d", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_tutorial_msg_subscriber");

  ros::NodeHandle nh;

  ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

  ros::spin();

  return 0;
}
