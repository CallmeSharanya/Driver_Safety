// Eye Blink Sensor
#define EYE_BLINK_SENSOR_PIN A0

#define MOTOR_PIN 9
#define BEEPER_PIN 8

void setup() {
  pinMode(EYE_BLINK_SENSOR_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BEEPER_PIN, OUTPUT);

  //digitalWrite(MOTOR_PIN, HIGH);  // Assuming HIGH is the default state (motor running)
  //digitalWrite(BEEPER_PIN, LOW);  // Assuming LOW is the default state (beeper off)
}

void loop() {
  // Read the eye blink sensor
  int eyeBlinkSensorValue = digitalRead(EYE_BLINK_SENSOR_PIN);

  // Check if eyes are closed (assuming HIGH signal indicates closed eyes)
  if (eyeBlinkSensorValue == HIGH) {
    // Eyes are closed, stop the motor and turn on the beeper
    digitalWrite(MOTOR_PIN, HIGH);
    digitalWrite(BEEPER_PIN, HIGH);
  } else {
    // Eyes are open, run the motor and turn off the beeper
    digitalWrite(MOTOR_PIN, LOW);
    digitalWrite(BEEPER_PIN, LOW);
  }

  // Add a small delay to avoid rapid readings
  delay(50);
}
