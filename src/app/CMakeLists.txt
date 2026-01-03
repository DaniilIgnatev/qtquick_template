qt_add_executable(app
    main.cpp
)

target_link_libraries(app
    PRIVATE
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::Widgets
)

install(TARGETS app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
