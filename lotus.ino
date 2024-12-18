// Code for the light-up lotus flower ("crystal ball")

#include <RGBLed.h>

RGBLed led1(3, 5, 6, RGBLed::COMMON_CATHODE);
RGBLed led2(9, 10, 11, RGBLed::COMMON_CATHODE);

void setup() { }

void loop() {
  led2.setColor(255, 0, 255);
  led1.crossFade(255, 0, 255, 80, 0, 255, 100, 4000);
  led2.crossFade(255, 0, 255, 255, 0, 80, 100, 4000);
  led1.crossFade(80, 0, 255, 255, 0, 255, 100, 4000);
  led2.crossFade(255, 0, 80, 255, 0, 255, 100, 4000);
}
