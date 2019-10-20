cmake_minimum_required(VERSION 3.15)
project(MovieTheater)

find_package(Boost COMPONENTS regex  REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(GoogleTests)
add_executable(MovieTheater main.cpp viewModels/MoviesTheatersViewModel.h viewModels/Subject.h viewModels/Observer.h Command.h MainActivity.cpp commands/GetTheaterForMovie.h database/Movie.h database/Database.h database/MovieTheaterSeats.h database/MovieTheaterSeatsDAO.h commands/GetSeatsForMovieTheater.h commands/ReserveSeatsForMovieTheater.h commands/SelectMovie.h commands/SelectTheater.h)
target_link_libraries(MovieTheater ${Boost_LIBRARIES})