// the PWM pin the LED is attached to

#include <Servo.h>


int buttonState = 0;
int number = 0;
int lastButtonState = 0;
int SW1 = 2;
int on_off = 0; 
int pos = 0;    // variable to store the servo position
int pos_mov = 1;
Servo myservo;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(SW1, INPUT_PULLUP);
  myservo.attach(11);
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
    pos =pos+pos_mov;
    myservo.write(pos);

    if (pos == 0 || pos == 180) 
    {
      pos_mov = -pos_mov;
    }     
  }

  // if number % 2 is 0 --> turns off
  else if (number % 2 == 1)
  {
    myservo.write(pos);
  }

  // keeps track of previous state and current state
  lastButtonState = buttonState; 
  on_off = number % 2;


  // wait for 30 milliseconds to see the dimming effect
  delay(15);
  Serial.println(on_off);
}
