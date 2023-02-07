cmake_minimum_required(VERSION 3.15)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arkanoid main.cpp orb.cpp orb.h paddle.cpp paddle.h obstacles.cpp obstacles.h menu.cpp menu.h start.cpp start.h score.cpp score.h scoreboard.cpp scoreboard.h)

# Detect and add SFML
set(SFML_PATH "C:/Users/Arosl/Desktop/C++/ppo/Projekt_1/solutions/Arkanoid/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(Arkanoid sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()