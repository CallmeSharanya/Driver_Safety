#define SENSOR_DIGITAL A0
#define MOTOR_PIN 9
#define BUZZER_ALCOHOL_PIN 8
#define LED 13  // Change this to a different pin if needed

int ALCOHOL_sensor = 3;

unsigned long PREVIOUS_SENSOR_MILLIS;
unsigned long SENSOR_LONG_MILLIS;
bool SENSOR_STATE_LONG_TIME = false;

const int INTERVAL_SENSOR = 50;
unsigned long SENSOR_OUT_DURATION;
unsigned long SENSOR_STATE_PREVIOUS;
unsigned long MIN_SENSOR_DURATION = 3000;
unsigned long CURRENT_MILLIS = millis();

void setup() {
  pinMode(SENSOR_DIGITAL, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUZZER_ALCOHOL_PIN, OUTPUT);
  Serial.begin(9600);

  // Initialize CURRENT_MILLIS in setup
  
}

void readSensorState() {
  if ((CURRENT_MILLIS - PREVIOUS_SENSOR_MILLIS) > INTERVAL_SENSOR) {
    int SENSOR_STATE = digitalRead(SENSOR_DIGITAL);

    if (SENSOR_STATE == LOW && SENSOR_STATE_PREVIOUS == HIGH && !SENSOR_STATE_LONG_TIME) {
      SENSOR_LONG_MILLIS = CURRENT_MILLIS;
      SENSOR_STATE_PREVIOUS = LOW;
      Serial.println("Alcohol detected");
    }

    SENSOR_OUT_DURATION = CURRENT_MILLIS - SENSOR_LONG_MILLIS;

    if (SENSOR_STATE == LOW && !SENSOR_STATE_LONG_TIME && SENSOR_OUT_DURATION >= MIN_SENSOR_DURATION) {
      SENSOR_STATE_LONG_TIME = true;
      digitalWrite(MOTOR_PIN, HIGH);
      Serial.println("Motor stopped");
      // Add further logic if needed
    }
    else
    {
      digitalWrite(MOTOR_PIN, LOW);
    }

    // Add delay if necessary
    // delay(INTERVAL_SENSOR);

    // Update PREVIOUS_SENSOR_MILLIS after reading
    PREVIOUS_SENSOR_MILLIS = CURRENT_MILLIS;
  }
}

void loop() {
  // Read sensor state in the loop
  CURRENT_MILLIS = millis();
  readSensorState();
  // Add other loop logic if needed
}