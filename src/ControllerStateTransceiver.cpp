//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ControllerStateTransceiver.h"

namespace mark_os {
    namespace controller {
        void ControllerStateTransceiver::onEvent(unsigned long cycleNumber) {
            auto state = controller->readControllerState();
            if (state != previousControllerState) {
                previousControllerState = state;
                transceiver->send(channelId, state);
            }
        }

        ControllerStateTransceiver::ControllerStateTransceiver(Controller &controller,
                                                               communication::Transceiver<ControllerState> &transceiver,
                                                               uint8 channelId) :
                controller(&controller),
                transceiver(&transceiver),
                channelId(channelId) {}
    }
}