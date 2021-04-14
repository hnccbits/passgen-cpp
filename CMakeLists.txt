cmake_minimum_required(VERSION 3.13)

project(passgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(passgen ${PROJECT_SOURCE_DIR}/src/main.cpp)


