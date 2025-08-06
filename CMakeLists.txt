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
include_directories(src)
set(PROJECT_SOURCES
    src/main.cpp
    src/views/MainWindow.h
    src/views/MainWindow.cpp
    src/views/ContentWidget.h
    src/views/ContentWidget.cpp
    src/views/FlowLayout.h
    src/views/FlowLayout.cpp
    src/views/elements/Element.h
    src/views/elements/Element.cpp
    src/views/elements/ImageElement.h
    src/views/elements/ImageElement.cpp
    src/views/elements/HtmlElement.h
    src/views/elements/HtmlElement.cpp
    src/models/ElementModel.h
    src/models/ElementModel.cpp
    src/models/ImageElementModel.h
    src/models/ImageElementModel.cpp
    src/models/HtmlElementModel.h
    src/models/HtmlElementModel.cpp
    src/view_models/ElementViewModel.h
    src/view_models/ElementViewModel.cpp
    src/view_models/ImageElementViewModel.h
    src/view_models/ImageElementViewModel.cpp
    src/view_models/HtmlElementViewModel.h
    src/view_models/HtmlElementViewModel.cpp
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
