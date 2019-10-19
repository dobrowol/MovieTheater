//
// Created by dobrowol on 19.10.2019.
//

#ifndef MOVIETHEATER_COMMANDMOCK_H
#define MOVIETHEATER_COMMANDMOCK_H

#include "gmock/gmock.h"
#include "../Command.h"

class CommandMock : public Command{
public:
    MOCK_METHOD(bool, execute, (std::vector<std::string>), (override));
    MOCK_METHOD(bool, inputCheck, (std::vector<std::string>), (override));
};

#endif //MOVIETHEATER_COMMANDMOCK_H
