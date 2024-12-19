// the PWM pin the LED is attached to
#include <Button.h>
#include <Servo.h>

Button button1(0);

Servo leftArmServo,torsoServo, tiltServo, panServo, rightArmServo;  // Create a Servo object

// positions of the servos
int pos_tilt = 60;
int pos_arm = 60;

// servo movements
int pos_tilt_mov = 1;  // Reduced step size for slower tilt servo movement
int pos_arm_mov = 1;

// servos arm min and max
int pos_arm_min = 10;
int pos_arm_max = 150;

// servos tilt min and max
int pos_tilt_min = 60;
int pos_tilt_max = 70;


int number = 0;
int on_off = 0;

// the setup routine runs once when you press reset:
void setup() {

  tiltServo.attach(10);
  rightArmServo.attach(3);
  Serial.begin(9600);

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

  if (on_off == 0)
  {
    tiltServo.write(60); 
  }

  if (on_off == 1)
  {
    pos_tilt = pos_tilt + pos_tilt_mov;
    pos_arm = pos_arm + pos_arm_mov;
    tiltServo.write(pos_tilt);
    rightArmServo.write(pos_arm);

    if (pos_arm < pos_arm_min || pos_arm > pos_arm_max) {
      pos_arm_mov = -pos_arm_mov; 
    }
    if (pos_tilt < pos_tilt_min || pos_tilt > pos_tilt_max) {
      pos_tilt_mov = -pos_tilt_mov; 
    }
  
  }

  if (on_off == 2)
  {
    tiltServo.write(60); 
  }


  if (on_off == 3)
  {
    pos_tilt = pos_tilt + pos_tilt_mov;
    pos_arm = pos_arm + pos_arm_mov;
    tiltServo.write(pos_tilt);
    rightArmServo.write(pos_arm);

    if (pos_arm < pos_arm_min || pos_arm > pos_arm_max) {
      pos_arm_mov = -pos_arm_mov; 
    }
    if (pos_tilt < pos_tilt_min || pos_tilt > pos_tilt_max) {
      pos_tilt_mov = -pos_tilt_mov; 
    }
  }

  // keeps track of previous state and current state


  // wait for 30 milliseconds to see the dimming effect
  delay(45);
  
}
