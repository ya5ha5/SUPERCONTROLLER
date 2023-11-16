const int numPots = 6;
const int potPins[] = {A0, A1, A2, A3, A4, A5};

void setup() {
  Serial.begin(9600);

  // Set the analog pins as inputs
  for (int i = 0; i < numPots; i++) {
    pinMode(potPins[i], INPUT);
  }
}

void loop() {
  // Read and print analog values from potentiometers
  for (int i = 0; i < numPots; i++) {
    int potValue = analogRead(potPins[i]);
    Serial.print("Pot ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(potValue);
  }

  // Add a delay to make the Serial Monitor output readable
  delay(500);
}
