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
    src/views/business_components/element/ElementFrame.h
    src/views/business_components/element/ElementFrame.cpp
    src/views/business_components/element/UnitElement.h
    src/views/business_components/element/UnitElement.cpp
    src/views/business_components/element/FieldElement.h
    src/views/business_components/element/FieldElement.cpp
    src/views/business_components/system_tray_icon/SystemTrayIcon.h
    src/views/business_components/system_tray_icon/SystemTrayIcon.cpp
    res/images.qrc
    res/qss.qrc
    src/views/common_components/SpinBox.h
    src/views/common_components/SpinBox.cpp
    src/views/common_components/InnerTip.h
    src/views/common_components/InnerTip.cpp
    src/views/business_components/thermal_image_index/ThermalImageIndex.h
    src/views/business_components/thermal_image_index/ThermalImageIndex.cpp
    src/views/business_components/tab/TabFrame.h
    src/views/business_components/tab/TabFrame.cpp
    src/views/business_components/tab/TabPageFrame.h
    src/views/business_components/tab/TabPageFrame.cpp
    src/views/business_components/group/GroupFrame.h
    src/views/business_components/group/GroupFrame.cpp
    src/views/business_components/group/UnitGroupFrame.h
    src/views/business_components/group/UnitGroupFrame.cpp
    src/views/business_components/group/FieldGroupFrame.h
    src/views/business_components/group/FieldGroupFrame.cpp
    src/utility/utility.h
    src/utility/utility.cpp
    src/global/global.h
    src/views/business_components/tab/UnitTabPageFrame.h
    src/views/business_components/tab/UnitTabPageFrame.cpp
    src/views/business_components/tab/FieldTabPageFrame.h
    src/views/business_components/tab/FieldTabPageFrame.cpp
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
