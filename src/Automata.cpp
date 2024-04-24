// Copyright 2024 MolkovAlexandr

#include<iostream>
#include"Automata.h"

Automata::Automata() {
	state = OFF;
	cash = 0;
}

void Automata::on() {
	state = WAIT;
}

void Automata::off() {
	state = OFF;
}

void Automata::coin(int cash) {
	this->cash += cash;
}

void Automata::getMenu(const std::vector<std::string>&menu, 
const std::vector<int>&prices) {
	this->menu = menu; this->prices = prices;
}

States Automata::getState() {
	return state;
}

void Automata::choice(int position) {
	if (position >= 0 && position < menu.size()) {
		state = CHECK;
		std::cout << "Выбрана позиция " << menu.at(position) << std::endl;
	} else {
		std::cout << "Невозможная операция" << std::endl;
	       }
}

bool Automata::check(int position) {
	if (cash >= prices.at(position)) {
		state = COOK;
		std::cout << "Приготовление начато" << std::endl;
		return true;
	} else {
		std::cout << "Недостаточно " << prices.at(position) - cash
			<< " для покупки позиции " << menu.at(position) << std::endl;
		return false;
	}
}

void Automata::cancel() {
	state = WAIT;
	cash = 0;
	std::cout << "Операция отменена" << std::endl;
}

void Automata::cook(int position) {
	state = WAIT;
	cash -= prices.at(position);
	std::cout << "Напиток готов, сдача: " << cash << std::endl;
	cash = 0;
}

void Automata::finish() {
	state = WAIT;
	cash = 0;
	std::cout << "Операция успешно завершена" << std::endl;
}
