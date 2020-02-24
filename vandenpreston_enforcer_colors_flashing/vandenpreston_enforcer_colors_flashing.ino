#include <Adafruit_NeoPixel.h>

#define PIN 4

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, PIN, NEO_GRB + NEO_KHZ800);
int i=0;
void blue() {

  while (i < 144+1) {
    strip.setPixelColor(i, 2,5,121);
    strip.show();
    i++;
  }
  }
  void yellow() {

  while (i < 144+1) {
    strip.setPixelColor(i, 255,208,0);
    strip.show();
    i++;
  }
  }
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'

}

void colorsflashing()
{
  yellow();
  delay(50);
  i=0;
  blue();
  delay(50);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
colorsflashing();
}
