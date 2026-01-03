
add_executable(test_system test_system.cpp)
target_link_libraries(test_system PRIVATE Qt6::Test Qt6::Quick Qt6::QuickWidgets Qt6::Widgets uiplugin)
add_test(NAME test_system COMMAND test_system)
