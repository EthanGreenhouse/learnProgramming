// Distance sensor to servo motor
// Ethan Greenhouse 
// 11/15/2024

// Distance sensor to servo
#include <Servo.h>                // Include the servo library

Servo myServo;                    // Create a servo object

const int trigPin = 11;           // Connects to the trigger pin on the distance sensor
const int echoPin = 12;           // Connects to the echo pin on the distance sensor
float distance = 0;               // Stores the distance measured by the distance sensor

void setup() {
  myServo.attach(9);              // Connects the servo to pin 9 (ensure correct pin number)
  Serial.begin(9600);             // Set up a serial connection with the computer
  pinMode(trigPin, OUTPUT);       // The trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);        // The echo pin will measure the duration of pulses coming back from the distance sensor
  myServo.write(0);               // Set servo position to 0 degrees
}

void loop() {
  distance = getDistance();       // Variable to store the distance measured by the sensor
  Serial.print(distance);         // Print the distance that was measured
  Serial.println(" in");          // Print units after the distance
 
  if (distance > 3) { // Ensure distance is valid and within range
    myServo.write(180);           // Set servo position to 180 degrees when an object is detected
  } else {                        // If the object is out of range
    myServo.write(0);             // Reset the servo to 0 degrees
  }

  delay(1000);                     // Delay 1s between each reading to smooth out readings
}

// RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance() {
  float echoTime;                         // Variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;               // Variable to store the distance calculated from the echo time
 
  // Send out an ultrasonic pulse that's 10 microseconds long
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  echoTime = pulseIn(echoPin, HIGH, 30000);  // Use the pulseIn command with a 30ms timeout
 
  // Check if a valid echo was received
  if (echoTime == 0) {
    return -1;  // Return -1 if no valid echo was detected
  }
 
  // Calculate the distance of the object that reflected the pulse
  calculatedDistance = echoTime / 148.0;     // Distance in inches (for distance in cm, use echoTime / 58.0)
 
  return calculatedDistance;                 // Send back the calculated distance
}
