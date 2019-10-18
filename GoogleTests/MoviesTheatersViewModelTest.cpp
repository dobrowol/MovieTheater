/*
 * DummyMoviesViewModelTest.cpp
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */
#include "gmock/gmock.h"

#include "gtest/gtest.h"
#include "ObserverMock.h"
#include "../viewModels/MoviesTheatersViewModel.h"

using ::testing::_;
namespace {
    class MoviesTheatersViewModelTest : public ::testing::Test {
        using ResultObserver = ObserverMock<std::vector<std::string>>;
    protected:
        std::shared_ptr<ResultObserver> observer = std::make_shared<ResultObserver>();
        MoviesTheatersViewModel foo;
        using CallbackFunctionMock = testing::MockFunction<void(const std::vector<std::string>)>;

    };

    TEST_F(MoviesTheatersViewModelTest, MoviesTheatersViewModel) {

        EXPECT_CALL(*observer, handle(_)).Times(1);
        foo.getTheatersForMovie("Legiony")->observe(observer);
    }
}



