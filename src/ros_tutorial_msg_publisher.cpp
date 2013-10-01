#include "ros/ros.h"
#include "ros_tutorial/msgTutorial.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_tutorial_msg_publisher");

  ros::NodeHandle nh;

  ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorial::msgTutorial>("ros_tutorial_msg", 100);

  ros::Rate loop_rate(10);

  int count = 0;

  while (ros::ok())
  {
    ros_tutorial::msgTutorial msg;

    msg.data = count;

    ROS_INFO("send msg = %d", count);

    ros_tutorial_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
