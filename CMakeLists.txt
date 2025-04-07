cmake_minimum_required(VERSION 3.5)

project(GuiTextComparator)

# Find required Qt packages
find_package(Qt5 REQUIRED COMPONENTS Widgets Core)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automoc
set(CMAKE_AUTOMOC ON)

# Add executable
add_executable(GuiTextComparator
    main.cpp
    TextComparator.h
    TextComparator.cpp
)

# Link Qt libraries
target_link_libraries(GuiTextComparator
    Qt5::Widgets
    Qt5::Core
)

# Include current directory
target_include_directories(GuiTextComparator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
