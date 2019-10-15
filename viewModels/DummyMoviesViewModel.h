#pragma once
#include <vector>
#include <string>
#include <functional>
class DummyMoviesViewModel{

public:
	void getAllMovies(const std::function< void(const std::vector<std::string>) >& lambda){
		lambda( {"Joker", "Legiony", "Last Mountain"});
	}
};
