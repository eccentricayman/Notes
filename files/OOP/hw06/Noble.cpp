#include "Warrior.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {
	
	ostream& operator << (ostream& os, const Noble& noble) {
		os << noble.name << " has an army of "
		   << noble.army.size() << endl;
		for (size_t a = 0 ; a < noble.army.size() ; a++) {
			os << "\t\t" << *noble.army[a];
			os << endl;
		}
		return os;
	}

	Noble::Noble(string newName) : name(newName) {
		alive = true;
		army = vector<Warrior*>();
	};

	string Noble::getName() const { return name; }
	bool Noble::getAlive() const { return alive; }

	void Noble::setName(string &nm) { name = nm; }
	void Noble::setAlive(bool alv) { alive = alv; }

	int Noble::employed(const Warrior &warrior) {
		for (size_t a = 0 ; a < army.size() ; a++) {
			if (army[a] == &warrior) {
				return a;
			}
		}
		return -1;
	}

	bool Noble::hire(Warrior &warrior) {
		//already employed or im ded
		if (warrior.getEmployer() || !getAlive()) {
			return false;
		}
		//unemplyoed
		else {
			Warrior* warriorP = &warrior;
			army.push_back(warriorP);
			warrior.setEmployer(this);
			return true;
		}
	}

	bool Noble::fire(Warrior* warrior) {
		//find index of warrior if exists
		int index = employed(*warrior);
								
		//i employ this warrior and im alive
		if (index != -1 && getAlive()) {
			//move every element above the deleted one down one
			for (size_t a = index ; a < army.size() - 1 ; a++) {
				army[a] = army[a + 1];
			}
			//delete the last element
			army.pop_back();
			//make warrior free
			warrior->setEmployer(NULL);
			
			cout << warrior->getName() << 
				", you're fired! -- " << getName() << endl;
			return true;
		}
		else {
			return false;	
		}
	}

	void Noble::runaway(Warrior* warrior) {
		//find index of warrior if exists
		int index = employed(*warrior);

		//i employ this warrior and im alive
		if (index != -1) {
			//move every element above the deleted one down one
			for (size_t a = index ; a < army.size() - 1 ; a++) {
				army[a] = army[a + 1];
			}
			//delete the last element
			army.pop_back();
		}
	}

	int Noble::armyStrength() {
		int strength = 0;
		for (Warrior* warrior : army) {
			strength += warrior->getStrength();
		}
		return strength;
	}

	void Noble::armyRemoveStrength(int strength) {
		//get how much to reomve from each warrior
		int perWarrior = strength / army.size();
		for (Warrior* warrior : army) {
			warrior->setStrength(warrior->getStrength() - perWarrior);
		}
	}

	void Noble::battle(Noble &enemy) {
		//battle text
		cout << getName() << " battles "
			 << enemy.getName() << endl;
		
		//strengths
		int str = armyStrength();
		int strEnemy = enemy.armyStrength();
		//
		//both dead
		if (!getAlive() && !enemy.getAlive()) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		//same strength, non 0
		else if (str == strEnemy) {
			//change army strengths
			armyRemoveStrength(strEnemy);
			enemy.armyRemoveStrength(str);
			//kill nobles
			setAlive(false);
			enemy.setAlive(false);
			
			cout << "Mutual Annihilation: " << getName() << " and " <<
				enemy.getName() << " die at each other's hands" << endl;
		}
		//person starting battle is stronger
		else if (str > strEnemy) {
			//check if enemy is alive before fight
			if (enemy.getAlive()) {
				cout << getName() << " defeats " 
					 << enemy.getName() << endl;	
			}
			else {
				cout << "He's dead, " << getName() << endl;
			}
			//update army strengths
			armyRemoveStrength(strEnemy);
			enemy.armyRemoveStrength(strEnemy);
			//enemy noble ded
			enemy.setAlive(false);
		}
		//enemy is stronger
		else if (str < strEnemy) {
			//check if we're alive before fighting
			if (getAlive()) {
				cout << enemy.getName() << 
					" defeats " << getName() << endl;
			}
			else {
				cout << "He's dead, " << enemy.getName() << endl;
			}
			//update army strengths
			armyRemoveStrength(str);
			enemy.armyRemoveStrength(str);
			//im ded
			setAlive(false);
		}
	}
	
}
