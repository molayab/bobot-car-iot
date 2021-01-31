#include <Arduino.h>
#include "kernel/kernel.h"

Bobot* bobot;

void setup() {
  Serial.begin(9600);
  bobot = new Bobot();
}

void loop() {
  while (Serial.available()) {
      bobot->received_byte((uint8_t) Serial.read());
  }
}