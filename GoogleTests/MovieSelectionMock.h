//
// Created by dobrowol on 19.10.2019.
//

#ifndef MOVIETHEATER_MOVIESELECTIONMOCK_H
#define MOVIETHEATER_MOVIESELECTIONMOCK_H

#include "gmock/gmock.h"
#include "../commands/SelectMovie.h"

class MovieSelectionMock : public SelectMovie::MovieSelectionInterface {
public:
    MOCK_METHOD(void, setMovie, (std::string), (override));
};

#endif //MOVIETHEATER_MOVIESELECTIONMOCK_H
