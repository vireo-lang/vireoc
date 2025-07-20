cmake_minimum_required(VERSION 3.0)

project(vireoc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(vireoc Vireo.cpp)

target_include_directories(vireoc PRIVATE ${CMAKE_SOURCE_DIR}/extern/include/)

install(TARGETS vireoc RUNTIME DESTINATION bin)
