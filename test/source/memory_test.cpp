#include <gtest/gtest.h>

#include <Memory.hpp>

TEST(MemoryTest, Init) {
    Tricore::Memory mem{
        Tricore::Memory::Layout{1024ULL * 1024ULL * 2ULL, 0xC0000000U}};

    EXPECT_EQ(mem.address(), 0xC0000000U);
    EXPECT_EQ(mem.size(), 1024ULL * 1024ULL * 2ULL);
    EXPECT_TRUE(mem.is_address_valid(0xC0001000));
    EXPECT_FALSE(mem.is_address_valid(0xC0200001));
}

TEST(MemoryTest, Alias) {
    Tricore::Memory mem{
        Tricore::Memory::Layout{1024ULL * 1024ULL * 2ULL, 0x80000000U},
        {0xA0000000U}};

    EXPECT_TRUE(mem.is_address_valid(0x80001000));
    EXPECT_TRUE(mem.is_address_valid(0xA0001000));
    EXPECT_FALSE(mem.is_address_valid(0xB0200001));
    EXPECT_FALSE(mem.is_address_valid(0xA0200001));
}

TEST(MemoryTest, ReadWrite) {
    Tricore::Memory mem{
        Tricore::Memory::Layout{1024ULL * 1024ULL * 2ULL, 0x80000000U},
        {0xA0000000U}};

    constexpr u32 address = 0x80000800U;

    const u32 test_input = 0x12345678U;
    u32 test_output{};

    mem.write(reinterpret_cast<const std::byte *>(&test_input), address,
              sizeof(test_input));
    mem.read(reinterpret_cast<std::byte *>(&test_output), address,
             sizeof(test_output));

    EXPECT_EQ(test_input, test_output);
}