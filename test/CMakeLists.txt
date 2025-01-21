# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(corniceTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(GTest REQUIRED)
include(GoogleTest)

# ---- Tests ----

add_executable(
  tricore_emu_test
  source/elf_test.cpp
  source/memory_test.cpp
)
target_link_libraries(
  tricore_emu_test PRIVATE
  tricore_emu_lib
  GTest::gtest_main
)
target_compile_features(tricore_emu_test PRIVATE cxx_std_20)

gtest_discover_tests(tricore_emu_test)

# ---- End-of-file commands ----

add_folders(Test)
