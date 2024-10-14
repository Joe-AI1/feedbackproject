#ifndef HUMIDITY_H
#define HUMIDITY_H

// Function to read humidity from a sensor
float readHumidity(int sensorPin);

// Function to control a pump based on humidity
void controlPump(int pumpPin, float humidity, float minHumidity, float maxHumidity);

#endif  // HUMIDITY_H
