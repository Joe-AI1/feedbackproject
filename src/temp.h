// temp.h
#ifndef TEMP_H
#define TEMP_H

// Function to read temperature from a sensor
float readTemperature(int sensorPin);

// Function to control a heating or cooling element based on temperature
void controlHeating(int heatingElementPin, float measuredTemp, float minTemp, float maxTemp);

// Function to control the fan based on both temperature and humidity
void controlFan(int fanPin, float temperature, float humidity, float maxTemp, float maxHumidity);

#endif  // TEMP_H
