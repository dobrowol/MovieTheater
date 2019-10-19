//
// Created by dobrowol on 19.10.2019.
//
#include "gmock/gmock.h"

#include "gtest/gtest.h"
#include "ObserverMock.h"
#include "../commands/GetAllMovies.h"
#include "../viewModels/DummyMoviesViewModel.h"

using ::testing::_;
namespace {
    class GetAllMoviesTest : public ::testing::Test {
        using ResultObserver = ObserverMock<std::vector<std::string>>;
    protected:
        GetAllMovies<DummyMoviesViewModel> foo;
        using CallbackFunctionMock = testing::MockFunction<void(const std::vector<std::string>)>;
    };

    TEST_F(GetAllMoviesTest, WrongParameterNumber) {

        EXPECT_FALSE(foo.execute({"Legiony"}));
    }
}
