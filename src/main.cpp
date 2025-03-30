#include <Arduino.h>

// Define the pin numbers for the LED and PIR sensor
const int ledpin = 5;           // Pin number for the LED
const int PIRinput = 19;        // Pin number for the PIR sensor

// Variable to store the current state of the PIR sensor
int pirState = LOW;

// Setup function: runs once when the device starts up
void setup() {
  // Set the LED pin as an output
  pinMode(ledpin, OUTPUT);
  // Set the PIR sensor pin as an input
  pinMode(PIRinput, INPUT);
  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
}

// Loop function: runs repeatedly as long as the device is powered on
void loop() {
  // Read the state of the PIR sensor
  const int IP = digitalRead(PIRinput);
  // Delay for stability
  delay(100);
  
  // If motion is detected by the PIR sensor
  if (IP == 1) {
    // Turn on the LED
    digitalWrite(ledpin, HIGH);
    // If this is the first time motion is detected since the last reset
    if (pirState == LOW) {
      // Print "Motion detected!" to the serial monitor
      Serial.println("Motion detected!");
      // Update pirState to indicate motion detection
      pirState = HIGH;
    }
    // Delay for 1 second
    delay(1000);
  } else {
    // If no motion is detected by the PIR sensor
    // Turn off the LED
    digitalWrite(ledpin, LOW);
    // If motion was detected previously
    if (pirState == HIGH) {
      // Print "Motion ended!" to the serial monitor
      Serial.println("Motion ended!");
      // Update pirState to indicate no motion
      pirState = LOW;
    }
    // Delay for 1 second
    delay(1000);
  }
}
