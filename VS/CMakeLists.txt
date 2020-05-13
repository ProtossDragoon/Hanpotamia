cmake_minimum_required(VERSION 3.15)
project(VS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VS
        C-map.cpp
        C-master.cpp
        C-player.cpp
        C-resource.cpp
        C-unit.cpp
        map.h
        master.h
        player.h
        resource.h
        Test-main.cpp
        unit.h)
