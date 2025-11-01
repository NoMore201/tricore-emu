# ---- Setup compiler flags ----

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/sdl /guard:cf /utf-8 /diagnostics:caret /w14165)
  add_compile_options(/w44242 /w44254 /w44263 /w34265 /w34287 /w44296)
  add_compile_options(/w44365 /w44388 /w44464 /w14545 /w14546 /w14547)
  add_compile_options(/w14549 /w14555 /w34619 /w34640 /w24826 /w14905)
  add_compile_options(/w14906 /w14928 /w45038 /W4 /permissive- /volatile:iso)
else()
  add_compile_definitions(_GLIBCXX_ASSERTIONS)
  add_compile_definitions($<$<CONFIG:RelWithDebInfo>:_FORTIFY_SOURCE=3>)
  add_compile_definitions($<$<CONFIG:Release>:_FORTIFY_SOURCE=3>)
  add_compile_options(-fstack-clash-protection -fstack-protector-strong)
  add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)
  add_compile_options(-Wsign-conversion -Wcast-qual -Wformat=2 -Wundef
                      -Werror=float-equal)
  add_compile_options(-Wshadow -Wcast-align -Wunused -Wnull-dereference
                      -Wdouble-promotion)
  add_compile_options(-Wimplicit-fallthrough -Wextra-semi -Woverloaded-virtual
                      -Wnon-virtual-dtor -Wold-style-cast)
endif()

# ---- Configure Sanitizer support ----

if(ENABLE_SANITIZERS)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/fsanitize=address)
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls)
    add_link_options(-fsanitize=address,undefined)
  endif()
endif()