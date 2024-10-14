// servo_pwm.h
#ifndef SERVO_PWM_H
#define SERVO_PWM_H

// Function to set up the servo pin
void setupServo(int pin);

// Function to move the servo to a specific degree
void moveServo(int angle);

// Function to set up the PWM pin with frequency and resolution
void setupPWM(int pin, int frequency, int resolution);


// Function to handle stabilizer control based on gyro input
void stabilizerControl(int servoPin);

#endif  // SERVO_PWM_H
