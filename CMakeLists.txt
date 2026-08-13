cmake_minimum_required(VERSION 3.24)
project(project3)

# Force the project to use modern C++20 for Semaphores
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Direct path to your unzipped SFML folder
set(SFML_DIR "C:/Users/lenovo/Downloads/SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.1.0/lib/cmake/SFML")

# Automatically locate the SFML installation packages
find_package(SFML 3.1 COMPONENTS Graphics Window System REQUIRED)

# Link your code file (Make sure the file name matches Main.cpp exactly)
add_executable(project3 Main.cpp)
target_link_libraries(project3 PRIVATE SFML::Graphics SFML::Window SFML::System)

# Copy the required DLL files automatically so the game can launch
add_custom_command(TARGET project3 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/Users/lenovo/Downloads/SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.1.0/bin"
        $<TARGET_FILE_DIR:project3>
)
