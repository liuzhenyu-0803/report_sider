cmake_minimum_required(VERSION 3.16)
project(report_sider VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(.)
set(PROJECT_SOURCES
    main.cpp
    views/MainWindow.h
    views/MainWindow.cpp
    views/ContentWidget.h
    views/ContentWidget.cpp
    views/FlowLayout.h
    views/FlowLayout.cpp
    views/elements/Element.h
    views/elements/Element.cpp
    models/ImageElementModel.h
    models/ImageElementModel.cpp
    view_models/ImageElementViewModel.h
    view_models/ImageElementViewModel.cpp
)
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
)
