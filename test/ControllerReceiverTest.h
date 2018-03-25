//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_CONTROLLERRECEIVERTEST_H
#define MARKOS_MAIN_CONTROLLERRECEIVERTEST_H


#include <gtest/gtest.h>
#include <ControllerReceiver.h>
#include "MockReceiver.h"

using mark_os::controller::ControllerState;
using mark_os::communication::Receiver;


class ControllerReceiverTest : public testing::Test {
protected:

    mark_os::communication::MockReceiver<ControllerState> mockReceiver;
    mark_os::controller::ControllerReceiver controllerReceiver{mockReceiver};

    void SetUp() override;

};


#endif //MARKOS_MAIN_CONTROLLERRECEIVERTEST_H
