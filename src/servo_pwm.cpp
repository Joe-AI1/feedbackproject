#include "servo_pwm.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// MPU6050 object
Adafruit_MPU6050 mpu;

void setupServo(int pin) {
    pinMode(pin, OUTPUT);
    Wire.begin();

    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) { delay(10); }
    }
    Serial.println("MPU6050 Found!");
}

void moveServo(int angle) {
    int pwm_value = map(angle, -90, 90, 544, 2400);  // Map angle to PWM range
    ledcWrite(0, pwm_value);  // Write PWM value to the servo
}

void setupPWM(int pin, int frequency, int resolution) {
    ledcSetup(0, frequency, resolution);  // Set up PWM channel 0
    ledcAttachPin(pin, 0);  // Attach PWM to the pin
}

void stabilizerControl(int servoPin) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    
    float gyroX = g.gyro.x * 180 / M_PI;  // Convert to degrees per second
    float angle = constrain(gyroX, -90, 90);

    int pwm_value = map(angle, -90, 90, 544, 2400);  // Map angle to PWM range
    ledcWrite(0, pwm_value);  // Write PWM value to servo
}
