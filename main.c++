// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// For IIC-Cloud computing and IoT
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 07 December 2022
// ---------------------------------------------------------------- //
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0; 
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

#define inechoPin 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define intrigPin 5 //attach pin D3 Arduino to pin Trig of HC-SR04

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// defines variables
long duration; // variable for the duration of sound wave travel
int distance=1; // variable for the distance measurement

long induration; // variable for the duration of sound wave travel
float indistance=1; // variable for the distance measurement
float distanceinmeter;
int a = 1;
float dustbinstatus=0;
int servopos=0;
void setup() {
  // serv
   myservo.attach(9);
myservo.write(10);
servopos=10;

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  lcd.begin(16, 2);
  
  lcd.backlight();
  lcd.clear();
  // myservo.write(20);              // tell servo to go to position in variable 'pos'


  pinMode(intrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(inechoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  lcd.clear();

//Code for inner Ultrasonic

  // Clears the trigPin condition
  digitalWrite(intrigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(intrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(intrigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  induration = pulseIn(inechoPin, HIGH);
  // Calculating the distance
  indistance = 24-( induration * 0.034 / 2); // Speed of sound wave divided by 2 (go and back)
  // Displays t-he distance on the Serial Monitor

  Serial.println(indistance);
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  // lcd.setCursor(0, 0);

  if(indistance>=25){
    indistance=25;
  }

  if(indistance < 0){
    indistance=0;
  }
  
  dustbinstatus= (indistance/25)*100;
  // Serial.println(dustbinstatus);
  
  lcd.print(dustbinstatus);

  // Serial.println(dustbinstatus);


  delay(1000);
if(distance < 30){

      // myservo.write(70);              // tell servo to go to position in variable 'pos'
    for(servopos;servopos<90;servopos++){
      myservo.write(servopos);
      delay(10);
    }

delay(3000);
}
if(distance > 30){

  for(servopos;servopos>10;servopos--){
      myservo.write(servopos);             // tell servo to go to position in variable 'pos'
      delay(10);

  }

}

delay(100);

}