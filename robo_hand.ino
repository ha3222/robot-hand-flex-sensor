#include <Servo.h>

Servo thumbServo, indexServo, middleServo, ringServo, pinkyServo;

const int thumbSensor = A0;
const int indexSensor = A1;
const int middleSensor = A2;
const int ringSensor = A3;
const int pinkySensor = A4;

const int thumbPin = 9;
const int indexPin = 10;
const int middlePin = 11;
const int ringPin = 6;
const int pinkyPin = 5;

int lastThumbAngle = 90, lastIndexAngle = 90, lastMiddleAngle = 90, lastRingAngle = 90, lastPinkyAngle = 90;

void setup() {
  thumbServo.attach(thumbPin);
  indexServo.attach(indexPin);
  middleServo.attach(middlePin);
  ringServo.attach(ringPin);
  pinkyServo.attach(pinkyPin);

  Serial.begin(9600);
}

void loop() {
  int thumbValue = analogRead(thumbSensor);
  int indexValue = analogRead(indexSensor);
  int middleValue = analogRead(middleSensor);
  int ringValue = analogRead(ringSensor);
  int pinkyValue = analogRead(pinkySensor);

  Serial.print("Thumb: "); Serial.print(thumbValue);
  Serial.print(" | Index: "); Serial.print(indexValue);
  Serial.print(" | Middle: "); Serial.print(middleValue);
  Serial.print(" | Ring: "); Serial.print(ringValue);
  Serial.print(" | Pinky: "); Serial.println(pinkyValue);

  // تعديل الـ map حسب القراءات اللي شوفتها
  int thumbAngle  = map(thumbValue, 800, 950, 0, 180);
  int indexAngle  = map(indexValue, 850, 1000, 0, 180);
  int middleAngle = map(middleValue, 800, 950, 0, 180);
  int ringAngle   = map(ringValue, 700, 900, 0, 180);
  int pinkyAngle  = map(pinkyValue, 700, 900, 0, 180);

  thumbAngle = constrain(thumbAngle, 0, 180);
  indexAngle = constrain(indexAngle, 0, 180);
  middleAngle = constrain(middleAngle, 0, 180);
  ringAngle = constrain(ringAngle, 0, 180);
  pinkyAngle = constrain(pinkyAngle, 0, 180);

  if (abs(thumbAngle - lastThumbAngle) > 1) {
    lastThumbAngle = thumbAngle;
    thumbServo.write(thumbAngle);
  }

  if (abs(indexAngle - lastIndexAngle) > 1) {
    lastIndexAngle = indexAngle;
    indexServo.write(indexAngle);
  }

  if (abs(middleAngle - lastMiddleAngle) > 1) {
    lastMiddleAngle = middleAngle;
    middleServo.write(middleAngle);
  }

  if (abs(ringAngle - lastRingAngle) > 1) {
    lastRingAngle = ringAngle;
    ringServo.write(ringAngle);
  }

  if (abs(pinkyAngle - lastPinkyAngle) > 1) {
    lastPinkyAngle = pinkyAngle;
    pinkyServo.write(pinkyAngle);
  }

  delay(20);  // لتخفيف التقطيع
}
