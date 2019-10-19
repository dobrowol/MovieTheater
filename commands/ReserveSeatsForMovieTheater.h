//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H
#define MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H

#include <vector>
#include <iostream>
#include "../Command.h"
#include <boost/regex.hpp>

template<class Seats>
class SeatsProvider {
public:
    virtual Seats getSeats() = 0;
};

template<class ViewModel, class Seats>
class ReserveSeatsForMovieTheater : public Command {
    ViewModel viewModel;
    std::shared_ptr<SeatsProvider<Seats>> availableSeatsProvider;
    std::vector<int> seatsNumbers;
public:
    explicit ReserveSeatsForMovieTheater(std::shared_ptr<SeatsProvider<Seats>> availableSeatsProvider) :
            availableSeatsProvider(availableSeatsProvider) {};

    virtual ~ReserveSeatsForMovieTheater() = default;

    int parse_integer(const std::string &seat) {
        boost::smatch sm1;
        regex_search(seat, sm1, boost::regex("a(.*)"));
        return std::stoi(sm1[1]);
    }

    bool execute(std::vector<std::string> args) override {
        if (inputCheck(args)) {
            Seats availableSeats = availableSeatsProvider->getSeats();
            Seats reserved_seats(0);

            for (auto seat_nbr : seatsNumbers) {
                if(seat_nbr > availableSeats.size())
                    return false;
                if (!availableSeats[seat_nbr])
                    reserved_seats[seat_nbr] = true;
                else {
                    return false;
                }
            }

            viewModel.reserveSeatsForMovieTheater(args[0], args[1], reserved_seats);
        } else {
            return false;
        }
        return true;
    }

    bool inputCheck(std::vector<std::string> args) override {
        if (args.size() < 3)
            return false;
        boost::regex pattern("a(\\d+)");
        boost::smatch result;
        for (auto i = args.begin() + 2; i != args.end(); i++) {
            if (!boost::regex_search(*i, result, pattern)) {
                return false;
            }
            seatsNumbers.emplace_back(std::stoi(result[1]));
        }
        return true;
    }
};
#endif //MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H
