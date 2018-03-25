//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_MOCKRECEIVER_H
#define MARKOS_MAIN_MOCKRECEIVER_H

#include <Receiver.h>
#include "gmock/gmock.h"

namespace mark_os {
    namespace communication {

        template<typename T0>
        class MockReceiver : public Receiver<T0> {
        public:
            MOCK_METHOD0_T(receive,
                           commons::Optional<Message<T0>>());
        };

    }  // namespace communication
}  // namespace mark_os

#endif //MARKOS_MAIN_MOCKRECEIVER_H
