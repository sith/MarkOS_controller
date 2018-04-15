cmake_minimum_required(VERSION 3.10)
project(MarkOS_controller)

add_library(${PROJECT_NAME}
        src/Controller.h
        src/ControllerState.h
        src/ControllerStateReceiver.cpp
        src/ControllerStateReceiver.h
        src/ControllerStateTransceiver.cpp
        src/ControllerStateTransceiver.h
        src/Environment.h
        src/Environment.cpp src/JoystickToleranceAwareController.cpp src/JoystickToleranceAwareController.h)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_communication)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/libs/MarkOS/controller")