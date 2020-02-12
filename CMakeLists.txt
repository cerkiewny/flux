cmake_minimum_required(VERSION 3.7.0)

project(flux)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)

add_executable(flux
    todo.qrc
    main.cpp
    store.cpp
)

target_link_libraries(flux Qt5::Widgets Qt5::Quick)
