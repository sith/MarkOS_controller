//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_MOCKCONTROLLER_H
#define MARKOS_MAIN_MOCKCONTROLLER_H

#include <gmock/gmock.h>
#include <Controller.h>

class MockController : public Controller {
public:
    MOCK_METHOD0(readControllerState,
                 ControllerState());

    MockController(mark_os::communication::Transceiver<ControllerState> &transceiver, uint8 channelId) : Controller(
            transceiver, channelId) {};
};


#endif //MARKOS_MAIN_MOCKCONTROLLER_H
