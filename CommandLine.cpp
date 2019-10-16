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

class CommandLine{
    std::unordered_map<std::string, std::shared_ptr<Command>> commands;

    std::vector<std::string> split(const std::string& line){
        std::istringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        return results;
    }
public:
    CommandLine():commands({
                                   {"getAllMovies", std::make_shared<GetAllMovies<DummyMoviesViewModel>>()}
                           }){}

    void process( std::string line){
        auto args = split(line);
        if(!args.empty()) {
            commands[args[0]]->execute({args.begin() + 1, args.end()});
        }
    }
};