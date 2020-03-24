#!/usr/bin/env python
#license removed for brevity

import  rospy
from std_msgs.msg import Int16

def talker():
        pub = rospy.Publisher('chatter', Int16, queue_size=10)
        rospy.init_node('chatter',anonymous=True)
        rate = rospy.Rate(10)
        counter=0

        while not rospy.is_shutdown():
                entero=int(input("Ingresa un #: "))
                
                rospy.loginfo("%d ",entero)
                pub.publish(entero)
                rate.sleep()

def main():     
    try:
        talker()
    except rospy.ROSInterruptException:
        pass


if __name__ == '__main__':
    main()