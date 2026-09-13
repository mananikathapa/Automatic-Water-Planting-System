#define SENSOR_PIN 2
#define GREEN_LED 4
#define RED_LED 5
#define RELAY_PIN 7

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);
  // Print a header so you know the system has started
  Serial.println("--- Water Detection System Initialized ---");
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN);

  if (sensorValue == LOW) {   // Water detected
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY_PIN, HIGH);
    
    Serial.println("Status: [ WATER DETECTED ] - Relay ON");
  } 
  else {                    // Air detected
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RELAY_PIN, LOW);
    
    Serial.println("Status: [ DRY ] - Relay OFF");
  }

  delay(500); // Wait 0.5 seconds before next reading
}
