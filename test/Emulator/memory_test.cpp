#include <gtest/gtest.h>

#include <Memory.hpp>
#include <algorithm>

TEST(MemoryTest, Init) {

}

TEST(MemoryTest, Alias) {

}

TEST(MemoryTest, ReadWrite) {
    Tricore::MemoryRegion region{0xF000, 128};
    constexpr std::array<u8, 32> write_data{
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
        0xFA, 0xAF, 0xEA, 0xAE,
    };

    region.write(write_data, 0xF020);

    std::array<u8, 32> read_data{};
    region.read(read_data, 0xF020);
    ASSERT_TRUE(std::ranges::equal(read_data, write_data));
    ASSERT_EQ(region.read8(0xF028), 0xFA);
    ASSERT_EQ(region.read16(0xF028), 0xAFFA);
    ASSERT_EQ(region.read32(0xF028), 0xAEEAAFFA);

    ASSERT_THROW(region.read8(0xFFFF), Tricore::InvalidMemoryAccess);
    ASSERT_THROW(region.read8(0xF000 + 128), Tricore::InvalidMemoryAccess);
    ASSERT_THROW(region.read8(0xEFFF), Tricore::InvalidMemoryAccess);
}