// Code for the LED wall of stars

// we use PWM pins for each group of LEDs for advanced control of dimming
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 10;
int led5 = 11;

// start in different places to stagger timing
int bri1 = 0;
int bri2 = 75;
int bri3 = 149;
int bri4 = 112;
int bri5 = 38;

// saves whether each LED is increasing or decreasing in brightness
int amt1 = 1;  
int amt2 = 1;
int amt3 = 1;
int amt4 = -1;
int amt5 = -1;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led1, bri1);
  analogWrite(led2, bri2);
  analogWrite(led3, bri3);
  analogWrite(led4, bri4);
  analogWrite(led5, bri5);

 // change brightness by step of proper sign (pos/neg)
  bri1 = bri1 + amt1;
  bri2 = bri2 + amt2;
  bri3 = bri3 + amt3;
  bri4 = bri4 + amt4;
  bri5 = bri5 + amt5;

 // change from increasing to decreasing (or vice versa) once it reaches the limit of 0 or 255
  if (bri1 <= 0 || bri1 >= 255) {
    amt1 = -amt1;
  } else if (bri2 <= 0 || bri2 >= 255) {
    amt2 = -amt2;
  } else if (bri3 <= 0 || bri3 >= 255) {
    amt3 = -amt3;
  } else if (bri4 <= 0 || bri4 >= 255) {
    amt4 = -amt4;
  } else if (bri5 <= 0 || bri5 >= 255) {
    amt5 = -amt5;
  } 
  
  delay(30);
}
