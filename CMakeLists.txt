cmake_minimum_required(VERSION 3.26)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(data_structures)

add_executable(data_structures
        data_structures/Lista/List.h
        data_structures/Lista/Linked_List.h
        data_structures/Lista/Linked_List.h
        data_structures/Pila/ProvaStack.cpp
        data_structures/Pila/Stack_Vector.h
        data_structures/Coda/Queue_Vector.h
)
