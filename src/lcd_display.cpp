#include "lcd_display.h"
#include <LiquidCrystal_I2C.h>

// Set the LCD address and dimensions (20x4 LCD)
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Adjust I2C address if needed

// Function to set up the LCD
void setupLCD() {
    lcd.init();       // Initialize the LCD
    lcd.backlight();  // Turn on the backlight
    lcd.setCursor(0, 0);
    lcd.print("System Initializing");
}

// Function to update the LCD with real-time data
void updateLCD(float temperature, float humidity, bool stabilizerActive, bool fanStatus) {
    lcd.clear();  // Clear the display for the next update

    // Row 1: Display Temperature
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");

    // Row 2: Display Humidity
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print(" %");

    // Row 3: Display Servo Mode (Normal or Stabilizer)
    lcd.setCursor(0, 2);
    lcd.print("Servo Mode: ");
    lcd.print(stabilizerActive ? "Stabilizer" : "Normal");

    // Row 4: Display Fan Status
    lcd.setCursor(0, 3);
    lcd.print("Fan: ");
    lcd.print(fanStatus ? "ON" : "OFF");
}
