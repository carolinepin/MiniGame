#ifndef LAB7HEADER_H
#define LAB7HEADER_H

#include <iostream>
#include "Lab7Items.h"


using namespace std;

class MonsterBase {
	friend std::ostream& operator << (std::ostream& output, const MonsterBase& mon);

private:
	std::string name;
	int healthPoints;
	int level;
	int walkingSpeed;
	int attack;
public:
	MonsterBase();
	MonsterBase(std::string, int, int, int, int);
	void setName(std::string);
	void setHP(int hp);
	void setLevel(int);
	void setSpeed(int);
	void setAttack(int);
	virtual int combatAttack();
	std::string getName();
	int getHP();
	int getLevel();
	int getSpeed();
	int getAttack();
};

void combat(MonsterBase* combatant1, MonsterBase* combatant2);

#endif