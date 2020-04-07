#include <Servo.h>

Servo myservo;

const int sensorPin = 0;
const int servoPin = 3;

int lightCal;
int lightVal;
int jump;
int zero;



void setup()
{
  pinMode(sensorPin, OUTPUT);
  lightCal = analogRead(sensorPin);
  myservo.attach(servoPin);
}


void loop()
{
  
  lightVal = analogRead(sensorPin);
  jump = analogRead(sensorPin);
  jump = map(jump,0,1023,0,90);
  zero = map(jump,1023,0,90,0);
  
  if (lightVal > lightCal + 80)//50
  {
    digitalWrite(9, HIGH);
    myservo.write(jump);
  }

  else
  {
    digitalWrite(9, LOW);
    myservo.write(zero);
  }

}
