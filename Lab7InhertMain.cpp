#include <iostream>
#include "Lab7Header.h"
#include "Lab7SpecificMons.h"

using namespace std;

int main()
{
	int place = 0;
	string name = " ";
	int buy = 0;
	int originalHP = 0;
	int loot = 0;
	cout << "Welcome to Monster Land" << endl;
	cout << "Your actions will determine how successful you are. There are 3 areas you can chose from the Town, the Cove, or the Dungeon. Some basic rules of thumb, don’t attack the friendly monsters of the town, don’t befriend the dungeon monsters unless you are really really good at talking to them, and be warily of the water monsters. Beginner tip, check out the town! The monsters there can help you out. If you get attacked by a monster that is higher than your level, you’ll die. And dungeon monsters are particularly deadly" << endl;
	cout << endl << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Enter a name for your monster!" << endl;
	cin >> name;
	FriendMonster player{ name, 10,  1,  1,  2,  1,  10 };
	FriendMonster shop{ "ShopKeep", 100,  10,  0,  10,  7,  100 };
	FriendMonster wanderer{ "Suzy",   50,  5,  8,  6,  10,  10 };
	FriendMonster oldMan{ "Old Man Jankins" , 10, 1,  1,  0,  2,  30 };
	WaterMonster siren{ "Siren",  20,  1,  0,  2,  10 };
	WaterMonster selkie{ "Selkie", 10, 1,  5,  1, 5 };
	DungeonMonster dragon{ "Dragon", 30,  1,  8,  4,  3 };
	DungeonMonster skeleton{ "Skeleton",  10, 1,  2,  1, 2 };
	MonsterBase slime{ "Slime", 5,1,5,1 };
	MonsterBase* combatPtr1{ &player };
	MonsterBase* combatPtr2{ &player };
	Item emptySlot1; Item emptySlot2; Item emptySlot3; Item emptySlot4; Item emptySlot5;
	Item inventory[5] = { emptySlot1, emptySlot2, emptySlot3, emptySlot4, emptySlot5 };
	Item temp;
	Item lantern("Lanturn", 20, 0, 0, 0);
	Item flippers("Flippers", 10, 0, 10, 0);
	Item sword("Big Sword", 15, 0, 0, 10);
	Item shoes("Running Shoes", 20, 0, 10, 0);
	Item sunglasses("Rad Sun Glasses", 50, 10, 10, 10);
	Item shopInventory[5] = { lantern, flippers, sword, shoes, sunglasses };

	do {

		do {
			cout << "---------------------------------------------------------------------------" << endl;
			cout << player;
			cout << "\t Money: " << player.getMoney() << endl;
			if (player.getLevel() == 10)
				cout << "Max Level! Not much left to do" << endl;
			cout << "Where do you want to go?" << endl;
			cout << "1)Town \n2)Cove(Intermediate) \n3) Dungeon(Advanced) \n4)Slime Forest(Beginner) \n5)Quit" << endl;
			cin >> place;
			if (!cin.good() || place <= 0 || place > 5) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Retry" << endl;
				place = NULL;
			}
		} while (!cin.good() || place < 1 || place > 5 || place == NULL);

		if (place == 1) {
			randomEncounter(player);
			cout << endl << "PRESS ENTER TO CONTINUE" << endl;
			system("pause");
			int choice = 0;
			do {
				cout << "Welcome to Town! Here are a few monsters here to talk to " << endl;

				cout << "1)" << shop;
				cout << "2)" << wanderer;
				cout << "3)" << oldMan;
				cout << "Who do you want to talk to?" << endl;
				cin >> choice;
				if (!cin.good() || choice <= 0 || choice > 3) {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Retry" << endl;
					choice = NULL;
				}
				if (choice == 1) {
					int npc1 = 0;
					do {
						cout << "Well howdy! I'm the shop keep for this town. What can I do you for? " << endl;
						cout << "1) Buy \n2) Conversation \n3) Goodbye" << endl;
						cin >> npc1;
						if (!cin.good() || npc1 <= 0 || npc1 > 3) {
							cin.clear();
							cin.ignore(256, '\n');
							cout << "\"Huh? Speak up, kid, I can't hear you when you enter the wrong input like that!\"" << endl;
							npc1 = NULL;
						}
					} while (!cin.good() || npc1 < 1 || npc1> 3 || npc1 == NULL);
					if (npc1 == 1) {
						cout << "\"Sure, kid. This is what we got\"" << endl;
						do {
							for (int i = 0; i < 5; i++) {
								cout << "\t" << i + 1 << ") " << shopInventory[i] << endl;
								if (i == 4)
									cout << "6) Exit" << endl;
							}
							do {
								cout << "\"What do you want?\"" << endl;
								cin >> buy;
								if (!cin.good() || buy <= 0 || buy > 6) {
									cin.clear();
									cin.ignore(256, '\n');
									cout << "\"Huh? Speak up, kid, I can't hear you when you enter the wrong input like that! Enter a number 1 through 5.\"" << endl;
									npc1 = NULL;
								}
							} while (!cin.good() || buy < 1 || buy> 6 || buy == NULL);
							if (buy >= 1 && buy < 6) {
								if (purchase(player, shopInventory[buy - 1]) == true) {
									temp = inventory[buy - 1];
									inventory[buy - 1] = shopInventory[buy - 1];
									shopInventory[buy - 1] = temp;
									if (buy == 3)
										player.setAttack(player.getAttack() + shopInventory[buy - 1].getAddedAttack());
									if (buy == 4)
										player.setSpeed(player.getSpeed() + shopInventory[buy - 1].getAddedMove());
									if (buy == 5) {
										player.setAttack(player.getAttack() + shopInventory[buy - 1].getAddedAttack());
										player.setSpeed(player.getSpeed() + shopInventory[buy - 1].getAddedMove());
									}
									system("pause");
								}
							}
							if (buy == 6) {
								cout << "\"Alright, good luck out there!" << endl;
								system("pause");
							}
						} while (buy != 6);
					}
					if (npc1 == 2) {
						cout << "\"Well shoot, yeah I got some time to kill\"" << endl;
						cout << "You two have a pleasant coversation" << endl;
						player.setFriendliness(player.getFriendliness() + 2);
						system("pause");

					}
					if (npc1 == 3) {
						cout << "Alright, goodbye!" << endl;
						system("pause");
					}
				}
				if (choice == 2) {
					int npc2 = 0;
					cout << "Hey there. You still got that money I gave you?" << endl;
					do {
						cout << "1) \"What Money?\" " << endl;
						cout << "2) \"Yeah, what about it?\"" << endl;
						cin >> npc2;
						if (!cin.good() || npc2 <= 0 || npc2 > 2) {
							cin.clear();
							cin.ignore(256, '\n');
							cout << "\"You want to try saying that again?\"" << endl;
							npc2 = NULL;
						}
					} while (!cin.good() || npc2 < 1 || npc2> 2 || npc2 == NULL);
					if (npc2 == 1) {
						cout << "\"Exactly! Haha, I knew I liked you for a reason. See ya!\"" << endl;
						player.setFriendliness(player.getFriendliness() + 2);
						system("pause");
					}
					if (npc2 == 2) {
						cout << "\"Yeah I need it back before you submit it as evidence. Thanks for holding it for me\"" << endl;
						cout << "Aw man! You lost 2 money! Next time be cool and pick the other dialog option\"" << endl;
						player.setMoney(player.getMoney() - 2);
						system("pause");
					}
				}
				if (choice == 3) {
					if (player.getFriendliness() < 10) {
						cout << "\"Nyegh! Leave me alone, youngster. Can't you see I'm trying to mope here? Scram!\"" << endl;
					}
					if (player.getFriendliness() >= 10) {
						int happen = 0;
						cout << "\".......\"" << endl;
						cout << "\"..... As annoying as you are, thanks for checking up on me.\"" << endl;
						if (happen < 1) {
							cout << "\"Here, take this. It'll help keep you alive\"" << endl;
							cout << "You gained the Heart Amulate! Gain +10 to your health!" << endl;
							player.setHP(player.getHP() + 10);
							happen++;
						}
						system("pause");

					}
				}
			} while (!cin.good() || choice < 1 || choice> 4 || choice == NULL);
		}
		if (place == 2) {
			randomEncounter(player);
			system("pause");
			cout << "Here is ShipWreck Cove, have fun on the beach and be careful" << endl;
			cout << "Monsters in area" << endl;
			cout << siren;
			cout << selkie;
			cout << "Looks like you can't reach them yet because you don't have the swim speed! The shop might have something for that" << endl;
			cout << "Siren's swim speed is " << siren.getSpeed() << endl;
			cout << "Selkie's swim speed is " << selkie.getSpeed() << endl;
			bool flippersCheck = false;
			for (int k = 0; k < 5; k++) {
				if (inventory[k].getName() == "Flippers")
					flippersCheck = true;
			}
			if (flippersCheck == false)
				cout << "You can't swim like that! Go get proper swim equipment at the shop!" << endl;
			if (flippersCheck == true) {
				int fight1 = 0;
				cout << "Alright, which monster do you want to fight?" << endl;
				cout << "1) " << siren << endl;
				cout << "2) " << selkie << endl;
				do {
					cin >> fight1;
					if (!cin.good() || fight1 <= 0 || fight1 > 2) {
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Retry" << endl;
						fight1 = NULL;
					}
				} while (!cin.good() || fight1 < 1 || fight1> 2 || fight1 == NULL);
				if (fight1 == 1) {
					combatPtr2 = &siren;
					originalHP = combatPtr2->getHP();
				}
				if (fight1 == 2) {
					combatPtr2 = &selkie;
					originalHP = combatPtr2->getHP();
				}
				combat(combatPtr1, combatPtr2);
				if (combatPtr1->getHP() <= 0) {
					cout << "You were defeated :(. You black out just before hearing Suzy drag your body out of this mess" << endl;
					cout << endl << "You return back to the crossroads, pockets suddenly a lot lighter without any coin" << endl;
					player.setMoney(0);
					player.setHP(10);
					system("pause");
				}
				if (combatPtr2->getHP() <= 0) {
					loot = combatPtr2->getLevel() * 2;
					cout << "You defeated the monster! Gain 1 level and " << loot << " money" << endl;
					player.setMoney(player.getMoney() + loot);
					combatPtr1->setLevel(player.getLevel() + 1);
					combatPtr1->setHP(player.getHP() + 5);
					cout << "..... On your way out, you notice the other monsters in the area whispering to themselves.... " << endl;
					cout << "It seems they are preparing for your return with better stratagies. This type of monster +1 to their level" << endl;
					combatPtr2->setLevel(combatPtr2->getLevel() + 1);
					combatPtr2->setHP(originalHP);
					system("pause");
				}
			}
		}
		if (place == 3) {
			randomEncounter(player);
			system("pause");
			cout << "Are you sure about this? The monsters here can kill you pretty fast. Be careful!" << endl;
			cout << "Monsters in area" << endl;
			cout << dragon;
			cout << skeleton;
			bool lanturnCheck = false;
			for (int j = 0; j < 5; j++) {
				if (inventory[j].getName() == "Lanturn")
					lanturnCheck = true;
			}
			if (lanturnCheck == false)
				cout << "It's too dark to see, maybe something in the shop has an item to help you see" << endl;
			if (lanturnCheck == true) {
				int fight = 0;
				cout << "Alright, which monster do you want to fight?" << endl;
				cout << "1) " << dragon << endl;
				cout << "2) " << skeleton << endl;
				do {
					cin >> fight;
					if (!cin.good() || fight <= 0 || fight > 2) {
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Retry" << endl;
						fight = NULL;
					}
				} while (!cin.good() || fight < 1 || fight> 2 || fight == NULL);
				if (fight == 1) {
					combatPtr2 = &dragon;
					originalHP = combatPtr2->getHP();
				}
				if (fight == 2) {
					combatPtr2 = &skeleton;
					originalHP = combatPtr2->getHP();
				}
				combat(combatPtr1, combatPtr2);
				if (combatPtr1->getHP() <= 0) {
					cout << "You were defeated :(. You black out just before hearing Suzy drag your body out of this mess" << endl;
					cout << endl << "You return back to the crossroads, pockets suddenly a lot lighter without any coin" << endl;
					player.setMoney(0);
					player.setHP(10);
					system("pause");
				}
				if (combatPtr2->getHP() <= 0) {
					loot = combatPtr2->getLevel() * 2;
					cout << "You defeated the monster! Gain 1 level and " << loot << " money" << endl;
					player.setMoney(player.getMoney() + loot);
					combatPtr1->setLevel(player.getLevel() + 1);
					combatPtr1->setHP(player.getHP() + 5);
					cout << "..... On your way out, you notice the other monsters in the area whispering to themselves.... " << endl;
					cout << "It seems they are preparing for your return with better stratagies. This type of monster +1 to their level" << endl;
					combatPtr2->setLevel(combatPtr2->getLevel() + 1);
					combatPtr2->setHP(originalHP);
					system("pause");
				}
			}
		}
		if (place == 4) {
			randomEncounter(player);
			system("pause");
			cout << "Welcome to slime forest, home of the slimes!" << endl;
			cout << "Monsters in area:" << endl;
			cout << slime;
			cout << slime;

			int fight2 = 0;
			cout << "Alright, which monster do you want to fight?" << endl;
			cout << "1) " << slime << endl;
			cout << "2) " << slime << endl;
			do {
				cin >> fight2;
				if (!cin.good() || fight2 <= 0 || fight2 > 2) {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Retry" << endl;
					fight2 = NULL;
				}
			} while (!cin.good() || fight2 < 1 || fight2> 2 || fight2 == NULL);
			if (fight2 == 1) {
				combatPtr2 = &slime;
				originalHP = combatPtr2->getHP();
			}
			if (fight2 == 2) {
				combatPtr2 = &slime;
				originalHP = combatPtr2->getHP();
			}
			combat(combatPtr1, combatPtr2);
			if (combatPtr1->getHP() <= 0) {
				cout << "You were defeated :(. You black out just before hearing Suzy drag your body out of this mess" << endl;
				cout << endl << "You return back to the crossroads, pockets suddenly a lot lighter without any coin" << endl;
				player.setMoney(0);
				player.setHP(10);
				system("pause");
			}
			if (combatPtr2->getHP() <= 0) {
				loot = combatPtr2->getLevel() * 2;
				cout << "You defeated the monster! Gain 1 level and " << loot << " money" << endl;
				player.setMoney(player.getMoney() + loot);
				combatPtr1->setLevel(player.getLevel() + 1);
				combatPtr1->setHP(player.getHP() + 5);
				cout << "The other slimes are not sentient enough to react to the fight. You leave without issue" << endl;
				combatPtr2->setHP(originalHP);
				system("pause");
			}

		}

		if (place == 5) {
			cout << "Hope you had fun! Quitting..... " << endl;

		}
	} while (place != 5);
}