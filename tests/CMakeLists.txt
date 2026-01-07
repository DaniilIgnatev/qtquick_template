
add_executable(test_system test_system.cpp ${CMAKE_SOURCE_DIR}/src/app/qml_type_registration.cpp)
target_include_directories(test_system PRIVATE ${CMAKE_SOURCE_DIR}/src/app)
target_link_libraries(test_system PRIVATE Qt6::Test Qt6::Quick Qt6::QuickWidgets Qt6::Widgets Qt6::QuickTest uiplugin domain)
add_test(NAME test_system COMMAND test_system)
