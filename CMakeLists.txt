# 3.13 changes target_sources() to take paths relative to CURRENT_SOURCE_DIR
cmake_minimum_required(VERSION 3.13.0)

# General Compilation Flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Aero VERSION 0.1 LANGUAGES CXX)

include_directories("src/")
include_directories("external/")

add_subdirectory("src")
add_subdirectory("test")

add_subdirectory("external/fmt")
add_subdirectory("external/spdlog")
add_subdirectory("external/googletest")
