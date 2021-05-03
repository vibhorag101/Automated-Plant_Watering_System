// we have calibrated the sensor taking analogRead 300 as wettest soil and 1000 as dryest soil

#include <LiquidCrystal_I2C.h>
#define sensorPin A0 // analog pin of the soil sensor is initialised to A0
#define trigPin 6
#define echoPin 7
LiquidCrystal_I2C lcd(0x27, 16, 2);
int moistureLevel; // the analog resistor output representing the moisture level
int moisturePercent;
int reservoirWaterLevel;
int reservoirWaterPercent;
void setup()
{
    pinMode(sensorPin, INPUT); // A0 of arduino is initialised as output
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    welcomeLCD();
}
void loop()
{
    moistureLevel = moistureLevelFinder(sensorPin);
    moisturePercent = moisturePercentFinder(moistureLevel);
    humidityLCD(moisturePercent);
    wateringStatus(moisturePercent);
    reservoirWaterLevel = reservoirLevel();
    
    /* NOTE temporary code to find the hieght of the reservoir.
    lcd.clear();
    lcd.print(reservoirWaterLevel);
    delay(3000);
    */

    reservoirWaterPercent=reservoirLevelPercent(reservoirWaterLevel);
    reservoirPercentLCD(reservoirWaterPercent);

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
    delay(3000);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("MADE BY");
    lcd.setCursor(1, 1);
    lcd.print("VIBHOR AGARWAL");

    delay(4000);
}
void humidityLCD(int moisturePercent)
{
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("SOIL HUMIDITY");
    lcd.setCursor(5, 1);
    lcd.print("IS ");
    lcd.print(moisturePercent);
    lcd.print("%");
    delay(3000);
}

/* NOTE if moisturePercent > 80 - soil is too wet and no need to water
if moisturePercent<40 - soil is too dry, turning the pump on
if 40 < moisturePercent < 80 then soil humidity OK no need to water.
*/

void wateringStatus(int moisturePercent)
{
    if (moisturePercent <= 30)
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("SOIL TOO DRY");
        lcd.setCursor(0, 1);
        lcd.print("PUMP SWITCHED ON");
    }
    else if (moisturePercent > 30 & moisturePercent < 80)
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("SOIL GOOD");
        lcd.setCursor(1, 1);
        lcd.print("PUMP NO CHANGE");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SOIL TOO WET");
        lcd.setCursor(0, 1);
        lcd.print("PUMP SWITCHED OF");
    }
    delay(3000);
}
// calculate the reservoir water height to find the reservoir water percentage
float reservoirLevel()
{
    long bounceTime;
    float distanceCM;
    float distanceInch;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(trigPin, LOW);
    bounceTime = pulseIn(echoPin, HIGH);
    distanceCM = bounceTime / 58.2;
    return distanceCM;
}

int reservoirLevelPercent(int reservoirLevel)
{
    int reservoirPercent = map(reservoirLevel, 15, 45, 100, 0);
    return reservoirPercent;
}

void reservoirPercentLCD(int reservoirLevelPercent){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RESERVOIR WATER");
    lcd.setCursor(2,1);
    lcd.print("IS ");
    lcd.print(reservoirLevelPercent);
    lcd.print(" %");   
}
