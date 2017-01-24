// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// Modified by CraigColeman  for an 8x8 neopixel
int clearPix ();
void column (int cnum);
int matrix();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//  8x8 array

int i = 0, j = 0;


//
int delayval = 50; // delay for half a second

void setup() {
  Serial.begin(9600);      //ser up Serial.*
      randomSeed(analogRead(0));
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}
int setcolumn;
void loop() {
//clearPix(); 
setcolumn = random(8);
column(setcolumn);  
//delay(100);
 
  
}
int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    }
    pixels.show();
  }

////////////////////////////////////////////////////////////
void column (int cnum){
//ser base color

int red = 0, green = 0, blue = 0;
            green = random(50)+10;
      for (int i = cnum; i < 64; i = i + 8 ){
        pixels.setPixelColor(i, pixels.Color(red,green,blue));
        green = green - 7;
        if (green < 0) green = 0;
             pixels.show(); 
      }
}

////////////////////////////////////////////////////////////
