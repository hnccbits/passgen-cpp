cmake_minimum_required(VERSION 3.13)
project(passgen VERSION 1.0.0 LANGUAGES CXX)
configure_file(Config.h.in Config.h)
set(CMAKE_CXX_STANDARD 17)

add_executable(passgen ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_include_directories(passgen PUBLIC "${PROJECT_BINARY_DIR}")
