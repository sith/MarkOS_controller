//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_CONTROLLERTEST_H
#define MARKOS_MAIN_CONTROLLERTEST_H


#include <gtest/gtest.h>
#include <Controller.h>
#include "MockTransceiver.h"
#include "MockController.h"

class ControllerTest : public testing::Test {
protected:
    mark_os::communication::MockTransceiver<ControllerState> mockTransceiver;
    uint8 channelId = 77;
    MockController controller{mockTransceiver, channelId};

    void SetUp() override;
};


#endif //MARKOS_MAIN_CONTROLLERTEST_H
