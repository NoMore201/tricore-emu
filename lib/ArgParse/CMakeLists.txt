add_library(ArgParse STATIC 
ArgumentParser.cpp
ParsedOptions.cpp)

target_include_directories(ArgParse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ArgParse PRIVATE Microsoft.GSL::GSL)