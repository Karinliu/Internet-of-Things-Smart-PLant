# Introduction

<img align="right" width="200" alt="screenshot 2018-11-12 19 12 28" src="https://user-images.githubusercontent.com/32538678/48366690-e6762300-e6ae-11e8-964a-98ad5fd8c622.png">

Before we start coding and building this prototype, I will explain what this prototype does and how it works. 

First of all, this prototype is builded in `Arduino`, a basil plant and three sensors: `Moisture Sensor v1.4`, `NEOPIXEL LEDstrip` and a `Lightsensor`. 

### Okayy and what is the idea of this prototype?
Well, what this code prototype does is when you put the sensors in your plant, the LED strip indicates how it goes with your plant. 


# Alright so how do I start?
Before we start to build this prototype you need the Moisture sensor Lightsensor, Node MCU and a LED strip with 7 lights, the reason for this is that the lights show the following colors: <br> 

Moisture: LEDS 1-3, if the plant has not enough moisture, the LED turns white. <br><img align="left" width="300" alt="screenshot 2018-11-12 19 21 44" src="https://user-images.githubusercontent.com/32538678/48367191-386b7880-e6b0-11e8-960a-4301493cf2d4.png">

| Colors led     | Meaning                                           | 
| -------------- |-------------------------------------------------- |
| 3 Blue         | Plant has enough moisture                         |
| 2 Blue 1 White | plant has water, but beware: it will be less.     |
| 1 Blue 2 White | Plant almost has no water, you have to give water.| 
| 3 White        | Plant has no moisture, you have to give water!    | 

Lightsensor: LEDS 5-7, if the plant does not have enough light, it changes from yellow to orange. <br><img align="left" width="300" alt="screenshot 2018-11-12 19 21 33" src="https://user-images.githubusercontent.com/32538678/48367190-37d2e200-e6b0-11e8-9ff7-3ceb111d144c.png">

| Colors led        | Meaning                                                   |
| ----------------- |---------------------------------------------------------- |
| 3 Yellow          | Plant has enough light                                    |
| 2 Yellow 1 Orange | plant has light, but beware: the light is decreasing.     |
| 1 Yellow 2 Orange | Plant almost has no light, you have to turn on the light. | 
| 3 Orange          | Plant has no light, you have to turn on the light!        | 

### And the code??
When you have all the sensors we continue with the coding. First arduino must be installed (when this has not been done). If you have not done yet, you can click on this link to download it: https://www.arduino.cc/en/Main/Software

# Arduino
Now we can start with coding! The steps we need to do is:
1. Open arduino.

### Ehh... Void setup Void loop??
The code that you put inside void setup() will only run once, and that will be at the beginning of your program. And in void loop(), your code will repeat over and over again. :)

The next step is:

2. Devine the sensors in your serial. To do that you can place in your void setup `Serial.begin(9600);`
3. Alright to check if it works, we can place an serial print line with a delay. For example I have: `Serial.println("Reading From the Sensor ...");` with a delay off 2000 milliseconds.
4. Save it under the project name you want to give and open you serial monitor to check if it is working.

<img width="1250" alt="screenshot 2018-11-12 17 09 59" src="https://user-images.githubusercontent.com/32538678/48359712-d144c880-e69d-11e8-8c1e-4e611316139b.png">

## LightSensor
When your serial is showing your comment, we can go to the next step. Connecting the Lightsensor with Arduino.
1. Connect your lightsensor with your NodeMCU (Analog port and 3V).
2. Define your lightsensor in your void setup`pinMode(A0, INPUT_PULLUP);`(I have used the analog A0).
3. Define your lightsensor in you void loop so your sensor can keep reading the values `int sensorValueLight = analogRead(A0);`.
4. Set a printline so to know the value of your lightsensor `Serial.println(sensorValueLight);`.
5. Open your serial monitor to check if it works.

<img width="1280" alt="screenshot 2018-11-12 17 25 07" src="https://user-images.githubusercontent.com/32538678/48360610-e884b580-e69f-11e8-82c8-ee3932adae38.png">


## Moisture Sensor
Now we can connect our lightsensor with Arduino. First we need to do is:
1. Connect your Moisture Sensor with your NodeMCU (Analog port, 3v and Ground/GND).
2. Above your Void setup we need to define the Moisture sensor with the following command: `int sensorPin = D7;` (I have used pin D7). 
3. After we have defined our pin, we need to set the sensorValue to 0 so the moisture sensor knows which number to start`int sensorValue = 0;`.
4. Define the moisture sensor in your void loop `sensorValue = analogRead(sensorPin);`.
5. Set a printline to know the value of your Moisture sensor `Serial.println(sensorValue);`.
6. Open your serial monitor to check if it works.

<img width="1280" alt="screenshot 2018-11-12 17 35 26" src="https://user-images.githubusercontent.com/32538678/48361219-5a113380-e6a1-11e8-9cb2-9982b46fd530.png">


## LED strip
The last sensor we need to connect is the LED strip. What we need to do is: 
1. Include the Adafruit Neopixel library `Sketch > include library > Manage library > Adafruit Neopixel`.
2. Define the LED in your void setup with the following command:
  ```
 strip.begin();
 strip.show();  
 ```
3. Define the LED and the ledpin (I have used ledpin D5) `#define LEDpin D5` <br> (with a LED strip of 18 lights)
`Adafruit_NeoPixel strip = Adafruit_NeoPixel(18, LEDpin, NEO_GRB + NEO_KHZ800); //getal = aantal LED's`
4. To turn on the lamp, we need to make a `new void` under the void loop. To do that you can use the following code:

```  
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    }
  }
  ```
5. After your new void is made, we can define the ledstrip in the loop with `colorWipe(strip.Color(0, 0, 100), 0);`.
6. Now your leds will turn blue!

<img width="1280" alt="screenshot 2018-11-12 17 56 28" src="https://user-images.githubusercontent.com/32538678/48362608-4ddaa580-e6a4-11e8-87e0-df5cf025f7a6.png">
  
  
## Yes it works! Huh, but wait, what about my plant?!?! It is not even connected with each other?!
That's right, the next step is to connect these sensors with each other.

# Connect sensors with each other
To connect the sensors together we need to hide some code. First we need to comment out the void colorWippe. <br>
• Windows: Select the code and use keys `ctrl` + `/`. <br>
• Mac: Select the code and use keys `command` + `/`. <br>

Also we need to comment out the following code: `colorWipe(strip.Color(0, 0, 100), 0);`.

## If/Else
Now the next step is to write an `if/else` statement. In the if else we set what the light value and the moisture value should be.

To do that we can write for the `Moisture Sensor` the following code:

```
if (sensorValue >= 1000){  

}
else if (sensorValue <= 999 && sensorValue >=700){

}
else if (sensorValue <= 699 && sensorValue >=301){

}
else if (sensorValue <= 300){

}
```

For the `Light sensor` we can write under the if/else statement:

```
if (sensorValueLight >= 1000){  

}
else if (sensorValueLight <= 999 && sensorValueLight >=700){

}
else if (sensorValueLight <= 699 && sensorValueLight >=301){
 
}
else if (sensorValueLight <= 300){

}
```
<img width="1280" alt="screenshot 2018-11-12 18 42 37" src="https://user-images.githubusercontent.com/32538678/48365364-fee43e80-e6aa-11e8-9f37-f3343a70005d.png">

## Define the LED strip number
After you have made the if/else statements we need to define every LED lights and number to place this leds. (Moisture 1-3 & Light sensor 5-7. For example what I have used
```
 void colorLedsMoisture3(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<3; i++) {     //Start on led strip number 1 and go to max led number 3.
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  void colorLedsMoisture2(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<2; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  void colorLedsMoisture1(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<1; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  void colorLedsLight3(uint32_t c, uint8_t wait) {
    for(uint16_t i=4; i<7; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  void colorLedsLight2(uint32_t c, uint8_t wait) {
    for(uint16_t i=4; i<6; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  void colorLedsLight1(uint32_t c, uint8_t wait) {
    for(uint16_t i=4; i<5; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  ```

<img width="1280" alt="screenshot 2018-11-12 18 43 15" src="https://user-images.githubusercontent.com/32538678/48365371-03105c00-e6ab-11e8-9ebd-4f43eae62637.png">

## Define the color in the if/else statement
Now that the voids is created, we can call the colors in the if/else statement. For example what I have used for the `Moisture sensor`.
```
  if (sensorValue >= 1000){  
      colorLedsMoisture3(strip.Color(20, 20, 100), 0);  
      delay(1000);
  }
  else if (sensorValue <= 999 && sensorValue >=700){
      colorLedsMoisture2(strip.Color(20, 20, 100), 0);  
      colorLedsMoisture1(strip.Color(100, 100, 100), 0); 
      delay(1000);
  }
  else if (sensorValue <= 699 && sensorValue >=301){
      colorLedsMoisture1(strip.Color(20, 20, 100), 0);  
      colorLedsMoisture2(strip.Color(100, 100, 100), 0);  
      delay(1000);
  }
  else if (sensorValue <= 300){
      colorLedsMoisture3(strip.Color(100, 100, 100), 0);  
      delay(1000);
  }
  ```
  And the example code what I have used for the `light sensor`.
  
  ```
  if (sensorValueLight >= 1000){  
      colorLedsLight3(strip.Color(100, 100, 0), 0);  
      delay(1000);
  }
  else if (sensorValueLight <= 999 && sensorValueLight >=700){
      colorLedsLight2(strip.Color(100, 100, 0), 0);  
      colorLedsLight1(strip.Color(100, 60, 0), 0); 
      delay(1000);
  }
  else if (sensorValueLight <= 699 && sensorValueLight >=301){
      colorLedsLight1(strip.Color(100, 100, 0), 0);  
      colorLedsLight2(strip.Color(100, 60, 0), 0);  
      delay(1000);
  }
  else if (sensorValueLight <= 300){
      colorLedsLight3(strip.Color(100, 60, 0), 0);  
      delay(1000);
  }
```

<img width="1280" alt="screenshot 2018-11-12 18 44 06" src="https://user-images.githubusercontent.com/32538678/48365376-06a3e300-e6ab-11e8-94aa-9b8676c97310.png">

And? Did the ledstrip show on the strip 1-3 the color blue and on the strip 5-7 the color yellow?

## It does not work..
If you have an error in your code check on `spelling`, `;` or `{}`. Otherwise you can try download my code from Github and upload into your Arduino board.

## Yes it works!
Nicely done!

## Can I change it into an another color?
To change the color you can edit the values in 'strip.color()' `LedStrip(strip.Color(100, 100, 100), 0);` the colors that are read on it are `LedStrip(strip.Color(Red, Green, Blue), 0)`.


## Other links to try?
If you like this project and you would like to do or learn more about these sensors. Then here are some links you can try:

#### Moisture sensor
• https://www.instructables.com/id/Arduino-Soil-Moisture-Sensor/
• http://wiki.seeedstudio.com/Grove-Moisture_Sensor/
• https://learn.sparkfun.com/tutorials/soil-moisture-sensor-hookup-guide/all

#### Lightsensor
• https://maker.pro/arduino/tutorial/how-to-use-an-ldr-sensor-with-arduino
• http://wiki.seeedstudio.com/Sensor_light/
• https://create.arduino.cc/projecthub/amar-slik/turn-on-and-off-led-by-ldr-toggle-ldr-2e3502

#### LED strip
• https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
• https://learn.adafruit.com/neopixel-painter/test-neopixel-strip
• https://github.com/adafruit/Adafruit_NeoPixel

