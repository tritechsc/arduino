// cw coleman  neo RGBW demo 
//Ultra Somic
#define trigPin 7  // trigger pin
#define echoPin 8  // echo pin
#define led13 13


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
  //Ultra Sonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led13, OUTPUT);
}

//set up variables
int w = 10;
int i;  
int red, green, blue;
int proximity = 30;
void loop() {
long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);


  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; // convert to cm
  
  if (distance < proximity) {  // This is where the LED On/Off happens
    digitalWrite(led13,HIGH); // When the Red condition is met, the Green LED should turn off
     neo16(0,255,0,10);
 strip.show();
}
  else {
    digitalWrite(led13,LOW);
      neo16(255,0,0,10);
  }
  if (distance > 20){
    Serial.print(distance);
    Serial.println(" cm");
     //neo16(0,0,0,0);
  }

}

void neo16(int rd, int gn, int be, int we){
  // neo
 for(i = 0; i < 16 ; i++){
          //    strip.setPixelColor(pin number , strip.Color( red value,green value , blue value ,white value ) );
          red  = random(255);
          strip.setPixelColor(i, strip.Color(rd,gn,be,we ) );
          
 }
 strip.show();
//end neo
}
