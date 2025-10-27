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
option(ENABLE_TESTS "Enable unit tests" ON)

# ---- Declare dependencies ----

include(cmake/flags.cmake)

find_package(spdlog CONFIG REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(src)

if(ENABLE_TESTS)
  include(CTest)
  add_subdirectory(test)
endif()
