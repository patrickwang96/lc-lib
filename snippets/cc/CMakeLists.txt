cmake_minimum_required(VERSION 3.16)
project(cc_snippets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")

# add_library(ruochen_wheels stopwatch.h stopwatch.cc)
add_executable(ruochen_wheels stopwatch.h stopwatch.cc)
