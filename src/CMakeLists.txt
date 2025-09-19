add_subdirectory(emulator)

add_executable(tricore-emu main.cpp)

target_link_libraries(tricore-emu PRIVATE emulator spdlog::spdlog)