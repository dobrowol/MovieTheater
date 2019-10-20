//
// Created by dobrowol on 16.10.2019.
//

#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <iterator>
#include "Command.h"
#include "viewModels/MoviesTheatersViewModel.h"
#include "commands/GetTheaterForMovie.h"
#include "commands/GetSeatsForMovieTheater.h"
#include "commands/ReserveSeatsForMovieTheater.h"
#include "commands/SelectMovie.h"
#include "commands/SelectTheater.h"

template<class Seats_Container>
class MainActivity
        : public SelectMovie::MovieSelectionInterface,
          public AvailableSeatsSetter,
          public SeatsProvider<Seats_Container>,
          public std::enable_shared_from_this<MainActivity<Seats_Container>>,
          public SelectTheater::TheaterSelectionInterface {

    std::unordered_map<std::string, std::shared_ptr<Command>> commands;

    std::vector<std::string> split(const std::string &line) {
        std::istringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        return results;
    }

    MovieTheaterSeats movieTheaterSeats;
public:
    MainActivity() = default;

    /**
 * \brief   The process function.
 *
 * \details This function process command from client. Its input is string and
 *          it uses command map to select proper command to execute. Commands are
 *          set up before.
 *
 *
 * \param[in]     line    Input from client.
 *
 * \return        Nothing is returned.
 */
    void process(const std::string &line) {
        auto args = split(line);
        if (!args.empty()) {
            if (commands.find(args[0]) != commands.end()) {
                commands[args[0]]->execute({args.begin() + 1, args.end()});
            }
        }
    }

    void setMovie(std::string movie) override {
        std::cout << "Movie selected " << movie << std::endl;
        movieTheaterSeats.movie = std::move(movie);
        movieTheaterSeats.theater = "";
    }

    void setTheater(std::string theater) override {
        std::cout << "Theater selected" << theater << std::endl;
        movieTheaterSeats.theater = std::move(theater);
    }

    void setSeats(Seats_Container seats) override {
        movieTheaterSeats.seats = seats;
    }

    Seats_Container getSeats() override {
        return movieTheaterSeats.seats;
    }

    void setCommand(const std::string &commandName, const std::shared_ptr<Command> &command) {
        commands[commandName] = command;
    }
};