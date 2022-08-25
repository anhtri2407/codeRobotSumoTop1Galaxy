#include<Arduino.h>
#include <SoftwareSerial.h>
#define enA 10
#define enB 5
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6

short M1_Speed = 120; // speed of motor 1 
short M2_Speed = 120; // speed of motor 2
short LeftRotationSpeed = 250;  // Left Rotation Speed
short RightRotationSpeed = 250; // Right Rotation Speed

SoftwareSerial BTSerial(2, 3); // RX | TX  --->TX  | RX (HC-05)

char docgiatri;

void setup()
{
  Serial.begin(9600);
  Serial.print("ready");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

}


void forward()
{
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
             
                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}
  
void backward()
{
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
             
                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}
  
void right()
{
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
             
                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}
  
void left()
{
            

            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
             
                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}
  
void Stop()
{
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available() > 0){
    docgiatri = BTSerial.read();
    Serial.println(docgiatri);
  }

  switch (docgiatri) {
    case 'F': 
      forward();
      Serial.println("Forward");
      break;
    case 'B':
      backward();
      Serial.println("Backward");
      break;
    case 'L':
      Serial.println("left");
      left();
      break;
    case 'R':
      right();
      Serial.println("right");
      break;
     case 'S':
      Stop();
      break;
  }
    

}
