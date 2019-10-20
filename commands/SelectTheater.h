//
// Created by dobrowol on 20.10.2019.
//

#ifndef MOVIETHEATER_SELECTTHEATER_H
#define MOVIETHEATER_SELECTTHEATER_H

#include <memory>
#include "../Command.h"

class SelectTheater : public Command {

public:
    class TheaterSelectionInterface {
    public:
        virtual void setTheater(std::string) = 0;
    };

    explicit SelectTheater(TheaterSelectionInterface &theaterSelectionInterface) :
            theaterSelectionInterface(theaterSelectionInterface) {}

    bool execute(std::vector<std::string> args) override {
        if (!inputCheck(args)) {
            return false;
        }
        theaterSelectionInterface.setTheater(args[0]);
        return true;
    }

    bool inputCheck(std::vector<std::string> args) override {
        return args.size() == 1;
    }

private:
    TheaterSelectionInterface &theaterSelectionInterface;
};

#endif //MOVIETHEATER_SELECTTHEATER_H
