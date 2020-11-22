#ifndef LAB7ITEMS_H
#define LAB7ITEMS_H

#include <iostream>

class Item {
	friend std::ostream& operator << (std::ostream& output, const Item& item);
private:
	std::string what;
	int cost;
	int addSwim;
	int addMove;
	int addAttack;
public:
	Item();
	Item(std::string, int c, int s, int m, int a);
	std::string getName();
	int getCost();
	int getAddedSwim();
	int getAddedMove();
	int getAddedAttack();
};

#endif