#!/usr/bin/env python
#license removed for brevity

import  rospy
from std_msgs.msg import Int16

def publicador_prom():
        pub = rospy.Publisher('chatter', Int16, queue_size=10)
        rospy.init_node('chatter',anonymous=True)
        valores = []
        contador = 0

        while not rospy.is_shutdown():
            while contador <= 10:
                num = input("Ingresa un #: ")
                valores.append(num)
                promedio = sum(valores)/float(len(valores))
                contador  = contador + 1

                if  contador == 10: 
                    mensaje = "Promedio final: %d" %promedio 
                    rospy.loginfo("%d",promedio)         
                    pub.publish(promedio) 
                    break
                else: 
                    try: 
                        mensaje = "Promedio actual: %d" %promedio 
                        rospy.loginfo("%d",promedio)         
                        pub.publish(promedio) 
                    except:
                        mensaje = "Aún no llega a los 10 valores"
                        rospy.loginfo(mensaje)         
                        pub.publish(mensaje)  
                   

def main():     
    try:
        publicador_prom()
    except rospy.ROSInterruptException:
        pass


if __name__ == '__main__':
    main()