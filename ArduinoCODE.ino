//By Anando Zaman
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); 
char button;
//motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293

//Motor B
const int motorPin3  = 3; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

void setup(){
 BT.begin(9600);
 Serial.begin(9600);
   pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

}

void backwards(){
  digitalWrite(motorPin1, HIGH); //spin motor A CCW
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH); //spin motor B CCW
  }

  void forwards(){
  digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH); //spin motor A CW
    digitalWrite(motorPin3, HIGH);//spin motor B CW
    digitalWrite(motorPin4, LOW);
  }

  void right(){
  digitalWrite(motorPin1, HIGH); //spin motor A CCW
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }

  void left(){
  digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4,HIGH); //spin motor B CCW
  }

  void stops(){ //none of the wheels move
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4,LOW);
    }
void loop(){
   
  button =BT.read();
 if(button=='F') //if up button pressed, run forwards function
  {
    forwards();
  }
  else if(button=='B') //if down button pressed, run backwards function
  {
    backwards();
  
  }
  else if(button=='L') //if left button pressed, run left function
  {
    left();
   
  }
  else if(button=='R') //if right button pressed, run right function
  {
    right();
   
  }
  else if(button=='X') //if nothing pressed, run stops function
  {
     stops();     
  }
}

