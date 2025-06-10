// SPDX-License-Identifier: MIT
// Author: ELEKON, s.r.o., Vyškov

#include "unity.h"

#include <string.h>

#include "serde.h"

void test_Serde_BE_UInt64ToBytes(void)
{
    uint8_t data[8] = {0};

    Serde_BE_UInt64ToBytes(data, 0x123456789abcdef0ULL);

    TEST_ASSERT_EQUAL(0x12, data[0]);
    TEST_ASSERT_EQUAL(0x34, data[1]);
    TEST_ASSERT_EQUAL(0x56, data[2]);
    TEST_ASSERT_EQUAL(0x78, data[3]);
    TEST_ASSERT_EQUAL(0x9a, data[4]);
    TEST_ASSERT_EQUAL(0xbc, data[5]);
    TEST_ASSERT_EQUAL(0xde, data[6]);
    TEST_ASSERT_EQUAL(0xf0, data[7]);
}

void test_Serde_BE_UInt32ToBytes(void)
{
    uint8_t data[4] = {0};

    Serde_BE_UInt32ToBytes(data, 0x12345678);

    TEST_ASSERT_EQUAL(0x12, data[0]);
    TEST_ASSERT_EQUAL(0x34, data[1]);
    TEST_ASSERT_EQUAL(0x56, data[2]);
    TEST_ASSERT_EQUAL(0x78, data[3]);
}

void test_Serde_BE_UInt16ToBytes(void)
{
    uint8_t data[2] = {0};

    Serde_BE_UInt16ToBytes(data, 0x1234);

    TEST_ASSERT_EQUAL(0x12, data[0]);
    TEST_ASSERT_EQUAL(0x34, data[1]);
}

void test_Serde_BE_Int64ToBytes(void)
{
    uint8_t data[8] = {0};

    Serde_BE_Int64ToBytes(data, -0x123456789abcdef0ULL);

    TEST_ASSERT_EQUAL(0xed, data[0]);
    TEST_ASSERT_EQUAL(0xcb, data[1]);
    TEST_ASSERT_EQUAL(0xa9, data[2]);
    TEST_ASSERT_EQUAL(0x87, data[3]);
    TEST_ASSERT_EQUAL(0x65, data[4]);
    TEST_ASSERT_EQUAL(0x43, data[5]);
    TEST_ASSERT_EQUAL(0x21, data[6]);
    TEST_ASSERT_EQUAL(0x10, data[7]);
}

void test_Serde_BE_Int32ToBytes(void)
{
    uint8_t data[4] = {0};

    Serde_BE_Int32ToBytes(data, -0x12345678);

    TEST_ASSERT_EQUAL(0xed, data[0]);
    TEST_ASSERT_EQUAL(0xcb, data[1]);
    TEST_ASSERT_EQUAL(0xa9, data[2]);
    TEST_ASSERT_EQUAL(0x88, data[3]);
}

void test_Serde_BE_Int16ToBytes(void)
{
    uint8_t data[2] = {0};

    Serde_BE_Int16ToBytes(data, -0x1234);

    TEST_ASSERT_EQUAL(0xed, data[0]);
    TEST_ASSERT_EQUAL(0xcc, data[1]);
}

void test_Serde_BE_BytesToUInt64(void)
{
    uint8_t data[] = {0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10};

    TEST_ASSERT_EQUAL(0xFEDCBA9876543210ULL, Serde_BE_BytesToUInt64(data));
}

void test_Serde_BE_BytesToUInt32(void)
{
    uint8_t data[] = {0xFE, 0xDC, 0xBA, 0x98};

    TEST_ASSERT_EQUAL(0xFEDCBA98, Serde_BE_BytesToUInt32(data));
}

void test_Serde_BE_BytesToUInt16(void)
{
    uint8_t data[] = {0xFE, 0xDC};

    TEST_ASSERT_EQUAL(0xFEDC, Serde_BE_BytesToUInt16(data));
}

void test_Serde_BE_BytesToInt64(void)
{
    uint8_t data[] = {0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10};

    TEST_ASSERT_EQUAL(-81985529216486896LL, Serde_BE_BytesToInt64(data));
}

void test_Serde_BE_BytesToInt32(void)
{
    uint8_t data[] = {0xFE, 0xDC, 0xBA, 0x98};

    TEST_ASSERT_EQUAL(-19088744, Serde_BE_BytesToInt32(data));
}

void test_Serde_BE_BytesToInt16(void)
{
    uint8_t data[] = {0xFE, 0xDC};

    TEST_ASSERT_EQUAL(-292, Serde_BE_BytesToInt16(data));
}

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

int runUnityTests(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Serde_BE_UInt64ToBytes);
    RUN_TEST(test_Serde_BE_UInt32ToBytes);
    RUN_TEST(test_Serde_BE_UInt16ToBytes);

    RUN_TEST(test_Serde_BE_Int64ToBytes);
    RUN_TEST(test_Serde_BE_Int32ToBytes);
    RUN_TEST(test_Serde_BE_Int16ToBytes);

    RUN_TEST(test_Serde_BE_BytesToUInt64);
    RUN_TEST(test_Serde_BE_BytesToUInt32);
    RUN_TEST(test_Serde_BE_BytesToUInt16);

    RUN_TEST(test_Serde_BE_BytesToInt64);
    RUN_TEST(test_Serde_BE_BytesToInt32);
    RUN_TEST(test_Serde_BE_BytesToInt16);

    return UNITY_END();
}

int main(void)
{
    return runUnityTests();
}
