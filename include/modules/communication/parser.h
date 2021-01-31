#ifndef parser_h
#define parser_h
#include "communication.h"

namespace Communication {
    class Buffer;
    class Parser {
        frame_type_t get_frame_from_buffer(Buffer* buffer);
    };
}

#endif