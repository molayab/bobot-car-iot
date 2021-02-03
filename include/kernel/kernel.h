#ifndef kernel_h
#define kernel_h
#include "Arduino.h"
#include "modules/communication/communication.h"
#include "modules/commands/power_command.h"
#include "shell.h"

class BobotTask {
public:
    virtual void run() = 0;
};

class Bobot: public Communication::ReceiverProvider { 
public:
    Bobot();
    ~Bobot();
    void received_byte(uint8_t byte); // Received byte; priorize communication.
    void sync(); // Given CPU time to do important stuff.
    /// Schedules a task in order to be performed each CPU cycle, when available.
    void schedule_task(BobotTask* task);
    void set_parser(Parser* parser);
    void register_engine(Engine::configuration_t config);
private:
    Communication::Handler* handler;
    BobotTask* task;
    Parser* parser;
    Engine* engine;
    void receive(Communication::frame_t frame);
};

#endif