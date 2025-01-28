cmake_minimum_required(VERSION 3.14)

project(
  tricore_emu
  VERSION 0.1.0
  DESCRIPTION "Custom emulator for AURIX Tricore TC-3X series, written in C++"
  HOMEPAGE_URL "https://example.com/"
  LANGUAGES CXX
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not supported")
endif()

option(BUILD_DOXYGEN_DOCS "Build documentation using Doxygen and m.css" OFF)
option(ENABLE_SANITIZERS "Enable compiler sanitizers" OFF)

# ---- Setup compiler flags ----

if (MSVC)
  add_compile_options(/sdl /guard:cf /utf-8 /diagnostics:caret /w14165)
  add_compile_options(/w44242 /w44254 /w44263 /w34265 /w34287 /w44296)
  add_compile_options(/w44365 /w44388 /w44464 /w14545 /w14546 /w14547) 
  add_compile_options(/w14549 /w14555 /w34619 /w34640 /w24826 /w14905)
  add_compile_options(/w14906 /w14928 /w45038 /W4 /permissive- /volatile:iso)
  if(ENABLE_SANITIZERS)
    add_compile_options(/fsanitize=address)
  endif()
else()
  add_compile_definitions($<$<CONFIG:Debug>:_GLIBCXX_ASSERTIONS=1>)
  add_compile_definitions($<$<CONFIG:RelWithDebInfo>:_FORTIFY_SOURCE=3>)
  add_compile_definitions($<$<CONFIG:Release>:_FORTIFY_SOURCE=3>)
  add_compile_options(-fstack-clash-protection -Wall -Wextra -Wpedantic -Wconversion)
  add_compile_options(-Wsign-conversion -Wcast-qual -Wformat=2 -Wundef -Werror=float-equal)
  add_compile_options(-Wshadow -Wcast-align -Wunused -Wnull-dereference -Wdouble-promotion)
  add_compile_options(-Wimplicit-fallthrough -Wextra-semi -Woverloaded-virtual -Wnon-virtual-dtor -Wold-style-cast)

endif()

# ---- Declare library ----

add_library(
  tricore_emu_lib
  OBJECT
  source/Cpu.cpp
  source/Elf.cpp
  source/Tc33x.cpp
  source/Memory.cpp
)

target_include_directories(tricore_emu_lib PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>")

target_compile_features(tricore_emu_lib PUBLIC cxx_std_20)

find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(tricore_emu_lib PUBLIC Microsoft.GSL::GSL fmt::fmt)

# ---- Declare executable ----

add_executable(tricore_emu_exe source/main.cpp)
add_executable(tricore_emu::exe ALIAS tricore_emu_exe)

set_property(TARGET tricore_emu_exe PROPERTY OUTPUT_NAME tricore_emu)

target_compile_features(tricore_emu_exe PRIVATE cxx_std_20)

target_link_libraries(tricore_emu_exe PRIVATE tricore_emu_lib)

include(cmake/folders.cmake)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

if(BUILD_DOXYGEN_DOCS)
  include(cmake/docs.cmake)
endif()

add_folders(Project)
