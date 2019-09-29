#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   // tell the RedBoard what pins are connected to the display


const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor
const int PWMB = 10;
const int BIN1 = 9;
const int BIN2 = 8;
int motorSpeed = 255;       //starting speed for the motor
int switchPin = 7;

//void spinMotorR(int motorSpeed);
//void spinMotorL(int motorSpeed);
//void straight(int motorSpeed);
//void left(int motorSpeed);
//void right(int motorSpeed);

int incoming = 0;

void setup() {
  // put your setup code here, to run once:
  //set the motor control pins as outputs
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display

  
  
  Serial.begin(9600);                       //begin serial communication with the computer  
}

void loop() {
//  // put your main code here, to run repeatedly:
//  
 if (Serial.available() > 0){          //if the user has entered something in the serial monitor
    incoming = Serial.parseInt();
   
//    Serial.print("Going ");      //print the speed that the motor is set to run at
 }

    
  if (incoming == 1){
//    Serial.println("Straight");
    drive(motorSpeed, motorSpeed);
    delay(2000);
  }else if( incoming == 2){
//    Serial.println("Left");
    drive(0, motorSpeed);
    delay(1000);
  }else if(incoming == 3){
//    Serial.println("Right");
    drive(motorSpeed, 0);
    delay(1000);
  }else if(incoming == 4){
//    Serial.println("Backwards");
    drive(-motorSpeed, -motorSpeed);
    delay(2000);
  }else{
    drive(0, 0);
  }
  writeDisplay("Hello");
}


void writeDisplay(String DisplayString){
    lcd.setCursor(0,0);               //set the cursor to the 0,0 position (top left corner)
    lcd.print(DisplayString);       //print hello, world! starting at that position
    lcd.setCursor(0,1);               //move the cursor to the first space of the bottom row
    lcd.print(millis()/1000);         //print the number of seconds that have passed since the last reset

}


void drive(int leftSpeed, int rightSpeed) {
  spinMotorL(leftSpeed);
  spinMotorR(rightSpeed);
}


void spinMotorL(int motorSpeed)                       //function for driving the right motor
{
  if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(AIN1, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMA, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
}

void spinMotorR(int motorSpeed){
   if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(BIN1, HIGH);                         //set pin 1 to high
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed));   
}
