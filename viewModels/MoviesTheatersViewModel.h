//
// Created by dobrowol on 14.10.2019.
//

#include <functional>
#include <vector>
#include "Subject.h"
#include "../database/MovieTheaterSeatsDAO.h"

class MoviesTheatersViewModel{
    using Subject_String=Subject<std::vector<std::string>>;
    using Subject_Bitset=Subject<std::bitset<20>>;
    MovieTheaterSeatsDAO movieTheaterSeatsDao;
public:
    std::shared_ptr<Subject_String> getTheatersForMovie(const std::string& movie){
        if(movie == "Legiony"){
            std::shared_ptr<Subject_String> subject =
                    std::make_shared<Subject_String>();
            subject->setValue({"Arkady", "Helios", "NoweHoryzonty"});
            return subject;
        }
    }
    std::shared_ptr<Subject_Bitset> getSeatsForMovieTheater(const std::string& movie, const std::string& theater){
        return movieTheaterSeatsDao.getSeatsForMovieTheater(movie, theater);
    }

    void reserveSeatsForMovieTheater(const std::string& movie, const std::string& theater, std::bitset<20> seats){
        movieTheaterSeatsDao.reserveSeatsForMovieTheater(movie, theater, seats);
    }
};