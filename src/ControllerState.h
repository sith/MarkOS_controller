#ifndef MARKOS_MAIN_CONTROLLERSTATE_H
#define MARKOS_MAIN_CONTROLLERSTATE_H

#include <types.h>

namespace mark_os {
    namespace controller {
        struct ControllerState {
            int16 leftX;
            int16 leftY;
            int16 rightX;
            int16 rightY;
            bool left;
            bool right;
            bool a;
            bool b;
            bool x;
            bool y;

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
