// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
//modified by cwcoleman
// download the following frmo
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 250; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}
int red = 0;
int green = 0;
int blue = 0;
int thedelay = 250;
int PixelNum = 8;
int max = 155;
void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<(PixelNum / 2);i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(red,green,blue)); 
    pixels.setPixelColor((PixelNum -1)-i, pixels.Color(red,green,blue)); 
    
    pixels.show(); // This sends the updated pixel color to the hardware.
  
    
    delay(thedelay); // Delay for a period of time (in milliseconds).

  }
  //  red = red + 1;
    green = green + (255/7);
 //   blue = blue + 1;
    if (red > max) red = 0;
    if (green > max) green = 0;
    if (blue > max) blue = 0;
}
