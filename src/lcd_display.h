#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

void setupLCD();
void updateLCD(float temperature, float humidity, bool stabilizerActive, bool fanStatus);

#endif // LCD_DISPLAY_H
