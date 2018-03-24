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
                Message<ControllerState> message{0, 0, state};
                transceiver->send(message);
            }
        }

        ControllerStateTransceiver::ControllerStateTransceiver(Controller &controller,
                                                               communication::Transceiver<ControllerState> &transceiver)
                : controller(&controller), transceiver(&transceiver) {}

    }
}