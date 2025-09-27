#include <LiquidCrystal.h>  // load liquid crystal library
LiquidCrystal LCD(11,10,9,2,3,4,5); // create liquid crystal object called LCD

#define trigPin 13  // sensor echo pin connected to Arduino pin 13
#define echoPin 12  // sensor trip pin connected to Arduino pin 12



void setup() 
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  LCD.begin(16,2);  // tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0); // set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Target Distance:");  // print message on first row
}

void loop() {
  long duration, distance;  // variables to store time (microseconds) and calculated distance (cm)
  //  send a short LOW-HIGH-LOW pulse on trigger pin to start measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // keep it HIGH for 10 microseconds
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH);  // measure the time it takes for the echo pulse to return
  
  distance = (duration/2) / 29.1; // convert time into distance, speed of sound = 343 m/s ~ 29.1 microseconds per cm, divide by 2 for one-way distance


  LCD.setCursor(0,1);  // set cursor to first column of second row
  LCD.print("                "); // print blanks to clear the row
  LCD.setCursor(0,1);   // set cursor again to first column of second row
  LCD.print(distance); // print measured distance
  LCD.print(" cm");  // print your units
  delay(250); // pause to let things settle
}

