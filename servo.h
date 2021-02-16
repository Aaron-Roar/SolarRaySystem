#define UPDATETIME 20
#include <Wire.h>

int angle_pwm(int value, int convert) {
    if(convert == 1)
    return value * (((float) 255) / ((float) 180));
    else if(convert == 0) 
        return value * (((float) 180) / ((float) 255));

}

void use_servo(int pin, int angle, int time) {
    analogWrite(pin, angle_pwm(angle, 1));
    delay(time);
}
