/*
 * DummyMoviesViewModelTest.cpp
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */
#include <bitset>
#include "gmock/gmock.h"
#include <cstdio>

#include "gtest/gtest.h"
#include "ObserverMock.h"
#include "SeatsProviderMock.h"
#include "../commands/ReserveSeatsForMovieTheater.h"
#include "../viewModels/MoviesTheatersViewModel.h"

using ::testing::_;
using ::testing::Return;
using ::testing::NiceMock;
namespace {
    class ReserveSeatsForMovieTheaterTest : public ::testing::Test {

    protected:
        using Result = std::bitset<20>;
        using ResultObserver = ObserverMock<Result>;
        using SeatsProviderMockResult = NiceMock<SeatsProviderMock<Result>>;

        std::shared_ptr<SeatsProviderMockResult> seatsProviderMock = std::make_shared<SeatsProviderMockResult>();
        std::shared_ptr<ResultObserver> observer = std::make_shared<ResultObserver>();
        ReserveSeatsForMovieTheater<MoviesTheatersViewModel, Result > foo;
        using CallbackFunctionMock = testing::MockFunction<void(const Result &)>;
        ReserveSeatsForMovieTheaterTest():foo(seatsProviderMock){}
    };

    TEST_F(ReserveSeatsForMovieTheaterTest, ParseSeatNumber) {
        int expectedSeatNumber = 1;
        std::ostringstream stringStream;
        stringStream << "a"<<expectedSeatNumber;
        std::string seatString = stringStream.str();
        int seatNumber = foo.parse_integer(seatString);
        EXPECT_EQ(1, seatNumber);
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveValidSeat) {
        Result res;
        ON_CALL(*seatsProviderMock,getSeats()).WillByDefault(Return(res));
        EXPECT_TRUE(foo.execute({"Legiony", "Arkady", "a1"}));
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveAlreadyTakenSeat) {
        Result res;
        res.flip();
        ON_CALL(*seatsProviderMock,getSeats()).WillByDefault(Return(res));
        EXPECT_FALSE(foo.execute({"Legiony", "Arkady", "a1"}));
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveNotValidSeat) {
        EXPECT_CALL(*seatsProviderMock,getSeats()).Times(1);
        EXPECT_FALSE(foo.execute({"Legiony", "Arkady", "b1"}));
        EXPECT_FALSE(foo.execute({"Legiony", "Arkady", "a200"}));

    }
}



