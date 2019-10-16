cmake_minimum_required(VERSION 3.15)
project(MovieTheater)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(GoogleTests)
add_executable(MovieTheater main.cpp viewModels/MoviesTheatersViewModel.cpp viewModels/Subject.cpp viewModels/Subject.h viewModels/Observer.cpp viewModels/Observer.h)