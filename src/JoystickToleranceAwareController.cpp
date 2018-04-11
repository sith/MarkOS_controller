//
// Created by Oleksandra Baukh on 4/10/18.
//

#include "JoystickToleranceAwareController.h"

mark_os::commons::Optional<mark_os::controller::ControllerState>
mark_os::controller::JoystickToleranceAwareController::readControllerState() {
    auto controllerState = controller->readControllerState();
    if (controllerState) {

        if (controllerState.get().leftX <= mark_os::controller::joystickTolerance &&
            controllerState.get().leftX >= -mark_os::controller::joystickTolerance) {
            controllerState.get().leftX = 0;
        }

        if (controllerState.get().leftY <= mark_os::controller::joystickTolerance &&
            controllerState.get().leftY >= -mark_os::controller::joystickTolerance) {
            controllerState.get().leftY = 0;
        }

        if (controllerState.get().rightX <= mark_os::controller::joystickTolerance &&
            controllerState.get().rightX >= -mark_os::controller::joystickTolerance) {
            controllerState.get().rightX = 0;
        }

        if (controllerState.get().rightY <= mark_os::controller::joystickTolerance &&
            controllerState.get().rightY >= -mark_os::controller::joystickTolerance) {
            controllerState.get().rightY = 0;
        }
    }
    return controllerState;
}

mark_os::controller::JoystickToleranceAwareController::JoystickToleranceAwareController(
        mark_os::controller::Controller &controller) : controller(&controller) {}
