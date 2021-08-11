cmake_minimum_required(VERSION 3.5)

project(Editor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        textedit.cpp
        textedit.hpp
        mainwindow.cpp
        mainwindow.hpp
        resume.cpp
        resume.hpp
        resume.ui
)

add_executable(Editor
    ${PROJECT_SOURCES}
)

target_link_libraries(Editor PRIVATE Qt5::Widgets)
