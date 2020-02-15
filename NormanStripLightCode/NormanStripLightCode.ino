#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NUM 48
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

int x = 0;
int y = 1;
int randpix1;
int randpix2;
int randpix3;
int randpix4;
int randpix5;
int randpix6;
int randpix7;
int randpix8;
int randpix9;
int randpix10;
int randpix11;
int randpix12;
int randpix13;
int randpix14;
int randpix15;
int randpix16;
int randpix17;
int randpix18;
int randpix19;
int randpix20;
int randpix21;
int randpix22;
int randpix23;
int randpix24;

uint32_t enforcerYellow = strip.Color(255, 154, 0);
uint32_t enforcerBlue = strip.Color(0, 0, 108);
uint32_t vanilla = strip.Color(243, 229, 171);
uint32_t lime = strip.Color(0, 205, 0);
uint32_t hotPink = strip.Color(255, 0, 128);
uint32_t metallicGold = strip.Color(212, 175, 55);

void randomizer(){
  if(x == 0){
    randpix1 = random(0, 48);
    randpix2 = random(0, 48);
    randpix3 = random(0, 48);
    randpix4 = random(0, 48);
    randpix5 = random(0, 48);
    randpix6 = random(0, 48);
    randpix7 = random(0, 48);
    randpix8 = random(0, 48);
    randpix9 = random(0, 48);
    randpix10 = random(0, 48);
    randpix11 = random(0, 48);
    randpix12 = random(0, 48);
    randpix13 = random(0, 48);
    randpix14 = random(0, 48);
    randpix15 = random(0, 48);
    randpix16 = random(0, 48);
    randpix17 = random(0, 48);
    randpix18 = random(0, 48);
    randpix19 = random(0, 48);
    randpix20 = random(0, 48);
    randpix21 = random(0, 48);
    randpix22 = random(0, 48);
    randpix23 = random(0, 48);
    randpix24 = random(0, 48);
    }
  }

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

void pinkAndGoldBlink(){
  for(int i = 0; i < NUM; i++){
    strip.setPixelColor(i, hotPink);
    strip.setBrightness(x);
  }
  strip.setPixelColor(randpix1, metallicGold);
  strip.setPixelColor(randpix2, metallicGold);
  strip.setPixelColor(randpix3, metallicGold);
  strip.setPixelColor(randpix4, metallicGold);
  strip.setPixelColor(randpix5, metallicGold);
  strip.setPixelColor(randpix6, metallicGold);
  strip.setPixelColor(randpix7, metallicGold);
  strip.setPixelColor(randpix8, metallicGold);
  strip.setPixelColor(randpix9, metallicGold);
  strip.setPixelColor(randpix10, metallicGold);
  strip.setPixelColor(randpix11, metallicGold);
  strip.setPixelColor(randpix12, metallicGold);
  strip.setPixelColor(randpix13, metallicGold);
  strip.setPixelColor(randpix14, metallicGold);
  strip.setPixelColor(randpix15, metallicGold);
  strip.setPixelColor(randpix16, metallicGold);
  strip.setPixelColor(randpix17, metallicGold);
  strip.setPixelColor(randpix18, metallicGold);
  strip.setPixelColor(randpix19, metallicGold);
  strip.setPixelColor(randpix20, metallicGold);
  strip.setPixelColor(randpix21, metallicGold);
  strip.setPixelColor(randpix22, metallicGold);
  strip.setPixelColor(randpix23, metallicGold);
  strip.setPixelColor(randpix24, metallicGold);

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
delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:
  //redAndBlue();
  //stratify();
  randomizer();
  flash();
  strip.show();
  if(x > 48){
      x = 0;
  }
}
