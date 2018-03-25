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
            mark_os::communication::Receiver<ControllerState> *receiver;
        public:
            ControllerState readControllerState() override;
        };
    }
}
#endif //MARKOS_MAIN_CONTROLLERRECEIVER_H
