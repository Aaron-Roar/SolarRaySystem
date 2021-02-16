#include <SoftwareSerial.h>
#include <Wire.h>
#include "servo.h"

int setLED(int pin, int state) {
if(state == 0) {
    digitalWrite(pin, LOW);
    return 0;
}
else if(state == 1) {
    digitalWrite(pin, HIGH);
    return 1;
}
else
return -1;
}

int get_brightness(int pin) {
return analogRead(pin);
}

void setup() {
pinMode(9, OUTPUT);
Serial.begin(9600);
}

int servoPin = 9;
int moveAngle;
int currentAngle;

void loop() {

Serial.println(get_brightness(A0));
Serial.println(get_brightness(A1));


//if(( (get_brightness(A0) - get_brightness(A1)) < 10) || ( (get_brightness(A1) - get_brightness(A0)) < 10)) {
//}

if(get_brightness(A0) < get_brightness(A1)) {
if(currentAngle < 180) {
currentAngle += 1;
use_servo(servoPin, currentAngle, 20);
}
}

else if(get_brightness(A0) > get_brightness(A1)) {
if(currentAngle > 0) {
currentAngle -= 1;
use_servo(servoPin, currentAngle, 20);
}
}

}
