cmake_minimum_required(VERSION 3.7.0)

project(flux)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

add_executable(flux
    todo.qrc
    main.cpp
    store.cpp
    dispatcher.cpp
    handlers.cpp
)
 
target_compile_features(flux PRIVATE cxx_std_17)
target_include_directories(flux SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(flux PRIVATE Qt5::Widgets Qt5::Quick Threads::Threads)
