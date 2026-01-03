qt_add_qml_test(ui_tests
    QMLTEST_FILES
        tst_ui.qml
)

target_link_libraries(ui_tests
    PRIVATE
    Qt6::QuickTest
)