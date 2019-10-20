#include <iostream>
#include "MainActivity.cpp"
#include "commands/SelectTheater.h"
#include "commands/GetAllMovies.h"
#include "viewModels/DummyMoviesViewModel.h"

using namespace std;
using Seats_Container = std::bitset<20>;

int main() {

    MainActivity<Seats_Container> commandLine;

    commandLine.setCommand("getAllMovies", std::make_shared<GetAllMovies<DummyMoviesViewModel>>());
    commandLine.setCommand("selectMovie", std::make_shared<SelectMovie>(commandLine));
    commandLine.setCommand("getTheatersForMovie", std::make_shared<GetTheaterForMovie<MoviesTheatersViewModel>>());
    commandLine.setCommand("selectTheater", std::make_shared<SelectTheater>(commandLine));
    commandLine.setCommand("getSeatsForMovieTheater",
                           std::make_shared<GetSeatsForMovieTheater<MoviesTheatersViewModel>>(
                                   commandLine));
    commandLine.setCommand("reserveSeatsForMovieTheater",
                           std::make_shared<ReserveSeatsForMovieTheater<MoviesTheatersViewModel,
                                   Seats_Container>>(commandLine));
    for (std::string line; std::getline(std::cin, line);) {

        if (!line.empty()) { commandLine.process(line); }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
