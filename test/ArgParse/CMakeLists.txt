add_executable(
  argparse_test
  parsed_options_test.cpp
  argparse_test.cpp)
target_link_libraries(argparse_test PRIVATE GTest::gmock_main ArgParse)

gtest_discover_tests(argparse_test)