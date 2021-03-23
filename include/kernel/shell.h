#ifndef parser_h
#define parser_h
#include "Arduino.h"

class Engine;
class ShellParser {
public:
    virtual void parse(uint8_t* data, uint16_t size) = 0;
    virtual void register_module(Engine* engine) = 0;
};

class Shell: public ShellParser {
public:
    Shell();
    void register_module(Engine* engine);
    void parse(uint8_t* data, uint16_t size);
private:
    Engine* engine;
};

#endif