//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_MOCKCONTROLLER_H
#define MARKOS_MAIN_MOCKCONTROLLER_H

#include <gmock/gmock.h>
#include <Controller.h>

using mark_os::controller::Controller;
using mark_os::controller::ControllerState;
using mark_os::commons::Optional;

class MockController : public Controller {
public:
    MOCK_METHOD0(readControllerState,
                 Optional<ControllerState>());
};


#endif //MARKOS_MAIN_MOCKCONTROLLER_H
