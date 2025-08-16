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
    src/views/business_components/MainWindow.h
    src/views/business_components/MainWindow.cpp
    src/views/business_components/ContentWidget.h
    src/views/business_components/ContentWidget.cpp
    src/views/common_components/FlowLayout.h
    src/views/common_components/FlowLayout.cpp
    src/views/business_components/elements/Element.h
    src/views/business_components/elements/Element.cpp
    src/views/business_components/elements/ImageElement.h
    src/views/business_components/elements/ImageElement.cpp
    src/views/business_components/elements/HtmlElement.h
    src/views/business_components/elements/HtmlElement.cpp
    src/views/business_components/elements/UrlsElement.h
    src/views/business_components/elements/UrlsElement.cpp
    src/views/business_components/SystemTrayIcon.h
    src/views/business_components/SystemTrayIcon.cpp
    src/models/ElementModel.h
    src/models/ElementModel.cpp
    src/models/ImageElementModel.h
    src/models/ImageElementModel.cpp
    src/models/HtmlElementModel.h
    src/models/HtmlElementModel.cpp
    src/models/UrlsElementModel.h
    src/models/UrlsElementModel.cpp
    src/view_models/ElementViewModel.h
    src/view_models/ElementViewModel.cpp
    src/view_models/ImageElementViewModel.h
    src/view_models/ImageElementViewModel.cpp
    src/view_models/HtmlElementViewModel.h
    src/view_models/HtmlElementViewModel.cpp
    src/view_models/UrlsElementViewModel.h
    src/view_models/UrlsElementViewModel.cpp
    res/images.qrc
    res/qss.qrc
    src/views/common_components/SpinBox.h
    src/views/common_components/SpinBox.cpp
    src/views/business_components/ThermalImageIndex.h
    src/views/business_components/ThermalImageIndex.cpp
    src/views/business_components/TabFrame.h
    src/views/business_components/TabFrame.cpp
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
