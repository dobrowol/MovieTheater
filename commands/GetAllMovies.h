/*
 * GetAllMovies.h
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */

#ifndef COMMANDS_GETALLMOVIES_H_
#define COMMANDS_GETALLMOVIES_H_
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../viewModels/Observer.h"
#include "../Command.h"

template<class ViewModel>
class GetAllMovies
        : public Command, Observer<std::vector<std::string>>, std::enable_shared_from_this<GetAllMovies<ViewModel>> {
    ViewModel viewModel;
public:
    GetAllMovies() = default;

    virtual ~GetAllMovies() = default;

    bool execute(std::vector<std::string> args) override {
        auto callback = [&](const std::vector<std::string> &res) {
            this->handle(res);
        };
        viewModel.getAllMovies()->observe(callback);
    }

    void handle(const std::vector<std::string> &res) override {
        for (const std::string &s : res) {
            std::cout << s << std::endl;
        }
    }

    bool inputCheck(std::vector<std::string> args) override {
        return true;
    }
};

#endif /* COMMANDS_GETALLMOVIES_H_ */
