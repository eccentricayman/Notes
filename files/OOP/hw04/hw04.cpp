//hw04.cpp
//Ayman Ahmed
//this file has nobles and warriors, where nobles can hire warriors
//and makes use of pointers to warriors


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//warrior class
class Warrior;
//noble class
class Noble;

class Warrior {
public:
	Warrior(string nm, int str) : name(nm), 
								   strength(str),
								   employed(false) { };
	
	string getName() { return name; }
	int getStrength() { return strength; }
	bool getEmployed() { return employed; }
	
	void setName(string &newnm) { name = newnm; }
	void setStrength(int newstr) { strength = newstr; }
	void setEmployed(bool emplyd) { employed = emplyd; }
	
	void display() {
		cout << name << ": " << strength;
	}
	
private:
	string name;
	int strength;
	bool employed;
};

class Noble {
public:
	Noble(string newName) : name(newName) {
		alive = true;
		army = vector<Warrior*>();
	};
	
	string getName() { return name; }
	bool getAlive() { return alive; }
	vector<Warrior*>& getArmy() { return army; }
	
	void setName(string &nm) { name = nm; }
	void setAlive(bool alv) { alive = alv; }
	
	void display() {
		cout << name << " has an army of " << army.size() << endl;
		for (size_t a = 0 ; a < army.size() ; a++) {
			cout << "\t\t";
			army[a]->display();
			cout << endl;
		}
	}
	
	//check if i employ this warrior, returns index if i do
	int employed(const Warrior &warrior) {
		for (size_t a = 0 ; a < army.size() ; a++) {
			if (army[a] == &warrior) {
				return a;
			}
		}
		return -1;
	}
	
	//hires a warrior, returns bool for success
	bool hire(Warrior &warrior) {
		//already employed or im ded
		if (warrior.getEmployed() || !getAlive()) {
			return false;
		}
		//unemplyoed
		else {
			Warrior* warriorP = &warrior;
			army.push_back(warriorP);
			warrior.setEmployed(true);
			return true;
		}
	}
	
	//fires, returns bool for success
	bool fire(Warrior &warrior) {
		//find index of warrior if exists
		int index = employed(warrior);
								
		//i employ this warrior and im alive
		if (index != -1 && getAlive()) {
			//move every element above the deleted one down one
			for (size_t a = index ; a < army.size() - 1 ; a++) {
				army[a] = army[a + 1];
			}
			//delete the last element
			army.pop_back();
			//make warrior free
			warrior.setEmployed(false);
			
			cout << warrior.getName() << 
				", you're fired! -- " << getName() << endl;
			return true;
		}
		else {
			return false;	
		}
	}
	
	//gets the combined strength of this noble's army
	//returns as int
	int armyStrength() {
		int strength = 0;
		for (Warrior* warrior : army) {
			strength += warrior->getStrength();
		}
		return strength;
	}
	
	//evenly removed amount of army strength spread over all warriors
	void armyRemoveStrength(int strength) {
		//get how much to reomve from each warrior
		int perWarrior = strength / army.size();
		for (Warrior* warrior : army) {
			warrior->setStrength(warrior->getStrength() - perWarrior);
		}
	}
	
	//battles another noble, affecting army strength and noble life
	void battle(Noble &enemy) {
		//battle text
		cout << getName() << " battles "
			 << enemy.getName() << endl;
		
		//strengths
		int str = armyStrength();
		int strEnemy = enemy.armyStrength();
		
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
	
private:
	string name;
	bool alive;
	vector<Warrior*> army;
};

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

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}
