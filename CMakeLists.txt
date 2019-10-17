cmake_minimum_required(VERSION 3.15)
project(MovieTheater)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(GoogleTests)
add_executable(MovieTheater main.cpp viewModels/MoviesTheatersViewModel.h viewModels/Subject.h viewModels/Observer.h Command.h CommandLine.cpp commands/GetTheaterForMovie.h)