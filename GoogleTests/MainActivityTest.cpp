//
// Created by dobrowol on 19.10.2019.
//

#include <gtest/gtest.h>
#include "../MainActivity.cpp"
#include "CommandMock.h"

using ::testing::ElementsAre;

namespace {
    class MainActivityTest : public ::testing::Test {
    protected:
        using Seats_Container = std::bitset<20>;
        std::shared_ptr<MainActivity<Seats_Container>> mainActivity = std::make_shared<MainActivity<Seats_Container >>();
    };

    TEST_F(MainActivityTest, shouldSelectMovie) {
        std::shared_ptr<CommandMock> commandMock = std::make_shared<CommandMock>();
        mainActivity->setCommand("selectMovie", commandMock);
        EXPECT_CALL(*commandMock, execute(ElementsAre("Legiony")));
        mainActivity->process("selectMovie Legiony");
    }
}
