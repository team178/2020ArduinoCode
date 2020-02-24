
#include <Adafruit_NeoPixel.h>
#include <Wire.h>


// First strips, fading red with random blue lights
#define N 144
#define P 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N, P, NEO_GRB + NEO_KHZ800);

//Second strip, ball status lights
#define N2 60
#define P2 5
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(N2, P2, NEO_GRB + NEO_KHZ800);

/*#define PIN3 6
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(N, PIN3, NEO_GRB + NEO_KHZ800);*/

/*#define N4 20
#define PIN4 6
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(N4, PIN4, NEO_GRB + NEO_KHZ800);*/

int x=0;
int y=1;
int randompix;
int randompix2;
//int randompix3;
int input;
String binin;
int RM;
int GM;
int BM;
int RS;
int GS;
int BS;
int balls = 3;


//Generates which 3 pixels out of stip1 to invert the color
void randomizer(){
  if(x==0){
  randompix=random(0, N);
  randompix2=random(0, N);
  //randompix3=random(0, N);
  }
}

//Fade team color with 3 pixels the opposite color
void fade(){  for(int i=0; i<N; i++){
    strip.setPixelColor(i,RM,GM,BM);
    strip.setBrightness(x);
  }
  strip.setPixelColor(randompix,RS,GS,BS);
  strip.setPixelColor(randompix2,RS,GS,BS);
//  strip.setPixelColor(randompix3,RS,GS,BS);
  if(y==1){
  x++;
  if(x==127){
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

//Read the input coming from roboRIO
void readInput(int numBytes){
  //Get I2C input
  if( 0 < Wire.available()){
    //Take input and convert to integer
    //input is brought in as a binary format
    binin = Wire.read();
    input = binin.toInt();

  }
  Serial.print(input);

  //Find case for the incoming input
  switch(input){
    case 114:
      //Fade Red (r)
      RM=127;
      GM=0;
      BM=0;
      RS=15;
      GS=0;
      BS=127;
      break;
    case 98:
      //Fade Blue (b)
      RM=15;
      GM=0;
      BM=127;
      RS=127;
      GS=0;
      BS=0;
      break;
    //case 108:
      //Lightsaber (l)
      //lightsaber();
      //break;
    case 0:
      // 0 balls in chute
      balls = 0;
      for(int i = 0; i < N2; i++){
        strip2.setPixelColor(i, 0,0,0);
      }
      break;
    case 01:
      // 1 balls in chute
      balls = 1;
      ball();
      break;
    case 10:
      // 2 balls in chute
      balls = 2;
      ball();
      break;
    case 11:
      // 3 balls in chute
      balls = 3;
      ball();
      break;
    case 100:
      // 4 balls in chute
      balls = 4;
      ball();
      break;
    case 101:
      // 5 balls in chute
      balls = 5;
      ball();
      break;
  }

}

//Set the sections of strip2 to show the status of the ball chute
void ball(){
    strip2.clear();
    //For as many balls there are in the chute, from roboRIO input, divide the length of the strip by five and fill those sections
   for(int i = 0; i < (N2*balls-30)/5; i++){
     strip2.setPixelColor(i, 255,255,255);
 //    strip3.setPixelColor(i,255,255,255);
     Serial.print(i);
    }
}
void lightsaber(){
  for(int i=30; int j=31; i<N2; i=i+2; j=j+2){
    strip2.setPixelColor(i,RM,GM,BM);
    strip2.setPixelColor(j,RM,GM,BM);
    strip2.show();
    delay(2);
  }
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
strip.begin();
strip.show();
strip2.begin();
strip2.show();
//strip3.begin();
//strip3.show();
//strip4.begin();
//strip4.show();
Wire.begin(4);                // join i2c bus with address #4
Wire.onReceive(readInput);    // event handler for when an input is detected
}

void loop() {
  // put your main code here, to run repeatedly:
randomizer();
fade();
strip.show();
strip2.show();
//strip3.show();
delay(1);
}
