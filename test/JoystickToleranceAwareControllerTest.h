//
// Created by Oleksandra Baukh on 4/10/18.
//

#ifndef MARKOS_MAIN_JOYSTICKTOLERANCEAWARECONTROLLERTEST_H
#define MARKOS_MAIN_JOYSTICKTOLERANCEAWARECONTROLLERTEST_H


#include <gtest/gtest.h>
#include <JoystickToleranceAwareController.h>
#include "MockController.h"


class JoystickToleranceAwareControllerTest : public ::testing::Test {
protected:

    MockController mockController;
    mark_os::controller::JoystickToleranceAwareController controller{mockController};


    void SetUp() override;

};


#endif //MARKOS_MAIN_JOYSTICKTOLERANCEAWARECONTROLLERTEST_H
