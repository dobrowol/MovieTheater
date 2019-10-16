//
// Created by dobrowol on 14.10.2019.
//

#ifndef MOVIETHEATER_SUBJECT_H
#define MOVIETHEATER_SUBJECT_H


#include <vector>
#include <memory>
#include "Observer.h"

template< class Result>
class Subject {
    Result result;
    std::vector<std::shared_ptr<Observer<Result>>> observers;
public:
    void observe(std::shared_ptr<Observer<Result>> observer){
        observers.push_back(observer);
        if(!result.empty()){
            observer->handle(result);
        }
    }

    void notify() {
        for(auto observer : observers){
            observer->handle(result);
        }
    }

    void setValue(Result result){
        this->result = result;
        notify();
    }
};


#endif //MOVIETHEATER_SUBJECT_H
