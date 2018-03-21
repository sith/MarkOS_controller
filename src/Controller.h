//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_CONTROLLER_H
#define MARKOS_MAIN_CONTROLLER_H


#include <CycleListener.h>
#include <Transceiver.h>
#include "ControllerState.h"

namespace mark_os {
    namespace controller {
        class Controller {
        public:
            virtual ControllerState readControllerState()= 0;
        };
    }
}

#endif //MARKOS_MAIN_CONTROLLER_H
