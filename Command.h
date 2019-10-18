//
// Created by dobrowol on 16.10.2019.
//

#ifndef MOVIETHEATER_COMMAND_H
#define MOVIETHEATER_COMMAND_H


#include <string>
#include <vector>

class Command {
public:
    virtual void execute(std::vector<std::string> args) = 0;

    virtual bool inputCheck(std::vector<std::string> args) = 0;
};


#endif //MOVIETHEATER_COMMAND_H
