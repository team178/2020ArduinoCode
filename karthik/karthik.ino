#include <Adafruit_NeoPixel.h>

#define PIN 3
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800);

int(red) = 0;
int(green) = 1;

void enforcersColorsFlashing ()
{
  //enforcerBlueNum = enforcerBlueNum;
  //enforcerGoldNum = enforcerGoldNum;

  strip.show();
  for x range in
  delay(250);
  strip.setPixelColor(red, 0,0,0);
  delay(250);
  strip.setPixelColor(red, 255,0,0);
  strip.setPixelColor(green, 0,255,0);
 
  red+=1;
  green+=1;

 }

}

void EnforcersColorsOff()
{
  strip.clear();
  delay(500);
}
  
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  // put your main code here, to run repeatedly:
       
  enforcersColorsFlashing();
}
