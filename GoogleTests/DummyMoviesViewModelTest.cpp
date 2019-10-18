/*
 * DummyMoviesViewModelTest.cpp
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */
#include "gmock/gmock.h"

#include "gtest/gtest.h"
#include "../viewModels/DummyMoviesViewModel.h"
#include "ObserverMock.h"

using ::testing::_;
namespace {
    class DummyMoviesViewModelTest : public ::testing::Test {
        using ResultObserver = ObserverMock<std::vector<std::string>>;
    protected:
        std::shared_ptr<ResultObserver> observer = std::make_shared<ResultObserver>();
        DummyMoviesViewModel foo;
        using CallbackFunctionMock = testing::MockFunction<void(const std::vector<std::string>)>;

    };

    TEST_F(DummyMoviesViewModelTest, DummyMoviesViewModel) {

        EXPECT_CALL(*observer, handle(_)).Times(1);
        foo.getAllMovies()->observe(observer);
    }
}



