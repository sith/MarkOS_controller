//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_CONTROLLER_H
#define MARKOS_MAIN_CONTROLLER_H


#include <CycleListener.h>
#include <Transceiver.h>
#include "ControllerState.h"

class Controller : public CycleListener {
    mark_os::communication::Transceiver<ControllerState> *transceiver;
    uint8 channelId;
    ControllerState previousControllerState;

public:
    Controller(mark_os::communication::Transceiver<ControllerState> &transceiver, uint8 channelId);

    void onEvent(unsigned long cycleNumber) override;

    virtual ControllerState readControllerState()= 0;

};


#endif //MARKOS_MAIN_CONTROLLER_H
