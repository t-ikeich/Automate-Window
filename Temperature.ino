#include <Servo.h>
#include "DHT.h"

Servo myservo; 

#define DHTTYPE DHT11
#define DHTPIN A1 
#define DHTPIN2 A5 
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);



void setup() {  
   
  Serial.begin(9600); 
  myservo.attach(9);
  myservo.write(0);
  dht.begin();
  dht2.begin();

  }  
  void loop() {   
    Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
    Serial.println("Temperature2 = " + String(dht2.readTemperature())+" °C");

     if ( dht.readTemperature()<dht2.readTemperature())   { 
      myservo.write(150);    
      delay(1000);
   
      }  
      else   {       
        myservo.write(0);
        }    
 delay(1000);
}
