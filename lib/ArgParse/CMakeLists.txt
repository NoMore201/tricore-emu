add_library(ArgParse STATIC 
ArgumentParser.cpp)

target_include_directories(ArgParse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})