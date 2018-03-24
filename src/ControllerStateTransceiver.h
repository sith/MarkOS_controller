//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_MAIN_CONTROLLERTRANSCEIVER_H
#define MARKOS_MAIN_CONTROLLERTRANSCEIVER_H

#include "Controller.h"

namespace mark_os {
    namespace controller {
        class ControllerStateTransceiver : public mark_os::cycle::CycleListener {
            Controller *controller;
            mark_os::communication::Transceiver<mark_os::controller::ControllerState> *transceiver;

            ControllerState previousControllerState;

        public:
            ControllerStateTransceiver(Controller &controller,
                                       communication::Transceiver <ControllerState> &transceiver);


            void onEvent(unsigned long cycleNumber) override;

        };
    }
}

#endif //MARKOS_MAIN_CONTROLLERTRANSCEIVER_H
