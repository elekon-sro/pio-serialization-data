// SPDX-License-Identifier: MIT
// Author: ELEKON, s.r.o., Vyškov

#ifndef SERDE_H
#define SERDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Serialize uint64 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
void Serde_BE_UInt64ToBytes(void * buffer, uint64_t value);

/**
 * @brief Serialize uint32 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
void Serde_BE_UInt32ToBytes(void * buffer, uint32_t value);

/**
 * @brief Serialize uint16 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
void Serde_BE_UInt16ToBytes(void * buffer, uint16_t value);

/**
 * @brief Serialize uint64 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
static inline void Serde_BE_Int64ToBytes(void * buffer, int64_t value)
{
    Serde_BE_UInt64ToBytes(buffer, (uint64_t)value);
}

/**
 * @brief Serialize int32 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
static inline void Serde_BE_Int32ToBytes(void * buffer, int32_t value)
{
    Serde_BE_UInt32ToBytes(buffer, (uint32_t)value);
}

/**
 * @brief Serialize int16 value to bytes as big endian number
 *
 * @param buffer
 * @param value
 */
static inline void Serde_BE_Int16ToBytes(void * buffer, int16_t value)
{
    Serde_BE_UInt16ToBytes(buffer, (uint16_t)value);
}


/**
 * @brief Deserialize uint64 from bytes as big endian number
 *
 * @param buffer
 * @return uint64_t
 */
uint64_t Serde_BE_BytesToUInt64(const void * buffer);

/**
 * @brief Deserialize uint32 value from bytes as big endian number
 *
 * @param buffer
 * @return uint32_t
 */
static inline uint32_t Serde_BE_BytesToUInt32(const void * buffer)
{
    const uint8_t * data = buffer;
    return (uint32_t) data[0] << 24 |
           (uint32_t) data[1] << 16 |
           (uint32_t) data[2] << 8 |
           (uint32_t) data[3];
}

/**
 * @brief Deserialize uint32 value from bytes as little endian number
 *
 * @param buffer
 * @return uint32_t
 */
static inline uint32_t Serde_LE_BytesToUInt32(const void * buffer)
{
    const uint8_t * data = buffer;
    return (uint32_t) data[0] |
           (uint32_t) data[1] << 8 |
           (uint32_t) data[2] << 16 |
           (uint32_t) data[3] << 24;
}

/**
 * @brief Deserialize uint16 value from bytes as little endian number
 *
 * @param buffer
 * @return uint16_t
 */
static inline uint16_t Serde_LE_BytesToUInt16(const void * buffer)
{
    const uint8_t * data = buffer;
    return (uint16_t) data[0] |
           (uint16_t) data[1] << 8 ;
}

/**
 * @brief Deserialize uint16 value from bytes as big endian number
 *
 * @param buffer
 * @return uint16_t
 */
static inline uint16_t Serde_BE_BytesToUInt16(const void * buffer)
{
    const uint8_t * data = buffer;
    return data[0] << 8 | data[1];
}

/**
 * @brief Deserialize int64 from bytes as big endian number
 *
 * @param buffer
 * @return int64_t
 */
static inline int64_t Serde_BE_BytesToInt64(const void * buffer)
{
    return (int64_t)Serde_BE_BytesToUInt64(buffer);
}

/**
 * @brief Deserialize int32 from bytes as big endian number
 *
 * @param buffer
 * @return int32_t
 */
static inline int32_t Serde_BE_BytesToInt32(const void * buffer)
{
    return (int32_t)Serde_BE_BytesToUInt32(buffer);
}

/**
 * @brief Deserialize uint16 value from bytes as big endian number
 *
 * @param buffer
 * @return uint16_t
 */
static inline int16_t Serde_BE_BytesToInt16(const void * buffer)
{
    return (int16_t)Serde_BE_BytesToUInt16(buffer);
}

#ifdef __cplusplus
}
#endif

#endif /* SERDE_H */
