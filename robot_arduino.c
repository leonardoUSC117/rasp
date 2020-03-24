/*# Código para el contorl de un carrito con dos puentes H
 *  Alimentación = 12.47 V DC
 *  Microcontrolador = Arduino Mega
 *  CPU = Raspberry Pi 4 B+
 *  Motoreductores DC 
 *#
 */

#define TRIGGER 52  
#define ECHO 50

#define ENAd 13   // Pin Enable A Puente H delantero
#define IN1d 12   // Pin IN 1 Puente H delantero
#define IN2d 11   // Pin IN 2 Puente H delantero
#define IN3d 10   // Pin IN 3 Puente H delantero
#define IN4d 9    // Pin IN 4 Puente H delantero
#define ENBd 8    // Pin Enable B Puente H delantero

#define ENAt 7    // Pin Enable A Puente H trasero
#define IN1t 6    // Pin IN 1 Puente H trasero
#define IN2t 5    // Pin IN 2 Puente H trasero
#define IN3t 4    // Pin IN 3 Puente H trasero
#define IN4t 3    // Pin IN 4 Puente H trasero
#define ENBt 2    // Pin Enable B Puente H trasero


// Configuramos variables para el sensor Ultrasónico 
const float sonido = 34300.0; // Velocidad del sonido en cm/s
const float umbral1 = 30.0;   // 30 cm; 
const float umbral2 = 20.0;   // 20 cm 
const float umbral3 = 10.0;   // 5 cm 

// Configuramos la velocidad de los motores
const int vel = 100;
int velocidad = 0; 

void setup() 
{
 Serial.begin(9600);        //Comenzamos una comunicación de 9600 baudiso en puerto Serial 

/*  Configuramos nuestro Senso Ultrásonico*/ 
 pinMode(ECHO, INPUT);
 pinMode(TRIGGER, OUTPUT);
 digitalWrite(TRIGGER,LOW);
 
 /*  Configuramos nuestros Puentes H */
 // Puente H delantero
 pinMode (ENAd,OUTPUT);
 pinMode (IN1d,OUTPUT);
 pinMode (IN2d,OUTPUT);
 pinMode (ENBd,OUTPUT);
 pinMode (IN3d,OUTPUT);
 pinMode (IN4d,OUTPUT);
 // Puente H trasero
 pinMode (ENAt,OUTPUT);
 pinMode (IN1t,OUTPUT);
 pinMode (IN2t,OUTPUT);
 pinMode (ENBt,OUTPUT);
 pinMode (IN3t,OUTPUT);
 pinMode (IN4t,OUTPUT);
}

/*funcion main principal()     if __name__=='main':       void main();*/
void loop()
{
  while( Serial.available ())
  {
    velocidad = Serial.read();                  // Leemos la distancia a la que queramos que nuestro carrito vaya en general

    Serial.print("Velocidad de motores=  ");    // Imprimios un mensaje en el puerto serie
    Serial.println(velocidad);                  // Imprimimos la velocidad que seleccionamos
    
    float distancia = 0; 
    
    iniciar_sensor();                           //Mandamos los pulsos necesarios para prender el sensor
    distancia = calcularDistancia();            // Llamamos la función calcular distancia y la guardamos en la variable distancia. 
    
    if (distancia < umbral1) 
    {
      adelante();
    }
    else if (distancia < umbral1 && distancia >= umbral2)
    {
      reversa();
    }
    else if (distancia < 5 && distancia >1)
    {
      freno();
    } 
  }
}

void iniciar_sensor()
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
}

float calcularDistancia()
{
  unsigned long tiempo;
  tiempo = pulseIn(ECHO, HIGH);
  float distancia;
  distancia = tiempo / 59;              // distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();                     // Imprimimos en puerto Serial
  delay(80);                            // esperamos 80 ms para volver a repetir el ciclo.  
  
  return distancia;
}

void adelante()                   // FUnción para ir de frente
{
 //Puente H Delantero
 digitalWrite (IN1d, HIGH);
 digitalWrite (IN2d,LOW);
 analogWrite (ENAd,velocidad);
 digitalWrite (IN3d, HIGH);
 digitalWrite (IN4d,LOW);
 analogWrite (ENBd,velocidad);

 // Puente H Trasero
 digitalWrite (IN1t, HIGH);
 digitalWrite (IN2t,LOW);
 analogWrite (ENAt,velocidad);
 digitalWrite (IN3t, HIGH);
 digitalWrite (IN4t,LOW);
 analogWrite (ENBt,velocidad);
} 

void reversa()              // Funcion para ir en reversa
{
 //Puente H Delantero
 digitalWrite (IN1d, HIGH);
 digitalWrite (IN2d,LOW);
 analogWrite (ENAd,velocidad);
 digitalWrite (IN3d, HIGH);
 digitalWrite (IN4d,LOW);
 analogWrite (ENBd,velocidad);

 // Puente H Trasero
 digitalWrite (IN1t, HIGH);
 digitalWrite (IN2t,LOW);
 analogWrite (ENAt,velocidad);
 digitalWrite (IN3t, HIGH);
 digitalWrite (IN4t,LOW);
 analogWrite (ENBt,velocidad);
} 

void derecha()                // Función para girar a la derecha
{
 //Puente H Delantero
 digitalWrite (IN1d, HIGH);
 digitalWrite (IN2d,LOW);
 analogWrite (ENAd,velocidad);
 digitalWrite (IN3d, HIGH);
 digitalWrite (IN4d,LOW);
 analogWrite (ENBd,velocidad);

 // Puente H Trasero
 digitalWrite (IN1t, HIGH);
 digitalWrite (IN2t,LOW);
 analogWrite (ENAt,velocidad);
 digitalWrite (IN3t, HIGH);
 digitalWrite (IN4t,LOW);
 analogWrite (ENBt,velocidad);
} 

void izquierda()                //FUnción para girar a las izquierda
{
 //Puente H Delantero
 digitalWrite (IN1d, HIGH);
 digitalWrite (IN2d,LOW);
 analogWrite (ENAd,velocidad);
 digitalWrite (IN3d, HIGH);
 digitalWrite (IN4d,LOW);
 analogWrite (ENBd,velocidad);

 // Puente H Trasero
 digitalWrite (IN1t, HIGH);
 digitalWrite (IN2t,LOW);
 analogWrite (ENAt,velocidad);
 digitalWrite (IN3t, HIGH);
 digitalWrite (IN4t,LOW);
 analogWrite (ENBt,velocidad);
} 

void freno()                // Función para poder parar todos los motores
{
 //Puente H Delantero
 digitalWrite (IN1d, LOW);
 digitalWrite (IN2d,LOW);
 analogWrite (ENAd,velocidad);
 digitalWrite (IN3d, LOW);
 digitalWrite (IN4d,LOW);
 analogWrite (ENBd,velocidad);

 // Puente H Trasero
 digitalWrite (IN1t, LOW);
 digitalWrite (IN2t,LOW);
 analogWrite (ENAt,velocidad);
 digitalWrite (IN3t, LOW);
 digitalWrite (IN4t,LOW);
 analogWrite (ENBt,velocidad);
} 