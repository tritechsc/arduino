// grbw  neo-pixel modified by CW Coleman
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
int j = 15;  int i = 0; int count = 0;
int red = 100;  int green = 100;int blue = 100;

void loop() {
  // Some example procedures showing how to display to the pixels:

  strip.setPixelColor(i,red,green,blue );
  strip.setPixelColor(j,red,green,blue );
  strip.show();

    delay(30); // Delay for a period of time (in milliseconds).
    j--;
    i++;
    
    if (j < 0) j = 15;
    if (i > 16) i = 0;

    if (count > 32) {red = 100; green = 0; blue = 0;};
        if (count > 64) {red = 0; green = 100; blue = 0;};
           if (count > 96) {red = 0; green = 0; blue = 100;};
            if (count > 112) {red = 100; green = 100; blue = 0;count = 0;};
    
    count++;
}



