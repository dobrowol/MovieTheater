//
// Created by dobrowol on 16.10.2019.
//

#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <iterator>
#include "Command.h"
#include "commands/GetAllMovies.h"
#include "viewModels/DummyMoviesViewModel.h"
#include "viewModels/MoviesTheatersViewModel.h"
#include "commands/GetTheaterForMovie.h"
#include "commands/GetSeatsForMovieTheater.h"
#include "commands/ReserveSeatsForMovieTheater.h"

class MainActivity {
    std::unordered_map<std::string, std::shared_ptr<Command>> commands;

    std::vector<std::string> split(const std::string &line) {
        std::istringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        return results;
    }

    std::string movie;
    std::string theater;
public:
    MainActivity() : commands({
                                      {"getAllMovies",                std::make_shared<GetAllMovies<DummyMoviesViewModel>>()},
                                      {"getTheatersForMovie",         std::make_shared<GetTheaterForMovie<MoviesTheatersViewModel>>()},
                                      {"getSeatsForMovieTheater",     std::make_shared<GetSeatsForMovieTheater<MoviesTheatersViewModel>>()},
                                      {"reserveSeatsForMovieTheater", std::make_shared<ReserveSeatsForMovieTheater<MoviesTheatersViewModel>>()}
                              }) {}

    void process(const std::string &line) {
        auto args = split(line);
        if (!args.empty()) {
            if (commands.find(args[0]) != commands.end()) {
                commands[args[0]]->execute({args.begin() + 1, args.end()});
            }
        }
    }
};