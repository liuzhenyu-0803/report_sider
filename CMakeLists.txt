cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(report_sider VERSION 0.1 LANGUAGES CXX)

# Enable automatic moc, uic and rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt packages
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Concurrent
    Multimedia
    MultimediaWidgets
    Qml
    Quick
    QuickWidgets
    QuickControls2
    Svg
    WebChannel
    WebSockets
    Xml
    XmlPatterns
)

# Source files
# Use glob to automatically include all .cpp files in src directory
file(GLOB_RECURSE SOURCES "src/*")

# Resource files
file(GLOB_RECURSE RESOURCES
    res/*.qrc
)

# Add executable target
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${RESOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/../include/MicroUI
    ${CMAKE_SOURCE_DIR}/../include
    src
)

# Compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    _UNICODE
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Concurrent
    Qt5::Multimedia
    Qt5::MultimediaWidgets
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickWidgets
    Qt5::QuickControls2
    Qt5::Svg
    Qt5::WebChannel
    Qt5::WebSockets
    Qt5::Xml
    Qt5::XmlPatterns

    $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/../lib/debug/x64/MicroUI_Debug_x64.lib>
    $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/../lib/release/x64/MicroUI_Release_x64.lib>
)

# Set properties for the target
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    OUTPUT_NAME "${PROJECT_NAME}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../bin/Debug/x64"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../bin/Release/x64"
)

# 让Release模式下也生成PDB文件（仅MSVC）
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG")
endif()
