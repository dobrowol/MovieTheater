//
// Created by dobrowol on 15.10.2019.
//

#ifndef MOVIETHEATER_SEATSPROVIDERMOCK_H
#define MOVIETHEATER_SEATSPROVIDERMOCK_H
#include "gmock/gmock.h"
#include "../commands/ReserveSeatsForMovieTheater.h"

template<class Result>
class SeatsProviderMock : public SeatsProvider<Result> {
public:
    MOCK_METHOD(Result, getSeats, (), (override));
};
#endif //MOVIETHEATER_SEATSPROVIDERMOCK_H
