/*-----( Import needed libraries )-----*/
#include "Ultrasonic.h"
#include <Servo.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define  TRIG_PIN  12
#define  ECHO_PIN  13
#define  LED_PIN   16

Servo myServo;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  Serial.println("UltraSonic Distance Measurement");
  Serial.println("YourDuino.com  terry@yourduino.com");
    
  //pinMode(17, OUTPUT);
  //digitalWrite(17, HIGH);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  myServo.attach(22);
  //myServo.writeMicroseconds(2000);
  //delay(15);

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{  
  Ultrasonic module(TRIG_PIN, ECHO_PIN);
    
  digitalWrite(LED_PIN, LOW);
  while((module.Ranging(CM) < 15))
  {
    //double check helps eliminate noise - this is a workaround
    if(module.Ranging(CM) < 15)
    {
      digitalWrite(16, HIGH);
      myServo.write(150);
      delay(15);
    }
  }
  
  //reset LED
  digitalWrite(LED_PIN, LOW); 
  myServo.write(94);
  delay(15);
  
  Serial.print(module.Ranging(CM));
  Serial.println(" cm");
  delay(300);

}//--(end main loop )---

