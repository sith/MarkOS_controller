//
// Created by Oleksandra Baukh on 3/20/18.
//

#ifndef MARKOS_MAIN_MOCKTRANSCEIVER_H
#define MARKOS_MAIN_MOCKTRANSCEIVER_H

#include "gmock/gmock.h"
#include <Transceiver.h>

namespace mark_os {
    namespace communication {

        template<typename Message>
        class MockTransceiver : public mark_os::communication::Transceiver<Message> {
        public:
            MOCK_METHOD2_T(send,
                           void(uint8
                                   channelId, Message & message));
        };

    }  // namespace communication
}  // namespace mark_os

#endif //MARKOS_MAIN_MOCKTRANSCEIVER_H
