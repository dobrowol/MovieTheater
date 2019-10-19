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
    public:
        virtual void setMovie(std::string) = 0;
    };

    explicit SelectMovie(std::shared_ptr<MovieSelectionInterface> movieSelectionInterface) :
            movieSelectionInterface(std::move(movieSelectionInterface)) {}

    bool execute(std::vector<std::string> args) override {
        if(!inputCheck(args)){
            return false;
        }

        movieSelectionInterface->setMovie(args[0]);
        return true;
    }

    bool inputCheck(std::vector<std::string> args) override {
        return args.size() == 1;
    }

private:
    std::shared_ptr<MovieSelectionInterface> movieSelectionInterface;
};
#endif //MOVIETHEATER_SELECTMOVIE_H
