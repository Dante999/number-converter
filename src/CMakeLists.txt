cmake_minimum_required(VERSION 3.10)

project("number-converter")


# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/compiler-warnings.cmake)
set_project_warnings(project_warnings)


add_executable(nconv convert.cpp main.cpp)
target_link_libraries(nconv PRIVATE project_warnings)

