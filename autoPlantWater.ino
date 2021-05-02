# define sensorPin A0 // analog pin of the soil sensor is initialised to A0
int moistureLevel; // the analog resistor output representing the moisture level
int moisturePercent;
void setup(){
pinMode(sensorPin,INPUT); // A0 of arduino is initialised as output
Serial.begin(9600);
}
void loop(){
    moistureLevel= moistureLevelFinder(sensorPin);
    moisturePercent=moisturePercentFinder(moistureLevel);
    Serial.println(moistureLevel);
    Serial.println(moisturePercent);
    
    delay(1000); 
}
//function for calculating the humidity level of the soil
int moistureLevelFinder(int analogPin){ // input pin having analog input
    moistureLevel=analogRead(analogPin); 
    return moistureLevel;
}
/* function for calculating the humidity percentage by taking 300 as the lower mark for wetness and
 taking 1000 as the upper mark for the dryness.
 */
int moisturePercentFinder(int moistureLevel){
    int moisturePercent= (1000-moistureLevel)*(0.14);
    return moisturePercent;
}
