// Copyright 2024 MolkovAlexandr

#include<iostream>
#include"Automata.h"

int main() {
 setlocale(LC_ALL, "1251");

 Automata automata;

 int sum = 0;
 int decision = 0;
 int option = 0;

 automata.on();

 while (true) {
 std::cout << "Введите зачисляемую сумму: "; std::cin >> sum;

 automata.coin(sum);
 automata.getMenu({"Espresso", "Latte", "Americano", "Lungo"},
 {50, 65, 55, 70});

 std::cout << "Введите номер желаемой позиции: "; std::cin >> decision;

 automata.choice(decision);
 if (automata.check(decision)) {
 automata.cook(decision);
 automata.finish();
 } else {
 std::cout << "Пополнить баланс? (1) да, (2) нет: "; std::cin >> option;
 switch (option) {
 case 1: {
 break;
 }
 case 2: {
 automata.cancel();
 break;
 }
 default: {
 std::cout << "Невозможная операция";
 exit(0);
 break;
 }
 }
  }
 }
 return 0;
}
