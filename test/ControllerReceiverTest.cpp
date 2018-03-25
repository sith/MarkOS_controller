//
// Created by Oleksandra Baukh on 3/25/18.
//

#include "ControllerReceiverTest.h"

using ::testing::Mock;
using ::testing::Exactly;
using ::testing::Return;


void ControllerReceiverTest::SetUp() {
    Mock::VerifyAndClearExpectations(&mockReceiver);
}


TEST_F(ControllerReceiverTest, receiveMessage) {
    Message<ControllerState> message;
    ControllerState expectedControllerState;
    expectedControllerState.leftX = 10;
    expectedControllerState.a = true;

    message.content = expectedControllerState;


    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));

    auto actualControllerState = controllerReceiver.readControllerState();

    ASSERT_EQ(actualControllerState, expectedControllerState);
}

TEST_F(ControllerReceiverTest, receiveInvalidMessage) {
    Message<ControllerState> validMessage;
    ControllerState expectedControllerState;
    expectedControllerState.leftX = 10;
    expectedControllerState.a = true;
    validMessage.content = expectedControllerState;

    Message<ControllerState> invalidMessage;
    invalidMessage.signature = 123;

    EXPECT_CALL(mockReceiver, receive())
            .Times(Exactly(2))
            .WillOnce(Return(mark_os::commons::optional(validMessage)))
            .WillOnce(Return(mark_os::commons::optional(invalidMessage)));

    auto stateFromValidMessage = controllerReceiver.readControllerState();
    ASSERT_EQ(stateFromValidMessage, expectedControllerState);

    auto stateFromInvalidMessage = controllerReceiver.readControllerState();
    ASSERT_EQ(stateFromInvalidMessage, expectedControllerState);
}

TEST_F(ControllerReceiverTest, receiveNoneMessage) {
    Message<ControllerState> validMessage;
    ControllerState expectedControllerState;
    expectedControllerState.leftX = 10;
    expectedControllerState.a = true;
    validMessage.content = expectedControllerState;

    EXPECT_CALL(mockReceiver, receive())
            .Times(Exactly(2))
            .WillOnce(Return(mark_os::commons::optional(validMessage)))
            .WillOnce(Return(mark_os::commons::none<Message<ControllerState>>()));

    auto stateFromValidMessage = controllerReceiver.readControllerState();
    ASSERT_EQ(stateFromValidMessage, expectedControllerState);

    auto stateFromeNoneMessage = controllerReceiver.readControllerState();
    ASSERT_EQ(stateFromeNoneMessage, expectedControllerState);
}
