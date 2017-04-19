// cw coleman  neo RGBW circular with button input 
// https://www.arduino.cc/en/Tutorial/Button
// this code requires the Arduino Adafruit NeoPixel Library
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
const int led13 =  13;      // the number of the LED pin

//button state 
int buttonState2 = 0;      
int buttonState3 = 0;    
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

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(led13, HIGH);
    first = 0; leds = 16; red = 255, green = 0; blue = 127; white = 255;
    circular(first,leds,red,green,blue,white);
  } else {
    // turn LED off:
    digitalWrite(led13, LOW);
  }
  //end button code


}

// end of the event loop *************************

//red function
void circular(int s, int lds, int  r,int g,int b,int w){
// s:start   lds:the number of leds  r:red  g:green  b:blue  w:white
int delayVal = 100;// change the delayVal to speed things up
int j;
Serial.println();//debug
for(j = 0; j < 16 ; j++){
    Serial.println (s);//debug
          strip.setPixelColor(s, strip.Color(r,g,b,w ));
          delay(delayVal);
           strip.show();  
            s++; // increase s by 1;
            if (s > (lds -1)) { s = 0;}  
 }
}
