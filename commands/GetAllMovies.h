/*
 * GetAllMovies.h
 *
 *  Created on: 14 paź 2019
 *      Author: dobrowol
 */

#ifndef COMMANDS_GETALLMOVIES_H_
#define COMMANDS_GETALLMOVIES_H_
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../viewModels/Observer.h"
template<class ViewModel>
class GetAllMovies : public Observer<std::vector<std::string>>, std::enable_shared_from_this<GetAllMovies<ViewModel>>{
	ViewModel viewModel;
public:
	GetAllMovies() = default;
	virtual ~GetAllMovies() = default;
	void execute(){
		auto callback = [&](const std::vector<std::string>& res){
			this->handle(res);};
		viewModel.getAllMovies()->observe(this->shared_from_this());
	}
	void handle(const std::vector<std::string>& res) override {
		for(const std::string& s : res){
			std::cout<<s<<std::endl;
		}
	}
};

#endif /* COMMANDS_GETALLMOVIES_H_ */
