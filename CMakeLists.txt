cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Chip8 VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the executable
add_executable(Chip8 src/chip8.c)

# Link SFML libraries
target_link_libraries(Chip8 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Include SFML directories
include_directories(${SFML_INCLUDE_DIR})
