// the PWM pin the LED is attached to
int blueLed = 9;
int blueBrightness = 85; // how many points to fade the LED by
int blueFadeAmount = 5;
int buttonState = 0;
int number = 0;
int lastButtonState = 0;
int SW1 = 2;
int on_off = 0; 


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(blueLed, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(SW1);
  
  // adds to the number if the button is pressed
  if (lastButtonState == 0 & buttonState == 1)
  {
    number++;
  }

  // if number % 2 is 0 --> normal procedure
  if (number % 2 == 0)
  {
    // change the brightness for next time through the loop:
    blueBrightness = blueBrightness + blueFadeAmount;
    analogWrite(blueLed, blueBrightness);

    if (blueBrightness <= 0 || blueBrightness >= 255) 
    {
      blueFadeAmount = -blueFadeAmount;
    }     
  }

  // if number % 2 is 0 --> turns off
  else if (number % 2 == 1)
  {
    analogWrite(blueLed, 0);
  }

  // keeps track of previous state and current state
  lastButtonState = buttonState; 
  on_off = number % 2;


  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  Serial.println(on_off);
}
