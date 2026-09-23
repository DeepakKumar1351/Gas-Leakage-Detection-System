#include <Servo.h>

const int mq2Pin = A0;       // MQ-2 sensor analog output
const int buzzerPin = 8;     // Buzzer control
const int fanPin = 10;       // Fan control through MOSFET
const int servoPin = 9;      // Servo signal

Servo myServo;

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);  // Initial servo position, as in the project sketch
}

void loop() {
  int mq2Value = analogRead(mq2Pin);
  Serial.println(mq2Value);  // Display sensor value for monitoring

  if (mq2Value > 400) {      // Threshold used in the supplied project code
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(fanPin, HIGH);
    myServo.write(180);      // Confirm this position closes the regulator linkage
    delay(2000);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(fanPin, LOW);
    myServo.write(0);        // Confirm the intended normal position
  }

  delay(500);
}
