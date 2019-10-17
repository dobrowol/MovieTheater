#pragma once
#include <vector>
#include <string>
#include <functional>
#include "Subject.h"
#include "../database/Movie.h"

class DummyMoviesViewModel{

public:
	std::shared_ptr<Subject<std::vector<std::string>>> getAllMovies(){
	    std::shared_ptr<Subject<std::vector<std::string>>> subject =
	            std::make_shared<Subject<std::vector<std::string>>>();
	    subject->setValue({"Legiony", "Joker", "LastMountain"});
        return subject;
	}
	std::shared_ptr<Movie> getMovieDetail(const std::string& movie){

	}
};
