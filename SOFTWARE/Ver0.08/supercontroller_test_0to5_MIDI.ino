#include "MIDIUSB.h"

const int numPots = 5;
const int potPins[] = {A0, A1, A2, A3, A4};

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup() {
  Serial.begin(115200);

  // Set the analog pins as inputs
  for (int i = 0; i < numPots; i++) {
    pinMode(potPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < numPots; i++) {
    // Read the analog value from the potentiometer
    int potValue = analogRead(potPins[i]);

    // Map the pot value (0-1023) to the CC value range (0-127)
    byte ccValue = map(potValue, 0, 1023, 0, 127);

    // Send the Control Change message over MIDI USB
    controlChange(0, i, ccValue);

    // Print values to Serial Monitor (optional)
    Serial.print("Pot ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(ccValue);
  }

  // Delay to avoid flooding MIDI with messages
  delay(10);
}
