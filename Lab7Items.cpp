
#include <iomanip>
#include "Lab7Items.h"

using namespace std;

Item::Item()
{
	what = "empty";
	cost = 0;
	addSwim = NULL;
	addMove = NULL;
	addAttack = NULL;
}

Item::Item(string n, int c, int s, int m, int a)
{
	what = n;
	cost = c;
	addSwim = s;
	addMove = m;
	addAttack = a;
}

string Item::getName()
{
	return what;
}

int Item::getCost()
{
	return cost;
}

int Item::getAddedSwim()
{
	return addSwim;
}

int Item::getAddedMove()
{
	return addMove;
}

int Item::getAddedAttack()
{
	return addAttack;
}

std::ostream& operator<<(std::ostream& output, const Item& item)
{
	output << "\tItem: " << item.what << endl;
	if (item.addAttack != 0)
		output << "Adds " << item.addAttack << " to attack power!" << endl;
	if (item.addMove != 0)
		output << "Adds " << item.addMove << " to land movement speed!" << endl;
	if (item.addSwim != 0)
		output << "Adds " << item.addSwim << " to water movement speed!" << endl;
	output << "Cost: " << item.cost << " money." << endl;
	return output;
}
