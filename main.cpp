#include <iostream>
#include "MainActivity.cpp"

using namespace std;
using Seats_Container = std::bitset<20>;

int main() {

    MainActivity<Seats_Container> commandLine;

    commandLine.setCommand("getSeatsForMovieTheater", std::make_shared<GetSeatsForMovieTheater<MoviesTheatersViewModel>>(
            std::static_pointer_cast<AvailableSeatsSetter>(commandLine.shared_from_this())));
    commandLine.setCommand("getAllMovies",            std::make_shared<GetAllMovies<DummyMoviesViewModel>>());
    commandLine.setCommand("getTheatersForMovie",     std::make_shared<GetTheaterForMovie<MoviesTheatersViewModel>>());
    commandLine.setCommand("reserveSeatsForMovieTheater",
                           std::make_shared<ReserveSeatsForMovieTheater<MoviesTheatersViewModel,
                                   Seats_Container>>(commandLine.shared_from_this()));
    commandLine.setCommand("selectMovie", std::make_shared<SelectMovie>(commandLine.shared_from_this()));

    for (std::string line; std::cout << "APP > " && std::getline(std::cin, line);) {

        if (!line.empty()) { commandLine.process(line); }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
