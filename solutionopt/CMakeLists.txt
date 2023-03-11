cmake_minimum_required(VERSION 3.14)
project(deepbindexample C)

add_compile_options(-ffunction-sections)

add_executable(main main.c)
target_link_libraries(main dl)

add_library(deepbind SHARED deepbindlib.c)
target_compile_options(deepbind PRIVATE -fno-builtin)

add_library(lib SHARED lib.c)
target_link_libraries(deepbind lib)
target_link_libraries(main lib)

add_library(preload SHARED preload.c)