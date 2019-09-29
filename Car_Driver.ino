#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display


const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int BIN1 = 9;
const int BIN2 = 8;
const int PWMA = 11;            //speed control pin on the motor driver for the right motor
const int PWMB = 10;
int motorSpeed = 255;       //starting speed for the motor
String incoming = "";
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   // tell the RedBoard what pins are connected to the display


void setup() {
  //set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  //Setup LCD
  lcd.begin(16, 2);                 
  lcd.clear();                      

  //begin serial communication with the computer  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){          
    incoming = Serial.readString();
    incoming = incoming.substring(0,incoming.length()-2);
  }
  
  if(incoming.length() <= 1) {
    char inChar = incoming.charAt(0);
    switch(inChar){
      case '1':
        drive(motorSpeed, motorSpeed);
        break;
      case '2':
        drive(0, motorSpeed);
        break;
      case '3':
        drive(motorSpeed, 0);
        break;
      case '4':
        drive(-motorSpeed, -motorSpeed);
        break;
      default:
        drive(0, 0);
        break;
    }
  }else{
    writeDisplay(incoming);
  }

}


void writeDisplay(String DisplayString){
  while(DisplayString.length() < 32) {
    DisplayString += " ";
  }

  lcd.setCursor(0,0);               //set the cursor to the 0,0 position (top left corner)
  lcd.print(DisplayString);       //print hello, world! starting at that position
  String lineTwo = DisplayString.substring(16);
  lcd.setCursor(0,1);               //move the cursor to the first space of the bottom row
  lcd.print(lineTwo); 
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
