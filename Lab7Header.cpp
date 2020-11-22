#include <iostream>
#include "Lab7Header.h"

using namespace std;


MonsterBase::MonsterBase()
{
	name = "The Big Cheese";
	level = 1;
	walkingSpeed = 1;
	attack = 1;
}

MonsterBase::MonsterBase(std::string n, int hp, int l, int w, int a)
{
	setName(n);
	setHP(hp);
	setLevel(l);
	setSpeed(w);
	setAttack(a);
}

void MonsterBase::setName(std::string n)
{
	name = n;
}

void MonsterBase::setHP(int hp)
{
	healthPoints = hp;
}

void MonsterBase::setLevel(int l)
{
	level = l;
}

void MonsterBase::setSpeed(int s)
{
	walkingSpeed = s;
}

void MonsterBase::setAttack(int a)
{
	attack = a;
}

int MonsterBase::combatAttack()
{
	cout << "Goop burns your flesh when the monster attacks! Take " << attack * level << " points of damage" << endl;
	return attack*level;
}

std::string MonsterBase::getName()
{
	return name;
}

int MonsterBase::getHP()
{
	return healthPoints;
}

int MonsterBase::getLevel()
{
	return level;
}

int MonsterBase::getSpeed()
{
	return walkingSpeed;
}

int MonsterBase::getAttack()
{
	return attack;
}

std::ostream& operator<<(std::ostream& output, const MonsterBase& mon)
{
	output << "\tName: " << mon.name << endl <<
		"\tLevel: " << mon.level << endl << endl;
	return output;
}

void combat(MonsterBase* combatant1, MonsterBase* combatant2)
{
	cout << "Entered Combat!" << endl;
	cout << combatant1->getName() << " vs " << combatant2->getName() << endl;
	for (int i = 0; i < 100; i++) {
		cout << "----------------------------------------------------------------" << endl;
		cout << combatant1->getName() << " HP: " << combatant1->getHP() << "  ||||  " << combatant2->getName() << " HP: " << combatant2->getHP() << endl;
		if (combatant1->getSpeed() > combatant2->getSpeed()) {
			combatant2->setHP(combatant2->getHP() - combatant1->combatAttack());
			if (combatant2->getHP() <= 0) {
				i = 100;
				break;}
			combatant1->setHP(combatant1->getHP() - combatant2->combatAttack());
			if (combatant1->getHP() <= 0) {
				i = 100;
				break;
			}
		}
		if (combatant2->getSpeed() > combatant1->getSpeed()) {
			combatant1->setHP(combatant1->getHP() - combatant2->combatAttack());
			if (combatant1->getHP() <= 0) {
				i = 100;
				break;
			}
			combatant2->setHP(combatant2->getHP() - combatant1->combatAttack());
			if (combatant2->getHP() <= 0) {
				i = 100;
				break;
			}
		}
	
	}
}

