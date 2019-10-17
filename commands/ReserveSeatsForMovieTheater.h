//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H
#define MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H

#include <vector>
#include <iostream>
#include "../Command.h"
#include <boost/regex.hpp>

template<class ViewModel>
class ReserveSeatsForMovieTheater : public Command{
    ViewModel viewModel;
public:
    ReserveSeatsForMovieTheater() = default;
    virtual ~ReserveSeatsForMovieTheater() = default;

    int parse_integer(const std::string& seat) {
        boost::smatch sm1;
        regex_search(seat, sm1, boost::regex("a(.*)"));
        return std::stoi(sm1[0]);
    }

    void execute(std::vector<std::string> args) override{
        if(!args.empty()) {
            std::bitset<20> seats(0);
            if(args.size()>2){
                for(auto i = args.begin()+2; i != args.end();i++){
                    int seat_nbr = parse_integer(*i);
                    seats[seat_nbr] = true;
                }
            }
            viewModel.reserveSeatsForMovieTheater(args[0], args[1], seats);
        }
    }
};
#endif //MOVIETHEATER_RESERVESEATSFORMOVIETHEATER_H
