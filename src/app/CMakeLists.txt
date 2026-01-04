qt_add_executable(app
    main.cpp
    qml_type_registration.cpp
)

target_link_libraries(app
    PRIVATE
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::Widgets
    Qt6::Qml
    domain
    ui
)

target_include_directories(app PRIVATE
    ${CMAKE_SOURCE_DIR}/src/domain/include
    ${CMAKE_SOURCE_DIR}/src/ui
)

install(TARGETS app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
