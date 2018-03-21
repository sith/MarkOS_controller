cmake_minimum_required(VERSION 3.10)
project(MarkOS_controller)

add_library(${PROJECT_NAME}
        src/Controller.cpp
        src/Controller.h
        src/ControllerState.h)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_communication)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)