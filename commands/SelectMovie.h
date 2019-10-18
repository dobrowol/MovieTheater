//
// Created by dobrowol on 18.10.2019.
//

#ifndef MOVIETHEATER_SELECTMOVIE_H
#define MOVIETHEATER_SELECTMOVIE_H

#include <memory>
#include "../Command.h"

class SelectMovie : public Command {

public:
    class MovieSelectionInterface {
        virtual void setMovie(std::string) = 0;
    };

    explicit SelectMovie(std::shared_ptr<MovieSelectionInterface> movieSelectionInterface) :
            movieSelectionInterface(std::move(movieSelectionInterface)) {}

    bool execute(std::vector<std::string> args) override {

    }

    bool inputCheck(std::vector<std::string> args) override {
        return true;
    }

private:
    std::shared_ptr<MovieSelectionInterface> movieSelectionInterface;
};
#endif //MOVIETHEATER_SELECTMOVIE_H
