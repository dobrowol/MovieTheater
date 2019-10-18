#include <iostream>
#include "MainActivity.cpp"

using namespace std;


int main() {
    MainActivity commandLine;
    for (std::string line; std::cout << "APP > " && std::getline(std::cin, line);) {

        if (!line.empty()) { commandLine.process(line); }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
