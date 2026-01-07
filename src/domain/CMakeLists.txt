
add_library(domain
    ${CMAKE_CURRENT_SOURCE_DIR}/src/domain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/domain.hpp
)

target_include_directories(domain PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(domain
    PRIVATE
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::Widgets
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()