//
// Created by Oleksandra Baukh on 4/10/18.
//

#include "JoystickToleranceAwareControllerTest.h"

using namespace testing;

void JoystickToleranceAwareControllerTest::SetUp() {
    Test::SetUp();
}


TEST_F(JoystickToleranceAwareControllerTest, resetValuesBellowTollerance) {

    mark_os::controller::ControllerState controlState;
    controlState.leftX = 10;
    controlState.leftY = 11;
    controlState.rightX = 12;
    controlState.rightY = 12;
    controlState.a = true;

    EXPECT_CALL(mockController, readControllerState()).Times(Exactly(1)).WillOnce(
            Return(mark_os::commons::optional(controlState)));

    auto actualControllerState = controller.readControllerState();

    ControllerState expectedControllerState;

    expectedControllerState.leftX = 0;
    expectedControllerState.leftY = 0;
    expectedControllerState.rightX = 0;
    expectedControllerState.rightY = 0;
    expectedControllerState.a = true;

    ASSERT_EQ(actualControllerState, mark_os::commons::Optional<ControllerState>(expectedControllerState));
}


