cmake_minimum_required(VERSION 3.10)
project(calculator CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SRC_DIR src)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cc)

add_executable(OMS ${SRC_FILES})
target_include_directories(OMS PRIVATE ${SRC_DIR})
target_link_libraries(OMS Qt5::Widgets)

