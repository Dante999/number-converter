cmake_minimum_required(VERSION 3.15)

project(nconv CXX)



# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)



# standard compiler warnings
add_library(project_warnings INTERFACE)
include(cmake/compiler-warnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(src)
add_subdirectory(app)
