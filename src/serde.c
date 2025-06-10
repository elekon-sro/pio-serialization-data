// SPDX-License-Identifier: MIT
// Author: ELEKON, s.r.o., Vyškov

#include "serde.h"

void Serde_BE_UInt64ToBytes(void * buffer, uint64_t value)
{
    uint8_t * data = buffer;
    data[0] = (value >> 56) & 0xff;
    data[1] = (value >> 48) & 0xff;
    data[2] = (value >> 40) & 0xff;
    data[3] = (value >> 32) & 0xff;
    data[4] = (value >> 24) & 0xff;
    data[5] = (value >> 16) & 0xff;
    data[6] = (value >> 8) & 0xff;
    data[7] = (value >> 0) & 0xff;
}

void Serde_BE_UInt32ToBytes(void * buffer, uint32_t value)
{
    uint8_t * data = buffer;
    data[0] = (value >> 24) & 0xff;
    data[1] = (value >> 16) & 0xff;
    data[2] = (value >> 8) & 0xff;
    data[3] = (value >> 0) & 0xff;
}

void Serde_BE_UInt16ToBytes(void * buffer, uint16_t value)
{
    uint8_t * data = buffer;
    data[0] = (value >> 8) & 0xff;
    data[1] = (value >> 0) & 0xff;
}

uint64_t Serde_BE_BytesToUInt64(const void * buffer)
{
    const uint8_t * bytes = buffer;
    return ((uint64_t) bytes[0] << 56) | ((uint64_t) bytes[1] << 48) | ((uint64_t) bytes[2] << 40) |
            ((uint64_t) bytes[3] << 32) | ((uint64_t) bytes[4] << 24) | ((uint64_t) bytes[5] << 16) |
            ((uint64_t) bytes[6] << 8) | ((uint64_t) bytes[7] << 0);
}