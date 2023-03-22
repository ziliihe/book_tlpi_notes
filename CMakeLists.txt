cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(tlpi-proj LANGUAGES C)
add_subdirectory(util)

add_executable(copy fileio/copy.c)
set_target_properties(copy PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)
target_link_libraries(copy PUBLIC tlpi)

add_executable(seek_io fileio/seek_io.c)
set_target_properties(seek_io PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)
target_link_libraries(seek_io PUBLIC tlpi)

add_executable(t_getopt fileio/t_getopt.c)
set_target_properties(t_getopt PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)
target_link_libraries(t_getopt PUBLIC tlpi)

add_executable(tee fileio/tee.c)
set_target_properties(tee PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)

add_executable(bad_exclusive_open fileio/bad_exclusive_open.c)
set_target_properties(bad_exclusive_open PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)
target_link_libraries(bad_exclusive_open PUBLIC tlpi)

add_executable(cp_hole fileio/cp_hole.c)
set_target_properties(cp_hole PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/fileio
)