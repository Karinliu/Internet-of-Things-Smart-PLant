//Neopixel LedStrip
#include <Adafruit_NeoPixel.h>
#define LEDpin D5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(18, LEDpin, NEO_GRB + NEO_KHZ800); //getal = aantal LED's

//#include <dht.h>
//dht DHT;

//Grove - Temperature&Humidity Sensor
//#define DHT11_PIN D4

//Moisture Sensor
int sensorPin = D7;     //Moisture cable connect it to pin D7
int sensorValue = 0;    //Moisture set value to 0

void setup() {
   Serial.begin(9600);   //Serial monitor 9600 read.
   Serial.println("Reading From the Sensor ..."); //Print line "text"
   delay(2000);
   
   //LightSensor
   pinMode(A0, INPUT_PULLUP); 
   
   //LedStrip
   strip.begin();
   strip.show(); // Initialize all pixels to 'off'  
   }
   
void loop() {
  
   //Grove - Temperature&Humidity Sensor
//   int chk = DHT.read11(DHT11_PIN);
//   Serial.println("Temperature = ");
//   Serial.println(DHT.temperature);
//   Serial.println("Humidity = ");
//   Serial.println(DHT.humidity);
//   delay(1000);

   //Lightsensor
   int sensorValueLight = analogRead(A0);
   Serial.println("Lightsensor is");
   Serial.println(sensorValueLight);
   
   //Moisture sensor
   sensorValue = analogRead(sensorPin);   // SensorValue is the value that is read from the pin D7/
   Serial.println("Mositure is ");        // Print Line this text.
   Serial.println(sensorValue);           // Print the value what is readed.
   delay(1000);
 
// MOISTURE SENSOR START IF ELSE
    if (sensorValue >= 1000)
    {  
      colorLedsMoisture3(strip.Color(20, 20, 100), 0);  
      delay(1000);
//      Serial.println("3 Blue");
    }
    
    else if (sensorValue <= 999 && sensorValue >=700) 
    {
      colorLedsMoisture2(strip.Color(20, 20, 100), 0);  
      colorLedsMoisture1(strip.Color(100, 100, 100), 0); 
      delay(1000);
//      Serial.println("Wordt twee blauw en 1 wit");
    }
    else if (sensorValue <= 699 && sensorValue >=301) 
    {
      colorLedsMoisture1(strip.Color(20, 20, 100), 0);  
      colorLedsMoisture2(strip.Color(100, 100, 100), 0);  
      delay(1000);
      Serial.println("2 Blue and 1 White");
    }
    
    else if (sensorValue <= 300) 
    {
      colorLedsMoisture3(strip.Color(100, 100, 100), 0);  
      delay(1000);
      Serial.println("3 White");
    }
 // MOISTURE SENSOR FINISH IF ELSE
 
 // LIGHTSENSOR START IF ELSE  
      if (sensorValueLight >= 1000)
    {  
      colorLedsLight3(strip.Color(100, 100, 0), 0);  
      delay(1000);
    }
    
    else if (sensorValueLight <= 999 && sensorValueLight >=700) 
    {
      colorLedsLight2(strip.Color(100, 100, 0), 0);  
      colorLedsLight1(strip.Color(100, 60, 0), 0); 
      delay(1000);
    }
    else if (sensorValueLight <= 699 && sensorValueLight >=301) 
    {
      colorLedsLight1(strip.Color(100, 100, 0), 0);  
      colorLedsLight2(strip.Color(100, 60, 0), 0);  
      delay(1000);
    }
    
    else if (sensorValueLight <= 300) 
    {
      colorLedsLight3(strip.Color(100, 60, 0), 0);  
      delay(1000);
      Serial.println("Wordt alle 3 wit");
    }
 // LIGHTSENSOR FINISH IF ELSE  

// START VOIDS MOISTURE SENSOR   
 }
 void colorLedsMoisture3(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<3; i++) {
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
// FINISH VOIDS MOISTURE SENSOR 

//START VOIDS LIGHTSENSOR
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

//FINISH VOIDS LIGHTSENSOR

//ALL COLORS FROM LEDSRIP
  void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    }
  }
  
// Sources
// http://wiki.seeedstudio.com/Grove-Moisture_Sensor/   //Moisture Sensor
// https://docs.google.com/document/d/11qtJXaA1iL-qNUTrv6syh-FLeSwrIBpufeN2k9IH6zY/edit#  //Grove - Temperature&Humidity Sensor
