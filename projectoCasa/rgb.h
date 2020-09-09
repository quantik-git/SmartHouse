#ifndef _rbg_H
#define _rbg_H


#define ON 0
#define OFF 1

typedef struct rgbLed {
  byte red;
  byte green;
  byte blue;
} RgbLed;


void setupRgbLed(RgbLed led) {
  pinMode(led.red, OUTPUT);
  pinMode(led.green, OUTPUT);
  pinMode(led.blue, OUTPUT);
}

void allOff(RgbLed led) {
  digitalWrite(led.red, OFF);
  digitalWrite(led.green, OFF);
  digitalWrite(led.blue, OFF);
}

void red(RgbLed led, bool power) {
  digitalWrite(led.red, power);
}

void green(RgbLed led, bool power) {
  digitalWrite(led.green, power);
}

void blue(RgbLed led, bool power) {
  digitalWrite(led.blue, power);
}


#endif
