cmake_minimum_required(VERSION 3.29)
project(sdsu)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sdsu
        files/linkedlists.cpp
        files/priorityQueueNHeap.cpp
)


