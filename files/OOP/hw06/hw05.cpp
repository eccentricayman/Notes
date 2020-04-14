#include <iostream>
#include <vector>
#include <string>
#include "Noble.h"
#include "Warrior.h"
using namespace std;
using namespace WarriorCraft;

int main() {
	Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
	
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
	
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
	
    cout << jim << endl;
    cout << lance << endl;
	cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;

    cheetah.runaway();
    cout << art << endl;
	
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}

/////////CODE FOR SINGLE FILE////////////////

// //warrior class
// class Warrior;
// //noble class
// class Noble;

// class Warrior {
// 	friend ostream& operator << (ostream& os, const Warrior& warrior);	
// public:
// 	Warrior(string nm, int str);
	
// 	string getName() const;
// 	int getStrength() const;
// 	Noble* getEmployer();
	
// 	void setName(string &newnm);
// 	void setStrength(int newstr);
// 	void setEmployer(Noble* newnoble);

// 	void runaway();
	
// private:
// 	string name;
// 	int strength;
// 	Noble* employer;
// };

// class Noble {
// 	friend ostream& operator << (ostream& os, const Noble& noble);
// public:
// 	Noble(string newName);
	
// 	string getName() const;
// 	bool getAlive() const;
	
// 	void setName(string &nm);
// 	void setAlive(bool alv);
	
// 	//check if i employ this warrior, returns index if i do
// 	int employed(const Warrior &warrior);
	
// 	//hires a warrior, returns bool for success
//    	bool hire(Warrior &warrior);
	
// 	//fires, returns bool for success
// 	bool fire(Warrior* warrior);

// 	//when one of my warriors runs
// 	void runaway(Warrior* warrior);
	
// 	//gets the combined strength of this noble's army
// 	//returns as int
// 	int armyStrength();
	
// 	//evenly removed amount of army strength spread over all warriors
// 	void armyRemoveStrength(int strength);
	
// 	//battles another noble, affecting army strength and noble life
// 	void battle(Noble &enemy);
	
// private:
// 	string name;
// 	bool alive;
// 	vector<Warrior*> army;
// };

// ostream& operator << (ostream& os, const Warrior& warrior) {
// 	os << warrior.name << ": " << warrior.strength;
// 	return os;
// }

// Warrior::Warrior(string nm, int str) : name(nm), strength(str) {
// 	employer = NULL;
// 	};

// string Warrior::getName() const { return name; }
// int Warrior::getStrength() const { return strength; }
// Noble* Warrior::getEmployer() { return employer; }

// void Warrior::setName(string &newnm) { name = newnm; }
// void Warrior::setStrength(int newstr) { strength = newstr; }
// void Warrior::setEmployer(Noble* newnoble) { employer = newnoble; }

// void Warrior::runaway() {
// 	if (employer != NULL) {
// 		employer->runaway(this);
// 		cout << name << " flees in terror, abandoning his lord, "
// 			 << employer->getName() << endl;
// 		employer = NULL;
// 	}
// }

// ostream& operator << (ostream& os, const Noble& noble) {
// 	os << noble.name << " has an army of "
// 	   << noble.army.size() << endl;
// 	for (size_t a = 0 ; a < noble.army.size() ; a++) {
// 		os << "\t\t" << *noble.army[a];
// 		os << endl;
// 	}
// 	return os;
// }

// Noble::Noble(string newName) : name(newName) {
// 	alive = true;
// 	army = vector<Warrior*>();
// };

// string Noble::getName() const { return name; }
// bool Noble::getAlive() const { return alive; }

// void Noble::setName(string &nm) { name = nm; }
// void Noble::setAlive(bool alv) { alive = alv; }

// int Noble::employed(const Warrior &warrior) {
// 	for (size_t a = 0 ; a < army.size() ; a++) {
// 		if (army[a] == &warrior) {
// 			return a;
// 		}
// 	}
// 	return -1;
// }

// bool Noble::hire(Warrior &warrior) {
// 	//already employed or im ded
// 	if (warrior.getEmployer() || !getAlive()) {
// 		return false;
// 	}
// 	//unemplyoed
// 	else {
// 		Warrior* warriorP = &warrior;
// 		army.push_back(warriorP);
// 		warrior.setEmployer(this);
// 		return true;
// 	}
// }

// bool Noble::fire(Warrior* warrior) {
// 	//find index of warrior if exists
// 	int index = employed(*warrior);
								
// 	//i employ this warrior and im alive
// 	if (index != -1 && getAlive()) {
// 		//move every element above the deleted one down one
// 		for (size_t a = index ; a < army.size() - 1 ; a++) {
// 			army[a] = army[a + 1];
// 		}
// 		//delete the last element
// 		army.pop_back();
// 		//make warrior free
// 		warrior->setEmployer(NULL);
			
// 		cout << warrior->getName() << 
// 			", you're fired! -- " << getName() << endl;
// 		return true;
// 	}
// 	else {
// 		return false;	
// 	}
// }

// void Noble::runaway(Warrior* warrior) {
// 	//find index of warrior if exists
// 	int index = employed(*warrior);

// 	//i employ this warrior and im alive
// 	if (index != -1) {
// 		//move every element above the deleted one down one
// 		for (size_t a = index ; a < army.size() - 1 ; a++) {
// 			army[a] = army[a + 1];
// 		}
// 		//delete the last element
// 		army.pop_back();
// 	}
// }

// int Noble::armyStrength() {
// 	int strength = 0;
// 	for (Warrior* warrior : army) {
// 		strength += warrior->getStrength();
// 	}
// 	return strength;
// }

// void Noble::armyRemoveStrength(int strength) {
// 	//get how much to reomve from each warrior
// 	int perWarrior = strength / army.size();
// 	for (Warrior* warrior : army) {
// 		warrior->setStrength(warrior->getStrength() - perWarrior);
// 	}
// }

// void Noble::battle(Noble &enemy) {
// 	//battle text
// 	cout << getName() << " battles "
// 		 << enemy.getName() << endl;
		
// 	//strengths
// 	int str = armyStrength();
// 	int strEnemy = enemy.armyStrength();
// 		//
// 	//both dead
// 	if (!getAlive() && !enemy.getAlive()) {
// 		cout << "Oh, NO! They're both dead! Yuck!" << endl;
// 	}
// 	//same strength, non 0
// 	else if (str == strEnemy) {
// 		//change army strengths
// 		armyRemoveStrength(strEnemy);
// 		enemy.armyRemoveStrength(str);
// 		//kill nobles
// 		setAlive(false);
// 		enemy.setAlive(false);
			
// 		cout << "Mutual Annihilation: " << getName() << " and " <<
// 			enemy.getName() << " die at each other's hands" << endl;
// 	}
// 	//person starting battle is stronger
// 	else if (str > strEnemy) {
// 		//check if enemy is alive before fight
// 		if (enemy.getAlive()) {
// 			cout << getName() << " defeats " 
// 				 << enemy.getName() << endl;	
// 		}
// 		else {
// 			cout << "He's dead, " << getName() << endl;
// 		}
// 		//update army strengths
// 		armyRemoveStrength(strEnemy);
// 		enemy.armyRemoveStrength(strEnemy);
// 		//enemy noble ded
// 		enemy.setAlive(false);
// 	}
// 	//enemy is stronger
// 	else if (str < strEnemy) {
// 		//check if we're alive before fighting
// 		if (getAlive()) {
// 			cout << enemy.getName() << 
// 				" defeats " << getName() << endl;
// 		}
// 		else {
// 			cout << "He's dead, " << enemy.getName() << endl;
// 		}
// 		//update army strengths
// 		armyRemoveStrength(str);
// 		enemy.armyRemoveStrength(str);
// 		//im ded
// 		setAlive(false);
// 	}
// }
