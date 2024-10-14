#ifndef PID_H
#define PID_H

class PIDController {
public:
    PIDController(float kp, float ki, float kd);
    float calculate(float setpoint, float measured_value);

private:
    float kp, ki, kd;
    float previous_error;
    float integral;
};

#endif // PID_H
