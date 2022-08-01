#include <Servo.h>

Servo servo1;

int servoPin = 9;
int ServoPosition = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
}

void loop() {

if (Serial.available() > 0){
  String incomingString = Serial.readString();
  Serial.print("received");
  Serial.println(incomingString);
  if (incomingString.startsWith("يمين")){
    Serial.println("Right");
    for (ServoPosition = 0; ServoPosition <= 180; ServoPosition++)
    {
      servo1.write(ServoPosition);
      delay(100);
    }
  }
   else if (incomingString.startsWith("يسار"))
    {
      Serial.println("Turning Left");
      for (ServoPosition = 180; ServoPosition >= 0; ServoPosition--)
      {
        servo1.write(ServoPosition);
        delay(20);
      }
    }
}
}
