//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_CONTROLLERTEST_H
#define MARKOS_MAIN_CONTROLLERTEST_H


#include <gtest/gtest.h>
#include <Controller.h>
#include <ControllerStateTransceiver.h>
#include "MockTransceiver.h"
#include "MockController.h"

class ControllerStateTransceiverTest : public testing::Test {
protected:
    mark_os::communication::MockTransceiver<mark_os::controller::ControllerState> mockTransceiver;
    MockController controller;
    mark_os::controller::ControllerStateTransceiver controllerStateTransceiver{controller, mockTransceiver};

    void SetUp() override;
};


#endif //MARKOS_MAIN_CONTROLLERTEST_H
