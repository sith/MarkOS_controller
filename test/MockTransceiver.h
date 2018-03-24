//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_MOCKTRANSCEIVER_H
#define MARKOS_MAIN_MOCKTRANSCEIVER_H

#include "gmock/gmock.h"
#include <Transceiver.h>

namespace mark_os {
    namespace communication {

        template<typename T0>
        class MockTransceiver : public Transceiver<T0> {
        public:
            MOCK_METHOD1_T(send,
                           void(Message<T0>
                                   &message));
        };

    }  // namespace communication
}  // namespace mark_os

#endif //MARKOS_MAIN_MOCKTRANSCEIVER_H
