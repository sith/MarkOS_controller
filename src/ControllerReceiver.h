//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_MAIN_CONTROLLERRECEIVER_H
#define MARKOS_MAIN_CONTROLLERRECEIVER_H


#include <Receiver.h>
#include "Controller.h"

namespace mark_os {
    namespace controller {
        class ControllerReceiver : public Controller {
            communication::Receiver<ControllerState> *receiver;
            ControllerState currentControllerState;
        public:
            explicit ControllerReceiver(communication::Receiver<ControllerState> &receiver);

            ControllerState readControllerState() override;
        };
    }
}
#endif //MARKOS_MAIN_CONTROLLERRECEIVER_H
