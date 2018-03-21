//
// Created by Oleksandra Baukh on 3/20/18.
//
#include <gmock/gmock.h>
#include "ControllerTest.h"

using ::testing::Mock;
using ::testing::Exactly;
using ::testing::Return;

void ControllerTest::SetUp() {
    Mock::VerifyAndClearExpectations(&mockTransceiver);
    Mock::VerifyAndClearExpectations(&controller);
}

TEST_F(ControllerTest, messageNewControllerState) {
    ControllerState controllerState;
    controllerState.right = true;
    controllerState.a = true;
    EXPECT_CALL(controller, readControllerState()).Times(1)
            .WillOnce(Return(controllerState));
    EXPECT_CALL(mockTransceiver, send(channelId, controllerState)).Times(Exactly(1));

    controller.onEvent(0);
}

TEST_F(ControllerTest, doNotMessageTheSameState) {
    ControllerState controllerState;
    controllerState.right = true;
    controllerState.a = true;
    EXPECT_CALL(controller, readControllerState()).Times(2)
            .WillOnce(Return(controllerState))
            .WillOnce(Return(controllerState));
    EXPECT_CALL(mockTransceiver, send(channelId, controllerState)).Times(Exactly(1));

    controller.onEvent(0);
    controller.onEvent(1);
}
