cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.28)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.28)
endif()

set(PROJECT_NAME "opengl-basic-2D")
set(GLAD_HEADERS "/usr/include/glad")
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/SDL/build")
project(${PROJECT_NAME} VERSION 1.0 DESCRIPTION "OpenGL 2D renderer for basic game!")

find_package(SDL2 REQUIRED)
add_executable(renderer main.cpp glad.c GL.cpp shader.cpp)
target_link_libraries(renderer ${SDL2_LIBRARIES})
include_directories(renderer ${SDL2_INCLUDE_DIRS} ${GLAD_HEADERS})
