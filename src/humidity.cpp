#include "humidity.h"
#include <Arduino.h>

// Function to read the humidity from the sensor
float readHumidity(int sensorPin) {
    int sensorValue = analogRead(sensorPin);
    float voltage = sensorValue * (3.3 / 4095.0);  // Convert to voltage
    float humidity = voltage * 100.0;  // Convert voltage to humidity (%)
    return humidity;
}

// Function to control the pump based on humidity
void controlPump(int pumpPin, float humidity, float minHumidity, float maxHumidity) {
    if (humidity < minHumidity) {
        digitalWrite(pumpPin, HIGH);  // Turn on the pump if humidity is too low
    } else if (humidity > maxHumidity) {
        digitalWrite(pumpPin, LOW);   // Turn off the pump if humidity is too high
    }
}
