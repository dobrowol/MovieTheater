/*
 * DummyMoviesViewModelTest.cpp
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */
#include "gmock/gmock.h"

#include "gtest/gtest.h"
#include "../viewModels/DummyMoviesViewModel.h"

using ::testing::_;
namespace {
  class DummyMoviesViewModelTest : public ::testing::Test {
  protected:
	  DummyMoviesViewModel foo;
	  using CallbackFunctionMock = testing::MockFunction< void(const std::vector<std::string>)>;

  };
  TEST_F(DummyMoviesViewModelTest, DummyMoviesViewModel) {
        CallbackFunctionMock  callbackFunctionMock;
      auto callback = [&](const std::vector<std::string>& param){
          callbackFunctionMock.Call(param);};

	  EXPECT_CALL(callbackFunctionMock, Call(_)).Times(1);
        foo.getAllMovies(callback);
  }
}



