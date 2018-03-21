//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ControllerReceiver.h"

namespace mark_os {
    namespace controller {
        ControllerState ControllerReceiver::readControllerState() {
            return receiver->receive(channelId);
        }
    }
}