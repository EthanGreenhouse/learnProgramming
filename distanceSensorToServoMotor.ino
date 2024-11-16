// Distance sensor to servo motor
// Ethan Greenhouse 11/15

// Include the library for controlling servos
#include <Servo.h>                

// Create a Servo object to control the servo motor
Servo myServo;                    

// Define pins for the ultrasonic distance sensor
const int trigPin = 11;           // Trigger pin on the distance sensor
const int echoPin = 12;           // Echo pin on the distance sensor

// Variable to store the measured distance
float distance = 0;               

void setup() {
  // Attach the servo motor to pin 9
  myServo.attach(9);              
  // Start serial communication at 9600 baud rate for debugging
  Serial.begin(9600);             
  // Configure the trigger pin as an output
  pinMode(trigPin, OUTPUT);       
  // Configure the echo pin as an input
  pinMode(echoPin, INPUT);        
  // Initialize the servo to 0 degrees
  myServo.write(0);               
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  distance = getDistance();       

  // Print the measured distance to the Serial Monitor
  Serial.print(distance);         
  Serial.println(" in");          

  // Control the servo based on the measured distance
  if (distance > 0 && distance <= 5) { 
    // If an object is detected within 5 inches, move the servo to 180 degrees
    myServo.write(180);           
  } else if (distance > 5) {      
    // If the object is further than 5 inches, reset the servo to 0 degrees
    myServo.write(0);             
  }

  // Add a short delay to smooth out sensor readings
  delay(100);                     
}

// Function to measure and return the distance using the HC-SR04 sensor
float getDistance() {
  float echoTime;                  // Time for the pulse to bounce back
  float calculatedDistance;        // Distance calculated from echo time

  // Send a 10-microsecond pulse from the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse received at the echo pin, with a 30ms timeout
  echoTime = pulseIn(echoPin, HIGH, 30000);  

  // Check if a valid echo was received (no echo means timeout)
  if (echoTime == 0) {             
    return -1;                     // Return -1 to indicate no valid reading
  }

  // Calculate the distance in inches (for cm, divide echoTime by 58.0)
  calculatedDistance = echoTime / 148.0;     

  // Return the calculated distance
  return calculatedDistance;      
}
