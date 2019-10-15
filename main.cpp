#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "commands/GetAllMovies.h"
#include "viewModels/DummyMoviesViewModel.h"
using namespace std;

bool startsWith(std::string mainStr, std::string toMatch)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

void process(std::string line){
    if(startsWith(line, "getAllMovies")){
        GetAllMovies<DummyMoviesViewModel> g;
        g.execute();
    }
}
int main() {
    for (std::string line; std::cout << "APP > " && std::getline(std::cin, line); )
    {
        if (!line.empty()) { process(line); }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
