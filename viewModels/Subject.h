//
// Created by dobrowol on 14.10.2019.
//

#ifndef MOVIETHEATER_SUBJECT_H
#define MOVIETHEATER_SUBJECT_H


#include <vector>
#include <memory>
#include <functional>
#include "Observer.h"

template< class Result>
class Subject {
    Result result;
    std::vector<std::shared_ptr<Observer<Result>>> observers;
    std::vector<std::function<void(const Result&)>> lambdas;
public:
    Subject() = default;
    explicit Subject(Result res):result(res){}
    void observe(std::function<void(const Result&)> lambda){
        lambdas.push_back(lambda);
        if(!result.empty()){
            lambda(result);
        }
    }
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
        for(auto lambda : lambdas){
            lambda(result);
        }
    }

    void setValue(Result result){
        this->result = result;
        notify();
    }
};


#endif //MOVIETHEATER_SUBJECT_H
