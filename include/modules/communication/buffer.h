#ifndef buffer_h
#define buffer_h
#include <vector>

namespace Communication {
    class Buffer {
    public:
        Buffer();
        void writeByte(uint8_t byte);
        uint8_t readByte();
        size_t count();
        uint8_t* unsafe_readAll();
        void clear();
    private:
        std::vector<uint8_t> context;
    };
}

#endif