cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(tlpi-proj LANGUAGES C)
add_subdirectory(util)

add_executable(copy chapter04/fileio/copy.c)
set_target_properties(copy PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)
target_link_libraries(copy PUBLIC tlpi)

add_executable(seek_io chapter04/fileio/seek_io.c)
set_target_properties(seek_io PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)
target_link_libraries(seek_io PUBLIC tlpi)

add_executable(t_getopt chapter04/fileio/t_getopt.c)
set_target_properties(t_getopt PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)
target_link_libraries(t_getopt PUBLIC tlpi)

add_executable(tee chapter04/fileio/tee.c)
set_target_properties(tee PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)

add_executable(cp_hole chapter04/fileio/cp_hole.c)
set_target_properties(cp_hole PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/chapter04/fileio
)