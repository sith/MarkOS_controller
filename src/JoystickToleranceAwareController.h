//
// Created by Oleksandra Baukh on 4/10/18.
//

#ifndef MARKOS_MAIN_JOYSTICTOLERANCEAWARECONTROLLER_H
#define MARKOS_MAIN_JOYSTICTOLERANCEAWARECONTROLLER_H

#include "Controller.h"

namespace mark_os {
    namespace controller {
        class JoystickToleranceAwareController : public Controller {
            Controller *controller;
        public:
            JoystickToleranceAwareController(Controller &controller);

        public:
            commons::Optional<ControllerState> readControllerState() override;
        };
    }
}

#endif //MARKOS_MAIN_JOYSTICTOLERANCEAWARECONTROLLER_H
