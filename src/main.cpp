#include "kernel/kernel.h"

Bobot* bobot;

class ExampleTask: public BobotTask {
  void run() {
    Serial.println("This is a test");
  }
};

void setup() {
  Serial.begin(9600);
  auto exampleTask = new ExampleTask();
  bobot = new Bobot();
  bobot->schedule_task(exampleTask);
}

void loop() {
  while (Serial.available() > 0) {
      bobot->received_byte((uint8_t) Serial.read());
  }
  bobot->sync();
}