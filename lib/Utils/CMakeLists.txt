add_library(
    Utils
    INTERFACE
)

target_include_directories(Utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Utils INTERFACE Microsoft.GSL::GSL)