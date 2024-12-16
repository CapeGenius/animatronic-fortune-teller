// the PWM pin the LED is attached to
#include <Button.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Button button1(2);

Servo myservo;  // create Servo object to control a servo
Servo myservo2;  // create Servo object to control a servo
Servo myservo_tilt;
Servo myservo_pan;
Servo torsoServo;

// Adafruit PWM Servo Driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Constants for Adafruit Motor Shield
#define SERVO_MIN  150  // Minimum pulse length count
#define SERVO_MAX  600  // Maximum pulse length count
int adafruitServoPos = 90; // Initial position for the Adafruit Motor Shield servo
int pos_mov_adafruit = 1;

int pos = 10;    // variable to store the servo position
int pos_pan = 80;
int pos_torso = 91;
int pos_mov = 1;
int pos_mov_tilt = 1;
int pos_mov_torso = 1;
int buttonState = 0;
int number = 0;
int lastButtonState = 0;
int SW1 = 2;
int on_off;

// the setup routine runs once when you press reset:
void setup() {


  // declare pin 9 to be an output:
  myservo.attach(3);  // attaches the servo on pin 9 to the Servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the Servo object  
  myservo_tilt.attach(6);  // attaches the servo on pin 9 to the Servo object  
  myservo_pan.attach(5);
  pinMode(SW1, INPUT_PULLUP);
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(50);  // Set frequency to 50 Hz (standard for servos)
}

// the loop routine runs over and over again forever:
void loop() {  

  // adds to the number if the button is pressed
  if (button1.released())
  {
    number++;
    on_off = number % 4;
    Serial.println(on_off);
    //Serial.println(on_off);
  }

  if (on_off == 1)
  {
    pos =pos+pos_mov;
    pos_pan = pos_pan+pos_mov_tilt;
    myservo.write(pos);
    myservo2.write(pos);
    myservo_tilt.write(pos_pan);
    myservo_pan.write(pos_pan);
    torsoServo.write(pos_torso);
    adafruitServoPos += pos_mov_adafruit;

    // Serial.println(pos_pan);
    // myservo3.write(pos_pan);
    if (pos < 10 || pos > 180) 
    {
      pos_mov = -pos_mov;
    }
    if (pos_pan < 80 || pos_pan > 110) 
    {
      pos_mov_tilt = -pos_mov_tilt;
    }
    if (pos_torso < 89 || pos_torso > 97)
    {
      pos_mov_torso = -pos_mov_torso;
    }
  }


  else if (on_off == 3)
  {
    pos = pos+pos_mov;
    myservo.write(pos);
    myservo2.write(pos);
    myservo_tilt.write(pos_pan);
    myservo_pan.write(pos_pan);
    torsoServo.write(pos_torso);
    // myservo3.write(pos_pan);

    if (pos < 10 || pos > 180) 
    {
      pos_mov = -pos_mov;
    }
    if (pos_pan < 10 || pos_pan > 40) 
    {
      pos_mov_tilt = -pos_mov_tilt;
    }
    if (pos_torso < 85 || pos_torso > 95)
    {
      pos_mov_torso = -pos_mov_torso;
    }
  }

  // keeps track of previous state and current state


  // wait for 30 milliseconds to see the dimming effect
  delay(15);
  
}
