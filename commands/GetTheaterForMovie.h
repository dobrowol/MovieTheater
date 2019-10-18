//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_GETTHEATERFORMOVIE_H
#define MOVIETHEATER_GETTHEATERFORMOVIE_H

#include <iostream>
#include "../Command.h"

template<class ViewModel>
class GetTheaterForMovie : public Command {
    ViewModel viewModel;
public:
    GetTheaterForMovie() = default;

    virtual ~GetTheaterForMovie() = default;

    bool execute(std::vector<std::string> args) override {
        auto callback = [&](const std::vector<std::string> &res) {
            this->handle(res);
        };
        if (!args.empty()) {
            viewModel.getTheatersForMovie(args[0])->observe(callback);
        }
    }

    void handle(const std::vector<std::string> &res) {
        for (const std::string &s : res) {
            std::cout << s << std::endl;
        }
    }

    bool inputCheck(std::vector<std::string> args) override {
        return true;
    }
};
#endif //MOVIETHEATER_GETTHEATERFORMOVIE_H
