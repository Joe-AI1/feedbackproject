#include <Arduino.h>
#include "servo_pwm.h"   // Include the servo and PWM header
#include "temp.h"        // Include the temperature header
#include "humidity.h"    // Include the humidity header
#include "lcd_display.h"

int servoPin = 5;           // Pin for the servo motor
int tempSensorPin = 7;      // Pin for the temperature sensor
int humiditySensorPin = 8;  // Pin for the humidity sensor
int heatingElementPin = 2;  // Pin for controlling heating element
int pumpPin = 4;            // Pin for controlling the pump
int fanPin = 6;             // Pin for controlling the fan
int stabilizerPin = 33;     // Pin to enable stabilizer mode
int stabilizerActive = 0;   // Variable to track stabilizer state

void setup() {
    Serial.begin(115200);

    // Set up the servo motor and PWM
    setupServo(servoPin);
    setupPWM(servoPin, 5000, 8);  // Setup PWM with a frequency of 5000Hz and resolution of 8 bits

    pinMode(heatingElementPin, OUTPUT);  // Set up heating element control pin
    pinMode(pumpPin, OUTPUT);            // Set up pump control pin
    pinMode(fanPin, OUTPUT);             // Set up fan control pin
    pinMode(stabilizerPin, INPUT);  // Pin 33 for stabilizer input
    setupLCD();
}

void loop() {
    // Check if the stabilizer mode should be active (pin 33 is HIGH)
    stabilizerActive = digitalRead(stabilizerPin);

    if (stabilizerActive) {
        // Stabilizer mode using MPU6050
        float angle = 0;  // Initialize angle variable (replace with actual gyro data)
        stabilizerControl(servoPin);  // Call the stabilizer function
    } else {
        // Normal servo control (when stabilizer is not active)
        moveServo(0);    // Move to 0 degrees
        delay(10000);    // Wait for 10 minutes
        
        moveServo(35);   // Move to 35 degrees
        delay(10000);    // Wait for 10 minutes
        
        moveServo(-35);  // Move to -35 degrees
        delay(10000);    // Wait for 10 minutes
    }

    // ----- Temperature Control -----
    float temperature = readTemperature(tempSensorPin);  // Read the temperature
    controlHeating(heatingElementPin, temperature, 34.0, 37.0);  // Control heating based on limits

    Serial.print("Temperature: ");
    Serial.println(temperature);

    // ----- Humidity Control -----
    float humidity = readHumidity(humiditySensorPin);  // Read humidity from sensor
    controlPump(pumpPin, humidity, 40.0, 60.0);  // Control pump based on humidity limits (e.g., 40%-60%)

    Serial.print("Humidity: ");
    Serial.println(humidity);

    // ----- Fan Control -----
    controlFan(fanPin, temperature, humidity, 37.0, 60.0);  // Turn on fan if both temperature and humidity exceed limits

    updateLCD(temperature, humidity, stabilizerActive, digitalRead(fanPin));
    delay(1000);  // Delay for 1 second before the next loop iteration
}
