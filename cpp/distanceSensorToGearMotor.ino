// Distance sensor to gear motor
// Ethan Greenhouse 
// 11/15/2024

// Define pins for the ultrasonic distance sensor
const int trigPin = 6;       // Trigger pin on the distance sensor
const int echoPin = 7;       // Echo pin on the distance sensor

// Variable to store the measured distance
float distance = 0;

// Define motor driver pins for the right motor
const int AIN1 = 13;         // Control pin 1 for the motor driver
const int AIN2 = 12;         // Control pin 2 for the motor driver
const int PWMA = 11;         // Speed control pin for the motor driver

// Define pin for the on/off switch
int switchPin = 7;           // Pin connected to the switch

// Variable to store the motor speed
int motorSpeed = 0;          // Initialize motor speed to 0

void setup() {
  // Configure pins for the ultrasonic distance sensor
  pinMode(trigPin, OUTPUT);  // Trigger pin will send pulses
  pinMode(echoPin, INPUT);   // Echo pin will read the returning pulse

  // Configure the switch pin with an internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);

  // Configure motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  distance = getDistance();

  // Print the measured distance to the Serial Monitor
  Serial.print(distance);
  Serial.println(" in");     // Add unit "in" to the distance

  // Print the motor speed to the Serial Monitor
  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);

  // If the measured distance is less than 2 inches
  if (distance < 2) {
    spinMotor(100);          // Run the motor at full speed
    delay(1000);             // Wait for 1 second
    spinMotor(0);            // Stop the motor
  }

  // Small delay before the next loop iteration
  delay(50);
}

// Function to measure and return the distance using the HC-SR04 sensor
float getDistance() {
  float echoTime;            // Time for the pulse to bounce back
  float calculatedDistance;  // Distance calculated from echo time

  // Send a 10-microsecond pulse from the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse received at the echo pin
  echoTime = pulseIn(echoPin, HIGH);

  // Calculate distance in inches: echoTime divided by 148 (speed of sound)
  calculatedDistance = echoTime / 148.0;

  // Return the calculated distance
  return calculatedDistance;
}

// Function to control the motor's speed and direction
void spinMotor(int motorSpeed) {
  if (motorSpeed > 0) {
    // Forward direction: AIN1 HIGH, AIN2 LOW
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else if (motorSpeed < 0) {
    // Backward direction: AIN1 LOW, AIN2 HIGH
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } else {
    // Stop the motor: both AIN1 and AIN2 LOW
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }

  // Set the motor speed using PWM (absolute value of motorSpeed)
  analogWrite(PWMA, abs(motorSpeed));
}
