//
// Created by Oleksandra Baukh on 3/20/18.
//
#include <gmock/gmock.h>
#include "ControllerStateTransceiverTest.h"

using ::testing::Mock;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;

void ControllerStateTransceiverTest::SetUp() {
    Mock::VerifyAndClearExpectations(&mockTransceiver);
    Mock::VerifyAndClearExpectations(&controllerStateTransceiver);
}

TEST_F(ControllerStateTransceiverTest, messageNewControllerState) {
    ControllerState controllerState;
    controllerState.right = true;
    controllerState.a = true;
    EXPECT_CALL(controller, readControllerState()).Times(1)
            .WillOnce(Return(controllerState));
    Message<ControllerState> message{controllerState};
    EXPECT_CALL(mockTransceiver, send(message)).Times(Exactly(1));

    controllerStateTransceiver.onEvent(0);
}

TEST_F(ControllerStateTransceiverTest, doNotMessageTheSameState) {
    ControllerState controllerState;
    controllerState.right = true;
    controllerState.a = true;
    EXPECT_CALL(controller, readControllerState()).Times(2)
            .WillOnce(Return(controllerState))
            .WillOnce(Return(controllerState));
    Message<ControllerState> message{controllerState};
    EXPECT_CALL(mockTransceiver, send(message)).Times(Exactly(1));

    controllerStateTransceiver.onEvent(0);
    controllerStateTransceiver.onEvent(1);
}

TEST_F(ControllerStateTransceiverTest, joystickSensetivity) {
    ControllerState firstState;
    firstState.leftX = 100;
    firstState.leftY = -100;

    ControllerState secondState;
    secondState.leftX = 109;
    secondState.leftY = -91;

    EXPECT_CALL(controller, readControllerState()).Times(2)
            .WillOnce(Return(firstState))
            .WillOnce(Return(secondState));
    Message<ControllerState> message{firstState};
    EXPECT_CALL(mockTransceiver, send(message)).Times(Exactly(1));

    controllerStateTransceiver.onEvent(0);
    controllerStateTransceiver.onEvent(1);
}
