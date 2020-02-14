#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NUM 144
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);
#define NUM2 5
#define PIN2 5
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM2, PIN2, NEO_GRB + NEO_KHZ800);
int x=0;
int y=1;
int randompix;
int randompix2;
int randompix3;
char input;
uint32_t yellow=(253,209,9);
uint32_t Maincolor;
uint32_t Secondcolor;


void randomizer(){
  if(x==0){
  randompix=random(0, NUM);
  randompix2=random(0, NUM);
  randompix3=random(0, NUM);
  }
}
void fade(){
  for(int i=0; i<NUM; i++){
    strip.setPixelColor(i,Maincolor);
    strip.setBrightness(x);
  }
  strip.setPixelColor(randompix,Secondcolor);
  strip.setPixelColor(randompix2,Secondcolor);
  strip.setPixelColor(randompix3,Secondcolor);
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
    Maincolor= 237,28,36;
    Secondcolor= 0,101,179;
  }
  if(input=="b"){
    Maincolor= 0,101,179;
    Secondcolor= 237,28,36;
  }
}
void ball(){
  for(int i=0; i<5; i++){
    strip2.setPixelColor(i,0,0,255);
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
mainColor();
Maincolor= 0,101,179;
Secondcolor= 237,28,36;
}

void loop() {
  // put your main code here, to run repeatedly:
defineinput();
randomizer();
fade();
ball();
strip.show();
strip2.show();

delay(2);
}
