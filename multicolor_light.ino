// the PWM pin the LED is attached to
int blueLed = 9;
int blueBrightness = 85; // how many points to fade the LED by
int blueFadeAmount = 5;
int buttonState = 0;
int SW1 = 2;


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop() {
  analogWrite(blueLed, blueBrightness);

  // change the brightness for next time through the loop:
  blueBrightness = blueBrightness + blueFadeAmount;


  if (blueBrightness <= 0 || blueBrightness >= 255) {
    blueFadeAmount = -blueFadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}


