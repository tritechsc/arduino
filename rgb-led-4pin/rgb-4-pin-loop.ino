//This works
int redPin = 7;
int greenPin = 6;
int bluePin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
int n;
int count;

void loop() {
   setColor(0, n, 0); 
   n++;
   if(n > 255) n = 0;
   delay(100);
   Serial.print(n);
   Serial.print(" ");
   count++;
  if (count % 20 == 0)Serial.println();
  
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
