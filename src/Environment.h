//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_MAIN_CONTROLLERENVIRONMENT_H
#define MARKOS_MAIN_CONTROLLERENVIRONMENT_H

#include <Cycle.h>
#include "Controller.h"
#include "ControllerStateTransceiver.h"

namespace mark_os {
    namespace controller {
        class Environment {
        public:
            virtual Controller &getController()= 0;

            virtual mark_os::cycle::Cycle &getCycle()= 0;

            virtual ControllerStateTransceiver &getControllerStateTransceiver()= 0;

            void init();
        };
    }
}

#endif //MARKOS_MAIN_CONTROLLERENVIRONMENT_H
