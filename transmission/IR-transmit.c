#include <IRremote.h>

const byte buttonPin = 0;  // Button input pin
const byte IRPin = 1;      // IR LED output pin

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);     // Set button pin as input with internal pull-up
  IrSender.begin(IRPin);                // Initialize IR sender on P1 (PB1)
}

void loop() {
  static bool lastButtonState = HIGH;   // Stores the last button state
  bool buttonState = digitalRead(buttonPin); // Reads the current button state

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {           // When button is pressed (LOW state)
      IrSender.sendNEC(0x381, 0xF9, 0); // EPSON projector
      delay(50); // delay

      IrSender.sendNEC(0x1308, 0x87, 0); // Acer prjector
      delay(50); // delay

      IrSender.sendNEC(0x5583, 0x90, 0); //epson universal
      delay(100);		        // Debounce delay
    }
    lastButtonState = buttonState;      // Update the last button state
  }
}