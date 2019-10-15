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
template<class ViewModel>
class GetAllMovies {
	ViewModel viewModel;
public:
	GetAllMovies(){};
	virtual ~GetAllMovies(){};
	void execute(){
		auto callback = [&](const std::vector<std::string>& res){
			this->processData(res);};
		viewModel.getAllMovies(callback);
	}
	void processData(const std::vector<std::string>& res){
		for(std::string s : res){
			std::cout<<s<<std::endl;
		}
	}
};

#endif /* COMMANDS_GETALLMOVIES_H_ */
