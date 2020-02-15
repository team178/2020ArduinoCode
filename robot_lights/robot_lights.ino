#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NUM 144
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);
#define NUM2 5
#define PIN2 4
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM2, PIN2, NEO_GRB + NEO_KHZ800);
int x=0;
int y=1;
int randompix;
int randompix2;
int randompix3;
char input;
int RM;
int GM;
int BM;
int RS;
int GS;
int BS;


void randomizer(){
  if(x==0){
  randompix=random(0, NUM);
  randompix2=random(0, NUM);
  randompix3=random(0, NUM);
  }
}
void fade(){
  for(int i=0; i<NUM; i++){
    strip.setPixelColor(i,RM,GM,BM);
    strip.setBrightness(x);
  }
  strip.setPixelColor(randompix,RS,GS,BS);
  strip.setPixelColor(randompix2,RS,GS,BS);
  strip.setPixelColor(randompix3,RS,GS,BS);
  if(y==1){
  x++;
  if(x==255){
    y=0;
  }
}
else{
  x--;
  if(x==0){
    y=1;
  }
}
}
void defineinput(){
  if(Wire.available() >0){
    input=Wire.read();
  }
}
void mainColor(){
  if(input=="r"){
    RM=127;
    GM=0;
    BM=0;
    RS=15;
    GS=0;
    BS=127;
  }
  if(input=='b'){
    RM=15;
    GM=0;
    BM=127;
    RS=127;
    GS=0;
    BS=0;
  }
}
void ball(){
  for(int i=0; i<NUM2;i++){
    strip.setPixelColor(i,127,0,0);
  }
  if(input=='1'){
    for(int i=0; i<NUM2/5; i++){
      strip.setPixelColor(i,0,0,0);
    }
  }
  if(input=='2'){
    for(int i=0; i<(NUM2*2)/5;i++){
      strip.setPixelColor(i,0,0,0);
    }
  }
  if(input=='3'){
    for(int i=0; i<(NUM2*3)/5;i++){
      strip.setPixelColor
    }
  }
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
strip.begin();
strip.show();
strip2.begin();
strip2.show();
strip. setBrightness(40);
Wire.begin(4);                // join i2c bus with address #4
//mainColor();
RM=15;
GM=0;
BM=127;
RS=127;
GS=0;
BS=0;
}

void loop() {
  // put your main code here, to run repeatedly:
defineinput();
randomizer();
fade();
ball();
strip.show();
strip2.show();

delay(1);
}
