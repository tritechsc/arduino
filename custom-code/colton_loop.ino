// cw coleman  neo RGBW circular
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 24

#define BRIGHTNESS 25

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

// define input pins
const int button2 = 2;     // the number of the pushbutton pin
const int button3 = 3;     // the number of the pushbutton pin
const int button4 = 4;
const int button5 = 5;
const int led13 =  13;      // the number of the LED pin

//button state 
int buttonState2 = 0;      
int buttonState3 = 0;    
int buttonState4 = 0;    
int buttonState5 = 0;    


void setup() {
  Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  // initialize the LED pin as an output:
  pinMode(led13, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button2, INPUT);
    pinMode(button3, INPUT);
}

//set up variables
int red,green,blue,white;
//set first led and total leds
int first = 0;
int last = 23;  //last is one than the real last


//The event loop  *************************
void loop() {

   first = 0; last = 23; red = 255; green = 0; blue = 0; white = 10;
      circular(first,last,red,green,blue,white);
      delay(1000);
 first = 12; last = 23; red = 0; green = 255; blue = 0; white = 10;
      circular(first,last,red,green,blue,white);
      delay(1000);

      first = 0; last = 11; red = 0; green = 0; blue = 255; white = 10;
      circular(first,last,red,green,blue,white);
      delay(1000);
// button code

 
  
  //end button code


}

// end of the event loop *************************

//red function
// s is start  e is end
void circular(int s, int e, int  r,int g,int b,int w){
// s:start   lds:the number of leds  r:red  g:green  b:blue  w:white
int delayVal = 10;// change the delayVal to speed things up
int j;

//Serial.println();//debug
for(j = s; j < (e+1) ; j++){
   // Serial.println (s);//debug
          strip.setPixelColor(j, strip.Color(r,g,b,w ));
          delay(delayVal);
           strip.show();  
           
 }
}
