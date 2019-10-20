//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_MOVIETHEATERSEATS_H
#define MOVIETHEATER_MOVIETHEATERSEATS_H


#include <string>
#include <vector>
#include <bitset>

struct MovieTheaterSeats {
    MovieTheaterSeats(std::string movie, std::string theater) : movie(std::move(movie)), theater(std::move(theater)),
                                                                seats(0) {}

    MovieTheaterSeats(std::string movie, std::string theater, std::bitset<20> seats) : movie(std::move(movie)),
                                                                                       theater(std::move(theater)),
                                                                                       seats(seats) {}

    std::string movie;
    std::string theater;
    std::bitset<20> seats;

    MovieTheaterSeats() : movie(""), theater(""), seats(0) {}
};

#endif //MOVIETHEATER_MOVIETHEATERSEATS_H
