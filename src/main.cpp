#include <Arduino.h>
#include "modules/communication/buffer.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
      auto ss = Serial.read();
  }
}