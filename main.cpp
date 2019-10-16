#include <iostream>
#include "CommandLine.cpp"
using namespace std;


int main() {
    CommandLine commandLine;
    for (std::string line; std::cout << "APP > " && std::getline(std::cin, line); )
    {
        
        if (!line.empty()) { commandLine.process(line); }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
