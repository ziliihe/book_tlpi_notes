file(GLOB _sources ./*.c ./*.h ./ename.c.inc)

add_library(tlpi STATIC ${_sources})

target_include_directories(tlpi PUBLIC .)
