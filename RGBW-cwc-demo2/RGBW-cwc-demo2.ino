
//RGBW demo cw coleman dem2

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 50

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
}

//set up variables
int w = 0;
int i; 
int parity = 1;
//the  loop starts
void loop() {
 for(i = 0; i < 16 ; i++){
          //    strip.setPixelColor(pin number , strip.Color( red value,green value , blue value ,white value ) );
          strip.setPixelColor(i, strip.Color(0,0,0,w ) );
       
          
 }
 strip.show();
delay(10);
  if  (w > 225) {parity = -1;};
  if  (w < 30) { parity = 1;};
  w = w + parity;
 
}
