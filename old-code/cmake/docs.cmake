# ---- Dependencies ----

find_package(Doxygen REQUIRED)

# ---- Declare documentation target ----

set(
    DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/docs"
    CACHE PATH "Path for the generated Doxygen documentation"
)

set(working_dir "${PROJECT_BINARY_DIR}/docs")

configure_file("docs/Doxyfile.in" "${working_dir}/Doxyfile" @ONLY)

add_custom_target(
    docs
    COMMAND "${CMAKE_COMMAND}" -E remove_directory
    "${DOXYGEN_OUTPUT_DIRECTORY}/html"
    "${DOXYGEN_OUTPUT_DIRECTORY}/xml"
    COMMAND Doxygen::doxygen "${working_dir}/Doxyfile"
    COMMENT "Building documentation using Doxygen"
    WORKING_DIRECTORY "${working_dir}"
    VERBATIM
)
