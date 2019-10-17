//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_MOVIETHEATERSEATS_H
#define MOVIETHEATER_MOVIETHEATERSEATS_H


#include <string>
#include <vector>

struct MovieTheaterSeats {
    MovieTheaterSeats(std::string movie, std::string theater): movie(std::move(movie)), theater(std::move(theater)), seats(20, 0) {
        
    }

    std::string movie;
    std::string theater;
    std::vector<int> seats;
    MovieTheaterSeats():movie(""), theater(""), seats(20, 0){}
};


#endif //MOVIETHEATER_MOVIETHEATERSEATS_H
