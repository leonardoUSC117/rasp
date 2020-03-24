#!/usr/bin/env python
#license removed for brevity

import  rospy
from std_msgs.msg import Int16

def callback(msg):
    rospy.loginfo("mensaje recibido:%d",msg.data)


def memory_subscriber():
    rospy.init_node('sucriptor_basico_alberto',anonymous=True)
    rospy.Subscriber('chatter',Int16,callback)
    rospy.spin()

def main():
    try:
        memory_subscriber()
    except rospy.ROSInterruptException:
        pass

if __name__== "__main__":
	main()
