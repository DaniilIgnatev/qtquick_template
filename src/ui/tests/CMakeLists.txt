add_test(
    NAME ui_tests
    COMMAND Qt6::qmltestrunner
    -input ${CMAKE_CURRENT_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)