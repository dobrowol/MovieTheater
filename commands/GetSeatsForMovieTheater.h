//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_GETSEATSFORMOVIETHEATER_H
#define MOVIETHEATER_GETSEATSFORMOVIETHEATER_H

#include <iostream>
#include "../Command.h"

class AvailableSeatsSetter {
public:
    virtual void setSeats(std::bitset<20>) = 0;
};

template<class ViewModel>
class GetSeatsForMovieTheater : public Command {
    ViewModel viewModel;
    std::shared_ptr<AvailableSeatsSetter> setter;
public:
    explicit GetSeatsForMovieTheater(std::shared_ptr<AvailableSeatsSetter> setter):setter(std::move(setter)){};

    virtual ~GetSeatsForMovieTheater() = default;

    bool execute(std::vector<std::string> args) override {
        if(!inputCheck(args)){
            return false;
        }
        auto callback = [&](const std::bitset<20> &res) {
            this->handle(res);
        };
        if (!args.empty()) {
            viewModel.getSeatsForMovieTheater(args[0], args[1])->observe(callback);
        }
        return true;
    }

    void handle(const std::bitset<20> &res) {
        for (auto s = 0; s < res.size(); s++) {
            if (!res[s]) {
                std::cout << "a" << s << " ";
            }
        }
        std::cout << std::endl;
        setter->setSeats(res);
    }

    bool inputCheck(std::vector<std::string> args) override {
        return true;
    }
};
#endif //MOVIETHEATER_GETSEATSFORMOVIETHEATER_H
