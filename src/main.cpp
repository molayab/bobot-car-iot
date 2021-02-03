#include "kernel/kernel.h"

Bobot* bobot;

class ExampleTask: public BobotTask {
  void run() {
    // Do stuff...
  }
};

void setup() {
  Serial.begin(9600);
  auto exampleTask = new ExampleTask();
  bobot = new Bobot();
  /**
   * Schedule a task to run after comm each clock cycle
   */
  bobot->schedule_task(exampleTask);
  /**
   * Pins used to control engine module:
   * pin 6 => pwm m1
   * pin 5 => pwm m2
   * pin 13 => m1
   * pin 12 => m1
   * pin 8 => m2
   * pin 7 => m2
   */
  bobot->register_engine((Engine::configuration_t){6, 5, 13, 12, 8, 7});
  // Register a new shell that exposes API that controls this device.
  bobot->set_shell(new Shell());
}

void loop() {
  // Do first comm.
  while (Serial.available() > 0) {
      bobot->received_byte((uint8_t)Serial.read());
  }
  // Give some time to the opt task, if it's present.
  bobot->sync();
}