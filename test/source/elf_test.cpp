#include <gtest/gtest.h>

#include <Elf.hpp>

#include <fstream>

TEST(ElfParsingTest, FileNotFoundError) {
    Tricore::Elf file;
    auto result = file.parse_file("/path/to/nonexisting/file");
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), Tricore::Elf::Error::ReadError);
}

TEST(ElfParsingTest, NotElfFormatError) {
    constexpr const char *local_file_path = "./local-file.elf";

    auto file_stream = std::ofstream(local_file_path);
    EXPECT_TRUE(file_stream.good());
    file_stream << "\x12\x34\x56\x78";
    file_stream.close();
    Tricore::Elf file;
    auto result = file.parse_file(local_file_path);
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), Tricore::Elf::Error::InvalidFile);
}