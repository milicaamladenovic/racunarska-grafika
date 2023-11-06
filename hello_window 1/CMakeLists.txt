cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 17)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(glad/)
add_executable(hello_window main.cpp)

target_link_libraries(hello_window glad glfw OpenGL::GL
    pthread X11 Xrandr Xi dl)
