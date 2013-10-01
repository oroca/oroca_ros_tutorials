#include "ros/ros.h"
#include "ros_tutorial/srvTutorial.h"

bool add(ros_tutorial::srvTutorial::Request  &req,
         ros_tutorial::srvTutorial::Response &res)
{
  res.sum = req.a + req.b;

  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_tutorial_srv_server");
  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("ros_tutorial_srv", add);
  ROS_INFO("ready srv server!");
  ros::spin();

  return 0;
}
