#include <Ultrasonic.h> 

int LEDpin = 12; 
int potPin = A0;
int potValue = 0; 
int motorPin = 6; 
int motorValue = 0; 
Ultrasonic ultrasonic(1,2); //Trig = 1 Echo = 2 ?

void setup() {
Serial.begin(9600); //57600
pinMode(LEDpin, OUTPUT);
pinMode (potPin, INPUT); 
pinMode(motorPin, OUTPUT);

}
void loop() {
   
  if (ultrasonic.distanceRead() > 10) 
  {
  potValue = analogRead(potPin); //Get Value From poteniometer
  digitalWrite(LEDpin, HIGH); //Turn on LED
  motorValue = map(potValue, 0, 1023, 0, 255); // Map the poteniometer values to only range from 0-255
  analogWrite(motorPin, motorValue); //Use a digital pin with pwm(pulse width modulation) to control the motor
  //For Debugging    
  Serial.println(motorValue);
  //Serial.println("Sucky");
  } 
  else 
  {
  digitalWrite(LEDpin, LOW);
  //For Debugging   
  //Serial.println("Oh nooooooo");
  }       
}
/*
Using the (Specific) H bridge
Connect the voltage to the 5v ardunio circuit 
Connect the ground to the common ground 
Connect the motorpin to an input, connect corresponding output to motor
Connnect other motor led to the ground 
 */
