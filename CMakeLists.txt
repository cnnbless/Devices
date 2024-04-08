cmake_minimum_required(VERSION 3.26)
project(Devices)

set(CMAKE_CXX_STANDARD 17)

add_executable(Devices main.cpp
        Keyboard.cpp
        Keyboard.h
        Mouse.cpp
        Mouse.h
        Headphones.cpp
        Headphones.h
        MechanicKeyboard.cpp
        MechanicKeyboard.h
        InEarHeadphones.cpp
        InEarHeadphones.h
        GamingMouse.cpp
        GamingMouse.h
        Printable.cpp
        Printable.h
        User.cpp
        User.h
        Functions.cpp
        Functions.h
        Admin.cpp
        Admin.h)
