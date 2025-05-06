cmake_minimum_required(VERSION 3.14)

project(
  tricore-emu
  VERSION 0.1.0
  DESCRIPTION "Tricore emulator"
  LANGUAGES C CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not supported")
endif()

option(ENABLE_SANITIZERS "Enable compiler sanitizers" OFF)

# ---- Declare dependencies ----

include(cmake/flags.cmake)

find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(lib/emulator)

# ---- Declare executable ----

add_executable(tricore-emu source/main.cpp)

target_compile_features(tricore-emu PRIVATE cxx_std_20)

target_link_libraries(tricore-emu PRIVATE emulator spdlog::spdlog)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()
