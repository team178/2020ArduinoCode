#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NUM 48
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

int x = 0;
int y = 1;
uint32_t enforcerYellow = strip.Color(255, 154, 0);
uint32_t enforcerBlue = strip.Color(0, 0, 108);
uint32_t vanilla = strip.Color(243, 229, 171);
uint32_t lime = strip.Color(0, 205, 0);



void redAndBlue(){
  
  int temporary = 0;
  if (temporary % 2 != 0){
    strip.setPixelColor(x,255,0,0);
  }
  strip.show();
  delay(500);
  temporary++;
  x++;
  }

void stratify(){
  int stripPattern[48] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};

  for(int f = 0; f < NUM; f++){
    if(stripPattern[f] == 0){
      strip.setPixelColor(f, enforcerYellow);
    }
    else if(stripPattern[f] == 1){
      strip.setPixelColor(f, enforcerBlue);
    }
    else if(stripPattern[f] == 2){
      strip.setPixelColor(f, vanilla);
    }
    else if(stripPattern[f] == 3){
      strip.setPixelColor(f, lime);
    }
  }
}


void flash(){
  for(int i=0; i<NUM; i++){
    strip.setPixelColor(i,x,0,0);
  }
  if(y==1){
    x++;
  if(x==255){
    y = 0;
  }
  }
  else{
    x--;
  if(x==0){
    y = 1;
  }
}
  }

void setup() {
  // put your setup code here, to run once:
strip.begin();
strip.show();
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  redAndBlue();
  stratify();
  flash();
  if(x > 48){
      x = 0;
  }
}
