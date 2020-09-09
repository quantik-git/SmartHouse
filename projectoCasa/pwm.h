#ifndef _pwm_H
#define _pwm_H

typedef struct pwmLed {
  byte pin;
  byte channel;
  int frequency;
  byte resolution;
} PwmLed;

void fadeIn(int ledChannel) {
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
}

void fadeOut(int ledChannel) {
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}

void turnOn(int ledChannel) {
  ledcWrite(ledChannel, 0);
  delay(500);
  ledcWrite(ledChannel, 255);
}
/*
// setting PWM properties
#define FREQUENCY 5000
#define RESOLUTION 8

PwmLed leds[] = {
  {RED, 0, FREQUENCY, RESOLUTION},
  {GREEN, 1, FREQUENCY, RESOLUTION},
  {BLUE, 2, FREQUENCY, RESOLUTION}
};

for (PwmLed led : leds) {
  ledcSetup(led.channel, led.frequency, led.resolution);
  ledcAttachPin(led.pin, led.channel);
}

for (PwmLed led : leds) {
  fadeIn(led.channel);
  fadeOut(led.channel);
}
*/

#endif
