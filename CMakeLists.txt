cmake_minimum_required(VERSION 3.13)
project(passgen LANGUAGES CXX)
set(passgen_VERSION_MAJOR 1)
set(passgen_VERSION_MINOR 0)
set(passgen_VERSION_REVISION 0)
set(CMAKE_CXX_STANDARD 17)
configure_file(${PROJECT_SOURCE_DIR}/src/version.h.in ${PROJECT_BINARY_DIR}/src/version.h)
add_executable(passgen ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/engine.cpp)
target_include_directories(passgen PUBLIC "${PROJECT_BINARY_DIR}/src/")
install(TARGETS passgen DESTINATION bin/)
