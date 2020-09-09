#ifndef _bme280_H
#define _bme280_H

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)


bool setupBme(Adafruit_BME280 *bme, uint8_t addr, TwoWire *theWire) {
  return bme->begin(addr, theWire);
}

void sensorSetup(Adafruit_BME280 *bme) {
  bool sensorStatus = bme->begin(0x76, &Wire1);  
  if (!sensorStatus) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void sensorPrint(Adafruit_BME280 *bme) { 
  // Read from bme1
  Serial.print("Temperature : ");
  Serial.print(bme->readTemperature());
  Serial.println(" ºC");

  Serial.print("Humidity : ");
  Serial.print(bme->readHumidity());
  Serial.println(" %");
  
  Serial.print("Pressure : ");
  Serial.print(bme->readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme->readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println("--------------------");
}
//0x76

#endif
