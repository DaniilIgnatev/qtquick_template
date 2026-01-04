cmake_minimum_required(VERSION 3.27)

# Optionally enable testing (default ON)
option(BUILD_TESTING "Enable testing" ON)

if(BUILD_TESTING)
    enable_testing()
endif()

project(qtquick_template VERSION 1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt setup
find_package(Qt6 REQUIRED COMPONENTS QML)
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS QuickWidgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS QuickTest)
qt_standard_project_setup(REQUIRES 6.8.5)

add_subdirectory(src)
add_subdirectory(tests)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an explicit, fixed bundle identifier manually though.
# explicit, fixed bundle identifier manually though.
set_target_properties(app PROPERTIES

    # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Packaging support
include(CPackConfig.cmake)
