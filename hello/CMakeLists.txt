cmake_minimum_required(VERSION 3.16)

project(hello LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download OpenCV builded with MingW on https://github.com/huihut/OpenCV-MinGW-Build/releases
set(OpenCV_DIR "C:/Users/Raphael/opencv-4.5-mingw")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)

add_executable(hello
  main.cpp
)
target_link_libraries(hello PRIVATE Qt${QT_VERSION_MAJOR}::Core ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS hello
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
