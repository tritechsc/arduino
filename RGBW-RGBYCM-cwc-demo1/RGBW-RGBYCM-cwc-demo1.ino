// cw coleman  neo RGBW demo 1
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

    randomSeed(analogRead(0));
}

//set up variables
long randomNumber;
int w;
int red = 0;  int green = 0; int blue = 0; int white = 0;
int pin;

void loop() {
  //pin 0  red
  pin = 0;red = 255; green = 0; blue = 0; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

   //pin 1 green
  pin = 1; red = 0; green = 255; blue = 0; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

      //pin 2 blue
  pin = 2; red = 0; green = 0; blue = 255; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

    //pin 3 yellow
     pin = 3; red = 255; green = 255; blue = 0; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

       //pin 4 cyan
     pin = 4; red = 0; green = 255; blue = 255; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 5 magenta
     pin = 5; red = 255; green = 0; blue = 255; white = 0;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

   //pin 6 white
     pin = 6; red = 0; green = 0; blue = 0; white = 255;
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 7 
     pin = 7;     red= random(255);     green= random(255);     blue= random(255);     white= random(8);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ));

     //pin 8 
     pin = 8; red= random(255);     green= random(255);     blue= random(255);     white= random(16);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 9 
     pin = 9; red= random(255);     green= random(255);     blue= random(255);     white= random(24);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 10 
     pin = 10; red= random(255);     green= random(255);     blue= random(255);     white= random(32);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 11 
     pin = 11; red= random(255);     green= random(255);     blue= random(255);     white= random(40);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 12 
     pin = 12;red= random(255);     green= random(255);     blue= random(255);     white= random(48);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 13
     pin = 13; red= random(255);     green= random(255);     blue= random(255);     white= random(56);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 14 
     pin = 14; red= random(255);     green= random(255);     blue= random(255);     white= random(64);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

     //pin 15
     pin = 15; red= random(255);     green= random(255);     blue= random(255);     white= random(72);
   strip.setPixelColor(pin, strip.Color(red,green,blue,white ) );

   

    
  //show neo-pixel
    strip.show();  

    delay (2000);
}



