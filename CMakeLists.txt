cmake_minimum_required(VERSION 3.14)
project(deepbindexample C)

add_executable(main_works main.c)
add_executable(main_fails main.c)
target_compile_definitions(main_fails PRIVATE USE_DEEPBIND)
target_link_libraries(main_works dl)
target_link_libraries(main_fails dl)

add_library(deepbind SHARED deepbindlib.c)
target_compile_options(deepbind PRIVATE -fno-builtin)
add_library(preload SHARED preload.c)


enable_testing()

add_test(NAME main_works COMMAND main_works)
set_tests_properties(main_works PROPERTIES ENVIRONMENT LD_PRELOAD=./libpreload.so)
add_test(NAME main_fails COMMAND main_fails)
set_tests_properties(main_works PROPERTIES ENVIRONMENT LD_PRELOAD=./libpreload.so)
