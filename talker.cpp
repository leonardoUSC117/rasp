#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int cuenta  = 0;


int main (int argc, char **argv)
{
	ros::init(argc, argv, "talker");

		ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    cuenta = 0;

    while (ros::ok())
    {
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Publiqué(C++): " << cuenta;
        msg.data = ss.str();

        std::cout << msg.data.c_str() << std::endl;

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();

        cuenta ++;
    }
    return 0;
}
