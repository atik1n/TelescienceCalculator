cmake_minimum_required(VERSION 3.15)
project(course_console)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
set(SFML_ROOT M:/Programming/ICST/CPP/SFML-2.5.1)
set(TELE_CPPS telescience/calculator.cpp telescience/calibrator.cpp telescience/data.cpp)
set(GUI_CPPS gui/helpers.cpp gui/calculator.cpp)

find_package(SFML REQUIRED system window graphics network audio)

add_executable(console telescience-console.cpp ${TELE_CPPS})
add_executable(gui telescience-gui.cpp ${TELE_CPPS} ${GUI_CPPS})

if(SFML_FOUND)
    include_directories(${CMAKE_CURRENT_LIST_DIR} ${SFML_INCLUDE_DIR})
    target_link_libraries(gui ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
