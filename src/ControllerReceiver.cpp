//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ControllerReceiver.h"

namespace mark_os {
    namespace controller {
        ControllerState ControllerReceiver::readControllerState() {
            auto message = receiver->receive();
            if (message.isPresent()) {
                if (message.get().signature == Message<ControllerState>::version) {
                    currentControllerState = message.get().content;
                    return currentControllerState;
                }
            }
            return currentControllerState;
        }

        ControllerReceiver::ControllerReceiver(communication::Receiver<ControllerState> &receiver) : receiver(
                &receiver) {}
    }
}