cmake_minimum_required(VERSION "3.17.2")

project("v1.0")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable("${PROJECT_NAME}" "Main.cpp")
