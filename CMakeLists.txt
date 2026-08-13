cmake_minimum_required(VERSION 3.10)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    Code/Main.cpp
    Code/sorting.cpp
    Code/sorting.h
    Code/measure.h
)

add_executable(sorting-app ${SOURCES})

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(sorting-app
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network
)
