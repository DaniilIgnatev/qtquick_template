add_executable(ui_tests test_ui.cpp ${CMAKE_SOURCE_DIR}/src/app/qml_type_registration.cpp)
target_include_directories(ui_tests PRIVATE ${CMAKE_SOURCE_DIR}/src/app)
target_link_libraries(ui_tests PRIVATE Qt6::Test Qt6::Quick Qt6::QuickWidgets Qt6::Widgets Qt6::QuickTest uiplugin domain)
add_test(NAME ui_tests COMMAND ui_tests)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tst_ui.qml ${CMAKE_CURRENT_BINARY_DIR}/tst_ui.qml COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/src/ui/RootView.qml ${CMAKE_CURRENT_BINARY_DIR}/RootView.qml COPYONLY)
set_tests_properties(ui_tests PROPERTIES
    ENVIRONMENT "QML_IMPORT_PATH=${CMAKE_BINARY_DIR}/src/ui;${CMAKE_BINARY_DIR}/src/ui/tests"
)