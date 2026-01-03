add_test(
    NAME ui_tests
    COMMAND Qt6::qmltestrunner
    -import ${CMAKE_CURRENT_BINARY_DIR}
)