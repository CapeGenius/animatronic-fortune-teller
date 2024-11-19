/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
Servo myservo2;
// twelve Servo objects can be created on most boards

int blueLed = 9;
int blueBrightness = 85; // how many points to fade the LED by
int blueFadeAmount = 5;
int buttonState = 0;
int number = 0;
int lastButtonState = 0;
int SW1 = 2;
int on_off = 0; 
int pos = 0;    // variable to store the servo position
int pos_delta = 1; 

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the Servo object
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
    pos = pos + pos_delta;      
    myservo.write(pos);
    if (pos == 0 | pos == 180)
    {
      pos_delta = -pos_delta; 
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
  delay(30);
  Serial.println(on_off);
}

