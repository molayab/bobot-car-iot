#include "modules/communication/communication.h"
using namespace Communication;

Buffer::Buffer() { 
    context = std::vector<uint8_t>();
}

void Buffer::writeByte(uint8_t byte) {
    context.push_back(byte);
}

uint8_t Buffer::readByte() {
    auto value = context[0];
    context.erase(context.begin());
    return value;
}

size_t Buffer::count() {
    return context.size();
}

uint8_t* Buffer::unsafe_readAll() {
    /**
     * This pointer is only valid as long as the vector is not reallocated. 
     * Reallocation happens automatically if you insert more elements than will fit 
     * in the vector's remaining capacity (that is, if v.size() + NumberOfNewElements > v.capacity(). 
     * You can use v.reserve(NewCapacity) to ensure the vector has a capacity of at least NewCapacity.
     * 
     * Also remember that when the vector gets destroyed, the underlying array gets deleted as well.
     * */
    return &context[0];
}

void Buffer::clear() {
    context.clear();
}