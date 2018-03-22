
#include "Environment.h"

void mark_os::controller::Environment::init() {
    getCycle().getListeners()->add(&getControllerStateTransceiver());
}
