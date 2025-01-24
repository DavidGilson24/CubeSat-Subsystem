bool stopLoop = true;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
  Serial.println("Hello, Serial Monitor!");  // Print a message
}

void loop() {
  if (!stopLoop) {
    Serial.println("Reading data...");
    delay(1000);
  }
}