# 'Google_test' is the subproject name
project(Google_tests)

find_package(Boost COMPONENTS regex  REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run DummyMoviesViewModelTest.cpp MoviesTheatersViewModelTest.cpp ReserveSeatsForMovieTheaterTest.cpp ObserverMock.h)
target_link_libraries(Google_Tests_run gtest gtest_main gmock ${Boost_LIBRARIES})