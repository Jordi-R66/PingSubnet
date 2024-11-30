#include "commons.h"

Endian getEndianness(void) {
    const uint16_t testNum = 0xabcd;

    Endian res = ((uint8_t*)&testNum)[0] == 0xab ? BIG : LITTLE;

    return res;
}
