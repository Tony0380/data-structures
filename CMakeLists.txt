cmake_minimum_required(VERSION 3.26)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(data_structures)

add_executable(data_structures
        data_structures/Lista/List.h)
