#include "ControllerStateReceiver.h"

namespace mark_os {
    namespace controller {
        commons::Optional<ControllerState> ControllerStateReceiver::readControllerState() {
            auto message = receiver->receive();
            if (message) {
                if (message.get().signature == Message<ControllerState>::version) {
                    return commons::optional(message().content);
                }
            }
            return commons::none<ControllerState>();
        }

        ControllerStateReceiver::ControllerStateReceiver(communication::Receiver<ControllerState> &receiver) : receiver(
                &receiver) {}
    }
}