
add_executable(test_domain test_domain.cpp)

target_link_libraries(test_domain PRIVATE domain Qt6::Test)

add_test(NAME test_domain COMMAND test_domain)
