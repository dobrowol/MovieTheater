//
// Created by dobrowol on 14.10.2019.
//

#include <functional>
#include <vector>
#include "Subject.h"

class MoviesTheatersViewModel{
    using Subject_Vector=Subject<std::vector<std::string>>;
public:
    std::shared_ptr<Subject_Vector> getTheatersForMovie(const std::string& movie){
        if(movie == "Legiony"){
            std::shared_ptr<Subject_Vector> subject =
                    std::make_shared<Subject_Vector>();
            subject->setValue({"Arkady", "Helios", "NoweHoryzonty"});
            return subject;
        }
    }
};