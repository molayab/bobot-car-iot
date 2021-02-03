#ifndef buffer_h
#define buffer_h
#include <vector>

namespace Communication {
    class Buffer {
    public:
        Buffer();
        void write_byte(uint8_t byte);
        uint8_t read_byte();
        size_t count();
        uint8_t* unsafe_read_all();
        void clear();
    private:
        std::vector<uint8_t> context;
    };
}

#endif