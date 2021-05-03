// we have calibrated the sensor taking analogRead 300 as wettest soil and 1000 as dryest soil
#include <LiquidCrystal_I2C.h>
#define sensorPin A0 // analog pin of the soil sensor is initialised to A0
LiquidCrystal_I2C lcd(0x27, 16, 2);
int moistureLevel; // the analog resistor output representing the moisture level
int moisturePercent;
void setup()
{
    pinMode(sensorPin, INPUT); // A0 of arduino is initialised as output
    Serial.begin(9600);
    welcomeLCD();
}
void loop()
{
    moistureLevel = moistureLevelFinder(sensorPin);
    moisturePercent = moisturePercentFinder(moistureLevel);
    humidityLCD(moisturePercent);

    delay(1000);
}

// NOTE below we implement the individual function required for the program

//function for calculating the humidity level of the soil
int moistureLevelFinder(int analogPin)
{ // input pin having analog input
    moistureLevel = analogRead(analogPin);
    return moistureLevel;
}
/* function for calculating the humidity percentage by taking 300 as the lower mark for wetness and
 taking 1000 as the upper mark for the dryness.
 */
int moisturePercentFinder(int moistureLevel)
{
    int moisturePercent = (1000 - moistureLevel) * (0.14); //  0.14 come by dividing 100 by (1000-300)
    if (moisturePercent > 100)
    {
        moisturePercent = 100;
    }
    else if (moisturePercent < 0)
    {
        moisturePercent = 0;
    }
    return moisturePercent;
}

void welcomeLCD()
{
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("WELCOME TO AUTO ");
    lcd.setCursor(0, 1);
    lcd.print("PLANT WATERING !");
}
void humidityLCD(int moisturePercent)
{
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("SOIL HUMIDITY");
    lcd.setCursor(4, 1);
    lcd.print("IS ");
    lcd.print(moisturePercent);
    lcd.print("%");
}