//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ControllerReceiver.h"

namespace mark_os {
    namespace controller {
        commons::Optional<ControllerState> ControllerReceiver::readControllerState() {
            auto message = receiver->receive();
            if (message) {
                if (message.get().signature == Message<ControllerState>::version) {
                    return commons::optional(message().content);
                }
            }
            return commons::none<ControllerState>();
        }

        ControllerReceiver::ControllerReceiver(communication::Receiver<ControllerState> &receiver) : receiver(
                &receiver) {}
    }
}