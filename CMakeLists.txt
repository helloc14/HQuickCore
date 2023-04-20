cmake_minimum_required(VERSION 3.16)

project(HQuickCore LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

file(GLOB_RECURSE SRC_DIR_LIST "./*.cpp" "./*.c" "./*.h" "./*.hpp")
add_library(HQuickCore SHARED
  ${SRC_DIR_LIST}
)

target_link_libraries(HQuickCore PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(HQuickCore PRIVATE HQUICK_LIBRARY)
