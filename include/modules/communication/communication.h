#ifndef communication_h
#define communication_h
#ifndef COMMUNICATION_FRAME_FLAG
#define COMMUNICATION_FRAME_FLAG 0xDF
#endif
#include <Arduino.h>
#ifdef CPPSTL_WRAPPER
#include <ArduinoSTL.h>
#endif
#include "buffer.h"

namespace Communication {
    enum frame_type_t { CONTROL = 0, STREAM };
    struct frame_t {
        frame_type_t type;
        uint16_t data_size;
        uint8_t* data;
    };
    class SenderProvider {
    public:
        virtual void send(uint8_t* bytes, size_t size) = 0;
    };
    class ReceiverProvider {
    public:
        virtual void receive(frame_t frame) = 0;
    };
    class Handler {
    public:
        Handler();
        ~Handler();
        void receive(uint8_t byte);
        void send(uint8_t* bytes, size_t size);
        void set_receiver(ReceiverProvider* receiver_provider);
    private:
        Buffer* buffer;
        SenderProvider* sender_provider;
        ReceiverProvider* receiver_provider;
        bool is_recording;
        uint16_t frame_size;
        uint8_t frame_type;
        void reset();
    };
}

#endif