//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_MOVIETHEATERSEATSDAO_H
#define MOVIETHEATER_MOVIETHEATERSEATSDAO_H

#include "Database.h"
#include <memory>
#include "../viewModels/Subject.h"

class MovieTheaterSeatsDAO{
    Database& database;
    using Subject_Int=Subject<std::vector<int>>;
public:
    MovieTheaterSeatsDAO():database(Database::getInstance()){
    }
    std::shared_ptr<Subject_Int> getSeatsForMovieTheater(const std::string& movie, const std::string& theater){
        std::vector<MovieTheaterSeats> movieTheaterSeats = database.getMovieTheaterSeats();
        for (const auto& movieTheaterSeat : movieTheaterSeats){
            if(movieTheaterSeat.theater == theater && movieTheaterSeat.movie == movie){
                return std::make_shared<Subject_Int>(movieTheaterSeat.seats);
            }
        }
        return {};
    }
};
#endif //MOVIETHEATER_MOVIETHEATERSEATSDAO_H
