cmake_minimum_required(VERSION 3.16)

qt_add_library(ui STATIC)
qt_add_qml_module(ui
    URI ui
    RESOURCE_PREFIX qml
    QML_FILES
        QuickWidgetTab.qml
        QuickViewTab.qml
)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()