//
// Created by dobrowol on 14.10.2019.
//

#include <functional>
#include <vector>
#include "Subject.h"
#include "../database/MovieTheaterSeatsDAO.h"

class MoviesTheatersViewModel{
    using Subject_String=Subject<std::vector<std::string>>;
    using Subject_Int=Subject<std::vector<int>>;
public:
    std::shared_ptr<Subject_String> getTheatersForMovie(const std::string& movie){
        if(movie == "Legiony"){
            std::shared_ptr<Subject_String> subject =
                    std::make_shared<Subject_String>();
            subject->setValue({"Arkady", "Helios", "NoweHoryzonty"});
            return subject;
        }
    }
    std::shared_ptr<Subject_Int> getSeatsForMovieTheater(const std::string& movie, const std::string& theater){
        MovieTheaterSeatsDAO movieTheaterSeatsDao;
        return movieTheaterSeatsDao.getSeatsForMovieTheater(movie, theater);
    }
};