add_subdirectory(app)
add_subdirectory(domain)
add_subdirectory(ui)

target_link_libraries(app PRIVATE
    uiplugin
)