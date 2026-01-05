qt_add_library(ui STATIC)
qt_add_qml_module(ui
    URI ui
    VERSION 1.0
    RESOURCE_PREFIX qml
    QML_FILES
    RootView.qml
)

# Install the QML module and resources
install(TARGETS ui
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install QML files to the correct location for deployment
install(FILES
    RootView.qml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/qml/ui
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()