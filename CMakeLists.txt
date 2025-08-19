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
    src/views/business_components/Element.h
    src/views/business_components/Element.cpp
    src/views/business_components/ElementFrame.h
    src/views/business_components/ElementFrame.cpp
    src/views/business_components/UnitElement.h
    src/views/business_components/UnitElement.cpp
    src/views/business_components/FieldElement.h
    src/views/business_components/FieldElement.cpp
    src/views/business_components/SystemTrayIcon.h
    src/views/business_components/SystemTrayIcon.cpp
    src/models/ElementModel.h
    src/models/ElementModel.cpp
    src/models/UnitElementModel.h
    src/models/UnitElementModel.cpp
    src/models/FieldElementModel.h
    src/models/FieldElementModel.cpp
    src/models/GroupModel.h
    src/models/GroupModel.cpp
    src/models/Model.h
    src/models/Model.cpp
    src/models/ConfigModel.h
    src/models/ConfigModel.cpp
    res/images.qrc
    res/qss.qrc
    src/views/common_components/SpinBox.h
    src/views/common_components/SpinBox.cpp
    src/views/common_components/InnerTip.h
    src/views/common_components/InnerTip.cpp
    src/views/business_components/ThermalImageIndex.h
    src/views/business_components/ThermalImageIndex.cpp
    src/views/business_components/TabFrame.h
    src/views/business_components/TabFrame.cpp
    src/views/business_components/TabPageFrame.h
    src/views/business_components/TabPageFrame.cpp
    src/views/business_components/GroupFrame.h
    src/views/business_components/GroupFrame.cpp
    src/utility/utility.h
    src/utility/utility.cpp
    src/global/global.h
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
