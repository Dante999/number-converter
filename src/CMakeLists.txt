#cmake_minimum_required(VERSION 3.10)

#project("number-converter")


# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
#add_library(project_warnings INTERFACE)

# standard compiler warnings
#include(cmake/compiler-warnings.cmake)
#set_project_warnings(project_warnings)



add_library(nconv_lib
    convert.cpp
    number.cpp
    converter.cpp
)

target_include_directories(nconv_lib PUBLIC ../include)

target_link_libraries(nconv_lib 
    PRIVATE project_options 
            project_warnings
)

