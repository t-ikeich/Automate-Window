#include <Servo.h>


Servo myservo; 
int pos = 0; 
int redLed = 4;
int buzzer = 10;
int smokeA0 = A0; 
int sensorThres = 200; 



void setup() {  
  pinMode(redLed, OUTPUT);   
  pinMode(buzzer, OUTPUT);  
  pinMode(smokeA0, INPUT); 
  Serial.begin(9600); 
  myservo.attach(9);
  myservo.write(0);


  }  
  void loop() {   


    int analogSensor = analogRead(smokeA0);   

    if (analogSensor > sensorThres )   { //la valeur qui retourne le capteur de gaz
      digitalWrite(redLed, HIGH);     
      tone(buzzer, 1000, 2000);   
      myservo.write(150);
      delay(10000);
      myservo.write(0);
   
      }  
      else   {     
        digitalWrite(redLed, LOW);    
        noTone(buzzer); 
        }  
digitalWrite(redLed,LOW);
 delay(10000);
}
