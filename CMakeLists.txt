cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(tlpi-proj LANGUAGES C)
add_subdirectory(util)

add_executable(copy chapter04/fileio/copy.c)
set_target_properties(copy PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)

target_link_libraries(copy PUBLIC tlpi)