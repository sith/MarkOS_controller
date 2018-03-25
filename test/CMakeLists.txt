
add_executable(controller_test
        main.cpp
        MockTransceiver.h
        ControllerStateTransceiverTest.h
        ControllerStateTransceiverTest.cpp
        MockController.h
        ControllerReceiverTest.cpp ControllerReceiverTest.h)


#Link with GoogleTest
target_link_libraries(controller_test gtest gtest_main)
#Link with GoogleMock
target_link_libraries(controller_test gmock gmock_main)

target_link_libraries(controller_test MarkOS_controller)