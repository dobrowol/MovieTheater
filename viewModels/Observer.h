//
// Created by dobrowol on 14.10.2019.
//

#ifndef MOVIETHEATER_OBSERVER_H
#define MOVIETHEATER_OBSERVER_H

template<class Result>
class Observer {
public:
    virtual void handle(const Result &result) = 0;
};


#endif //MOVIETHEATER_OBSERVER_H
