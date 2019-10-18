/*
 * DummyMoviesViewModelTest.cpp
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */
#include <bitset>
#include "gmock/gmock.h"

#include "gtest/gtest.h"
#include "ObserverMock.h"
#include "../commands/ReserveSeatsForMovieTheater.h"
#include "../viewModels/MoviesTheatersViewModel.h"

using ::testing::_;
namespace {
    class ReserveSeatsForMovieTheaterTest : public ::testing::Test {
        using Result = std::bitset<20>;
        using ResultObserver = ObserverMock<Result>;
    protected:
        std::shared_ptr<ResultObserver> observer = std::make_shared<ResultObserver>();
        ReserveSeatsForMovieTheater<MoviesTheatersViewModel> foo;
        using CallbackFunctionMock = testing::MockFunction<void(const Result &)>;

    };

    TEST_F(ReserveSeatsForMovieTheaterTest, ParseSeatNumber) {

        int i = foo.parse_integer("a1");
        EXPECT_EQ(1, i);
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveValidSeat) {
        foo.execute({"Legiony", "Arkady", "a1"});
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveAlreadyTakenSeat) {
        foo.execute({"Legiony", "Arkady", "b1"});
    }

    TEST_F(ReserveSeatsForMovieTheaterTest, ReserveNotValidSeat) {
        //b1
        //a200

    }
}



