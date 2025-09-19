add_executable(
  tricore_emu_test
  bus_test.cpp
  elf_test.cpp
  instruction_test.cpp
  memory_test.cpp)
target_link_libraries(tricore_emu_test PRIVATE emulator GTest::gmock_main)

gtest_discover_tests(tricore_emu_test)