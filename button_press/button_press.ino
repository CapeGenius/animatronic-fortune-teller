// the PWM pin the LED is attached to


int buttonState = 0;
int number = 0;
int lastButtonState = 0;
int SW1 = 2;
int on_off;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
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
    on_off = number % 2;
    Serial.println(on_off);
  }

  // keeps track of previous state and current state
  lastButtonState = buttonState; 
  


  // wait for 30 milliseconds to see the dimming effect
  delay(15);
  
}
