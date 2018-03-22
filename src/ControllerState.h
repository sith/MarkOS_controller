#ifndef MARKOS_MAIN_CONTROLLERSTATE_H
#define MARKOS_MAIN_CONTROLLERSTATE_H

#include <types.h>

namespace mark_os {
    namespace controller {
        struct ControllerState {
            int16 leftX = 0;
            int16 leftY = 0;
            int16 rightX = 0;
            int16 rightY = 0;
            bool left = false;
            bool right = false;
            bool a = false;
            bool b = false;
            bool x = false;
            bool y = false;

            bool operator==(const ControllerState &rhs) const {
                return leftX == rhs.leftX &&
                       leftY == rhs.leftY &&
                       rightX == rhs.rightX &&
                       rightY == rhs.rightY &&
                       left == rhs.left &&
                       right == rhs.right &&
                       a == rhs.a &&
                       b == rhs.b &&
                       x == rhs.x &&
                       y == rhs.y;
            }

            bool operator!=(const ControllerState &rhs) const {
                return !(rhs == *this);
            }

        };
    }
}
#endif //MARKOS_MAIN_CONTROLLERSTATE_H
