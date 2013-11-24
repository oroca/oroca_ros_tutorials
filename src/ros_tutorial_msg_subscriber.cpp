#include "ros/ros.h"                                    // ROS 기본 헤더파일 
#include "oroca_ros_tutorials/msgTutorial.h"            // msgTutorial 메시지 파일 헤더 (빌드후 자동 생성됨)

// 메시지 콜백함수로써, 밑에서 설정한 ros_tutorial_sub 구독자에 해당되는 메시지를
// 수신하였을때 동작하는 함수이다
// 입력 메시지로는 oroca_ros_tutorial 패키지의 msgTutorial 메시지를 받도록 되어있다 
void msgCallback(const oroca_ros_tutorials::msgTutorial::ConstPtr& msg)
{
  ROS_INFO("recieve msg: %d", msg->data);   // 수신된 메시지를 표시하는 함수
}

int main(int argc, char **argv)                         // 노드 메인 함수
{
  ros::init(argc, argv, "ros_tutorial_msg_subscriber"); // 노드명 초기화

  ros::NodeHandle nh;                                   // ROS 시스템과 통신을 위한 노드 핸들 선언

  // 구독자 선언, oroca_ros_tutorials 패키지의 msgTutorial 메시지 파일을 이용한
  // 구독자 ros_tutorial_sub 를 작성한다. 토픽명은 "ros_tutorial_msg" 이며,
  // 구독자 큐(queue) 사이즈를 100개로 설정한다는 것이다
  ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

  // 콜백함수 호출을 위한 함수로써, 메시지가 수신되기를 대기, 수신되었을 경우 콜백함수를 실행한다
  ros::spin();

  return 0;
}
