#ifndef buffer_h
#define buffer_h
#include <vector>
#include "communication.h"

namespace Communication {
    class Parser;
    class BufferDelegate {
        virtual void did_receive_frame(frame_type_t frame) = 0;
    };
    class Buffer {
    public:
        Buffer(Parser* parser, BufferDelegate* delegate);
        void writeByte(uint8_t byte);
    
    private:
        std::vector<uint8_t> buffer;
        bool is_recording;
        uint16_t frame_size;
        uint8_t frame_type;
    };
    class Interpreter: public BufferDelegate {
        void execute(frame_type_t frame);
        void did_receive_frame(frame_type_t frame);
    };
}

#endif