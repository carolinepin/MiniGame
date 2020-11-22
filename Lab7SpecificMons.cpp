#include <iostream>
#include "Lab7SpecificMons.h"
#include <time.h>
using namespace std;



WaterMonster::WaterMonster(string n, int hp,  int l, int w, int a, int ss) 
	: MonsterBase(n, hp, l, w, a) 
{
	setSwim(ss); 
}

int WaterMonster::combatAttack()
{
	int slash = 0;
	slash = this->getAttack() * this->getLevel();
	cout << "You get slapped in the face with a set of fins! You take " << slash << " points of damage!" <<endl;
	return slash;

}


void WaterMonster::setSwim(int s)
{
	swimSpeed = s;
}

int WaterMonster::getSpeed()
{
	return swimSpeed;
}

FriendMonster::FriendMonster(std::string n, int hp, int l, int w, int a, int f, int m)
: MonsterBase(n, hp, l, w, a) 
{
	setFriendliness(f); setMoney(m); 
}

int FriendMonster::combatAttack()
{
	int slash= 0;
	slash = this->getLevel() * this->getAttack();
	cout << "You hit it for " << slash << " points of damage!" << endl;
	return slash;
}


void FriendMonster::setFriendliness(int f)
{
	friendliness = f;
}

void FriendMonster::setMoney(int m)
{
	money = m;
}

int FriendMonster::getFriendliness()
{
	return friendliness;
}

int FriendMonster::getMoney()
{
	return money;
}

DungeonMonster::DungeonMonster(std::string name,int hp, int l, int w, int a, int sp)
	: MonsterBase(name, hp, l, w, a) 
{
	setSpecial(sp);
}



int DungeonMonster::combatAttack()
{
	int slash = 0;
	slash = getAttack() * getLevel() + specialAttack;
	cout << "Special attack! Brace yourself! You take " << slash << " points of damage!" << endl;
	return slash;
}


void DungeonMonster::setSpecial(int sp)
{
	specialAttack = sp;
}

int DungeonMonster::getSpecial()
{
	return specialAttack;
}

void randomEncounter(FriendMonster& thing)
{
	srand(time(NULL));
	int num;
	num = rand() % 6 + 1;
	cout << num << endl;
	cout << endl << endl;
	if (num == 1 && thing.money > 0) {
		cout << "\tBandits robbed you on the road!\n++Lose 5 money++" << endl;
		thing.money = thing.money - 5;
		if (thing.money < 0)
			thing.money = 0;
	}
	if (num == 1 && thing.money < 1) {
		cout << "\tBandits were going to rob you but after an awkward encounter when you turned out your pockets, they give you some pity cash." << endl;
		cout << "++Gain 2 money++" << endl;
		thing.money += 2;
	}
	if (num > 1 && num < 5)
		cout << "After peaceful travel, you arrive at your destination" << endl;
	if (num == 5) {
		cout << "\tSuzy Appeared!" << endl;
		cout << "\t\" Hey, how's it going man? I need to get rid of some cash, here take this and don't ask any questions\" " << endl;
		cout << "++You recieved 2 money!++" << endl;
		thing.money += 2;
	}
	if (num == 6) {
		cout << "\tHuh? Whats that on the side of the road? You dig in the dirt and find a treasure chest!" << endl;
		cout << "++Wow! You found 5 gold!++" << endl;
		thing.money += 5;
	}
	cout << endl << endl;
}

bool purchase(FriendMonster& player, Item& wanted)
{
	bool bought = false;
	if (player.getMoney() < wanted.getCost()) {
		cout << "\" Sorry, you can't afford that! Come back when you got the Money for it\"" << endl;
	}
	if (player.getMoney() >= wanted.getCost()) {
		if (wanted.getCost() != 0) {
			int left = 0;
			left = player.getMoney() - wanted.getCost();
			player.setMoney(left);
			cout << "You purchased the " << wanted.getName() << " for " << wanted.getCost() << " money!" << endl;
			cout << "Total cash remaining: " << player.getMoney() << endl;
			bought = true;
		}
		if (wanted.getCost() == 0)
			cout << "\" There isn't anything there to buy!\"" << endl;
	}
	return bought;
}
