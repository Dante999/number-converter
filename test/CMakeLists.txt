add_executable(unit-tests
    converter_test.cpp
)


target_link_libraries(unit-tests
    PRIVATE project_options
            project_warnings
            CONAN_PKG::gtest
            nconv_lib
)
