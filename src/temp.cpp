// temp.cpp
#include "temp.h"
#include <Arduino.h>

// Read the temperature from the sensor (you can adjust this based on your sensor)
float readTemperature(int sensorPin) {
    int sensorValue = analogRead(sensorPin);
    float voltage = sensorValue * (3.3 / 4095.0);  // Convert to voltage
    float temperature = voltage * 100.0;  // Convert voltage to temperature (Celsius)
    return temperature;
}

// Control the heating or cooling element
void controlHeating(int heatingElementPin, float measuredTemp, float minTemp, float maxTemp) {
    if (measuredTemp < minTemp) {
        digitalWrite(heatingElementPin, HIGH);  // Turn on heating
    } else if (measuredTemp > maxTemp) {
        digitalWrite(heatingElementPin, LOW);  // Turn off heating
    }
}

// Control the fan based on temperature and humidity thresholds
void controlFan(int fanPin, float temperature, float humidity, float maxTemp, float maxHumidity) {
    if (temperature > maxTemp && humidity > maxHumidity) {
        digitalWrite(fanPin, HIGH);  // Turn on fan if both temp and humidity are too high
    } else {
        digitalWrite(fanPin, LOW);   // Turn off fan otherwise
    }
}