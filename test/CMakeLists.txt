cmake_minimum_required(VERSION 3.10)
project(MarkOS_controller_test)

set(CMAKE_ENABLE_EXPORTS true)

add_executable(${PROJECT_NAME}
        main.cpp
        MockTransceiver.h
        ControllerStateTransceiverTest.h
        ControllerStateTransceiverTest.cpp
        MockController.h
        ControllerReceiverTest.cpp
        ControllerReceiverTest.h
        MockReceiver.h
        )


#Link with GoogleTest
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
#Link with GoogleMock
target_link_libraries(${PROJECT_NAME} gmock gmock_main)

target_link_libraries(${PROJECT_NAME} MarkOS_controller)