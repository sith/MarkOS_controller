//
// Created by Oleksandra Baukh on 3/20/18.
//

#include "Controller.h"

void Controller::onEvent(unsigned long cycleNumber) {
    auto controllerState = readControllerState();
    if (previousControllerState != controllerState) {
        transceiver->send(channelId, controllerState);
        previousControllerState = controllerState;
    }
}

Controller::Controller(mark_os::communication::Transceiver<ControllerState> &transceiver, uint8 channelId)
        : transceiver(&transceiver), channelId(channelId) {}
