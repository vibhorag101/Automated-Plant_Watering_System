# An Automated Plant Watering System
An Automated Plant Watering System using Arduino Uno R3, Ultrasonic and
Soil Humidity Sensor.It turns on the water pump automatically once the soil humidity
dips below a certain threshold. It also provides the users information like soil humidity
and bucket water level on a LCD.

## Hardware Needed 🛠️
- Arduino Uno R3
- HC-SR04 Sensor
- 5V 4 Channel Relay
- Jumper Wire
- LCD1602 Parallel LCD Display
- 16X2 I2C Module for LCD.
- Laser Transmitter Module For Arduino
-  SG90 9G MICRO SERVO MOTOR
- Breadboard
- 3.5-5.5V Standard Active Buzzer Module
- Water Pump
- 5V Adapter and AC Supply for Pump.

## Pin Setting 📌
- A0 is set as the soil sensor Analog Pin in Input Mode
- Digital Pin 6 is set as trigger pin for Ultrasonic Sensor
- Digital Pin 7 is set as echo recieving pin for Ultrasonic Sensor
- Digital Pin 10 is set as Relay Pin to control relay and thus water pump
- Digital Pin 11 is set as the Buzzer Pin

## Steps to Deploy the project 💻
- Clone the repository
- Install Arduino IDE and setup the environment.
- Now connect your Arduino Uno R3 to PC and flash to it using Arduino IDE

## Project Roadmap 🛣️
Find the Project Roadmap in Notion [here](https://vibhor20349.notion.site/0d5e07d96f0f48c88991cc896b61e940?v=e4d44f768d4f4f78b5a571fba82d3134)

## Images of the Deployed System 📸

### Complete Setup in Home

![image](https://user-images.githubusercontent.com/76804249/189982671-d3a380e8-b151-411e-863e-1189c85b69b2.png)

### System Up-Close and Soil Humidity Info

![image](https://user-images.githubusercontent.com/76804249/189982848-6f58a2c8-ddb9-419e-b256-b339b2d79cb3.png)

### Bucket Status 

![image](https://user-images.githubusercontent.com/76804249/189982962-718fce56-8069-44f8-9ea1-554bab495666.png)


## To-Do and Bug-Fixes✅
The following mentioned features need improvement
- Implement a solution for auto reservoir filling. Currently Manual
- Buzzer not working properly
- Need an automatic humidity calibration system.
