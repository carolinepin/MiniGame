#include <iostream>
#include "Lab7Header.h"
#include "Lab7Items.h"

#ifndef LAB7SPECIFICMONSTER_H
#define LAB7SPECIFICMONSTER_H

class WaterMonster : public MonsterBase {
private:
	int swimSpeed;
public:
	WaterMonster(std::string n, int hp, int l, int w, int a, int ss);
	int combatAttack();
	void setSwim(int);
	int getSpeed();
};

class FriendMonster : public MonsterBase {
	friend void randomEncounter(FriendMonster& thing);
private:
	int friendliness;
	int money;
public:
	FriendMonster(std::string n, int hp,  int l, int w, int a, int f, int m);
	int combatAttack();
	void setFriendliness(int);
	void setMoney(int);
	int getFriendliness();
	int getMoney();
};

class DungeonMonster : public MonsterBase {
private:
	int specialAttack;
public:
	DungeonMonster(std::string name,int hp, int l, int w, int a, int sp);
	int combatAttack();
	void setSpecial(int);
	int getSpecial();

};
bool purchase(FriendMonster& player, Item& wanted);

#endif