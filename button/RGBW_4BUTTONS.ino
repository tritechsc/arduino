// cw coleman  neo RGBW circular
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

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
int first = 10;
int leds = 16;
int count = 0;

//The event loop  *************************
void loop() {
 
// button code

 // read the state of the pushbutton value:
  buttonState2 = digitalRead(button2);
buttonState3 = digitalRead(button3);
buttonState4 = digitalRead(button4);
buttonState5 = digitalRead(button5);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {
    digitalWrite(led13, HIGH);
    first = 0; leds = 16; red = 255, green = 0; blue = 127; white = 255;
    circular(first,leds,red,green,blue,white);
  } else {
    digitalWrite(led13, LOW);
    circular(0,15,0,0,0,0);
  }
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {
    digitalWrite(led13, HIGH);
    first = 0; leds = 16; red = 255, green = 0; blue = 0; white = 50;
    circular(first,leds,red,green,blue,white);
  } else {
    digitalWrite(led13, LOW);
    circular(0,16,0,0,0,0);
  }

if (buttonState3 == HIGH) {
    digitalWrite(led13, HIGH);
    first = 0; leds = 8; red = 0, green = 0; blue = 255; white = 50;
    circular(first,leds,red,green,blue,white);
  } else {
    digitalWrite(led13, LOW);
    circular(0,16,0,0,0,0);
  }

  
  //end button code


}

// end of the event loop *************************

//red function
void circular(int s, int lds, int  r,int g,int b,int w){
// s:start   lds:the number of leds  r:red  g:green  b:blue  w:white
int delayVal = 10;// change the delayVal to speed things up
int j,k;
k = s;
//Serial.println();//debug
for(j = s; j < lds ; j++){
   // Serial.println (s);//debug
          strip.setPixelColor(k, strip.Color(r,g,b,w ));
          delay(delayVal);
           strip.show();  
            k++; // increase s by 1;
            if (k > (15)) { k = 0;}  
 }
}
