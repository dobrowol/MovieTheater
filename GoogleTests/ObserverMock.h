//
// Created by dobrowol on 15.10.2019.
//

#ifndef MOVIETHEATER_OBSERVERMOCK_H
#define MOVIETHEATER_OBSERVERMOCK_H

#include "gmock/gmock.h"
#include "../viewModels/Observer.h"

template<class Result>
class ObserverMock : public Observer<Result> {
public:
    MOCK_METHOD(void, handle, (const Result&), (override));
};

#endif //MOVIETHEATER_OBSERVERMOCK_H
