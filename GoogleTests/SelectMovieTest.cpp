//
// Created by dobrowol on 19.10.2019.
//

#include "gtest/gtest.h"
#include "ObserverMock.h"
#include "SeatsProviderMock.h"
#include "../commands/ReserveSeatsForMovieTheater.h"
#include "../viewModels/MoviesTheatersViewModel.h"
#include "../commands/SelectMovie.h"
#include "MovieSelectionMock.h"

using ::testing::_;
using ::testing::Return;
using ::testing::NiceMock;
namespace {
    class SelectMovieTest : public ::testing::Test {
    protected:
        MovieSelectionMock movieSelectionMock;;
        SelectMovie selectMovie;

        SelectMovieTest() : selectMovie(movieSelectionMock) {}
    };

    TEST_F(SelectMovieTest, shouldSelect) {
        EXPECT_CALL(movieSelectionMock, setMovie("Legiony"));
        selectMovie.execute({"Legiony"});
    }
}