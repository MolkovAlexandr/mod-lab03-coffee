// Copyright 2024 MolkovAlexandr

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include<string>
#include<vector>

enum States { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
	int cash;
	std::vector<std::string>menu;
	std::vector<int>prices;
	States state;
 public: 
	Automata();
	void on();
	void off();
	void coin(int cash);
	void getMenu(const std::vector<std::string>& menu,
const std::vector<int>& prices);
	States getState();
	void choice(int position);
	bool check(int position);
	void cancel();
	void cook(int position);
	void finish();
};
#endif //INCLUDE_AUTOMATA_H_
