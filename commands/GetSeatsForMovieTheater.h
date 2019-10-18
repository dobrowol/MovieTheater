//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_GETSEATSFORMOVIETHEATER_H
#define MOVIETHEATER_GETSEATSFORMOVIETHEATER_H

#include <iostream>
#include "../Command.h"

template<class ViewModel>
class GetSeatsForMovieTheater : public Command {
    ViewModel viewModel;
public:
    GetSeatsForMovieTheater() = default;

    virtual ~GetSeatsForMovieTheater() = default;

    void execute(std::vector<std::string> args) override {
        auto callback = [&](const std::bitset<20> &res) {
            this->handle(res);
        };
        if (!args.empty()) {
            viewModel.getSeatsForMovieTheater(args[0], args[1])->observe(callback);
        }
    }

    void handle(const std::bitset<20> &res) {
        for (auto s = 0; s < res.size(); s++) {
            if (!res[s]) {
                std::cout << "a" << s << " ";
            }
        }
        std::cout << std::endl;
    }

    bool inputCheck(std::vector<std::string> args) override {
        return true;
    }
};
#endif //MOVIETHEATER_GETSEATSFORMOVIETHEATER_H
