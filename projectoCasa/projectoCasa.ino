#include <Wire.h>


#include "rgb.h"
#include "bme280.h"


// Leds PWM setup
#define RED 14
#define GREEN 22
#define BLUE 23

RgbLed led = {RED, GREEN, BLUE};


// LDR
byte ldr = 34;


/* 
 * BME initialization
 */
Adafruit_BME280 bme;

#define ADDRESS 0x76

#define SCL 32
#define SDA 33


int temp;
float hum;

 
void setup(){
  Serial.begin(115200);

  setupRgbLed(led);
  allOff(led);
  
  if(! Wire1.begin(SDA, SCL)) {
    Serial.println("Wire1.begin problem");
    while(1);
  }

  if(! bme.begin(ADDRESS, &Wire1)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}


void loop(){
  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  green(led, (ldrValue < 550) ? ON : OFF);


  sensorPrint(&bme);
  
  temp = bme.readTemperature();
  red(led, (temp > 24) ? ON : OFF);
  hum = bme.readHumidity();
  blue(led, (hum > 80) ? ON : OFF);

  delay(3000);
}
