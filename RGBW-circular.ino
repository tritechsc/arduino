// cw coleman  neo RGBW circular
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 25

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
    randomSeed(analogRead(0));
}

//set up variables
int w = 0;
int i; 
int red,green,blue,white;
int first,last;

void loop() {
  red = 127; green = 60; blue = 0; white = 0;
  circular(first,last,red,green,blue,white);
}



//red function
void circular(int s, int e,int r,int g,int b,int w){

  if (s = 0)
    {e = 15;}
   else{e = s - 1;}
   
int delayVal = 100;
int j;
for(j = 0; j < 16 ; j++){
          strip.setPixelColor(j, strip.Color(r,g,b,w ));
          r = r+ 3;
          delay(delayVal);
           strip.show();  
 }

}
