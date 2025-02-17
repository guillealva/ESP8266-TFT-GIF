#include "portal.h"
#include <SPI.h>
#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();

void setup() {

  tft.init();
  tft.setRotation(0);
  tft.setCursor(0, 0);
  tft.setSwapBytes(true);
  tft.fillScreen(0x6066);
  tft.setViewport(0, 0, 128, 160);

  
}

void loop() {

  for(int i=0;i<frames;i++)

  {
    delay(40);
    tft.pushImage(0, 0 ,animation_width ,animation_height ,portal[i]);
  }

}
