//
// Created by dobrowol on 17.10.2019.
//

#ifndef MOVIETHEATER_DATABASE_H
#define MOVIETHEATER_DATABASE_H
#include <memory>
#include <vector>
#include <mutex>
#include "Movie.h"
#include "MovieTheaterSeats.h"

class Database{
    std::vector<Movie> movies;
    std::vector<MovieTheaterSeats> movieTheaterSeats;
    std::mutex insert_mutex;
public:
    static Database& getInstance(){
        static Database instance;

        return instance;
    }

    std::vector<Movie> getMovies(){
        return movies;
    }
    std::vector<MovieTheaterSeats> getMovieTheaterSeats(){
        return movieTheaterSeats;
    }
    void setMovieTheaterSeats(const MovieTheaterSeats& movieTheaterSeats1){
        std::lock_guard<std::mutex> lock(insert_mutex);
        for(auto mTS : movieTheaterSeats){
            if (mTS.movie == movieTheaterSeats1.movie && mTS.theater == movieTheaterSeats1.theater){
                mTS.seats = movieTheaterSeats1.seats;
            }
        }
    }
    Database(const Database&) = delete;
    void operator=(Database&) = delete;
private:
    Database() {
        movieTheaterSeats.emplace_back(MovieTheaterSeats("Legiony", "Arkady"));
    };


};
#endif //MOVIETHEATER_DATABASE_H
