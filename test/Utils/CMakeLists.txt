add_executable(
  utils_test
  bit_ops_test.cpp)
target_link_libraries(utils_test PRIVATE GTest::gmock_main Utils)

gtest_discover_tests(utils_test)