add_subdirectory(emulator)

add_executable(tricore-emu main.cpp)

target_compile_features(tricore-emu PRIVATE cxx_std_20)

target_link_libraries(tricore-emu PRIVATE emulator spdlog::spdlog)