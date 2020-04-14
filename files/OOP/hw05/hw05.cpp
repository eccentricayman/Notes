//hw05.cpp
//Ayman Ahmed
//manages nobles and warriors using dynamic memory and errors
//code is unoptimized because of requirement that we only
//store nobles/warriors in a vector and nowhere else

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//declarations
const string INPUTFILE = "nobleWarriors.txt";
//warrior class
class Warrior;
//class noble
class Noble;
//check if warrior exists
bool warriorExists(const string& warriorname, vector<Warrior*>& warriors);
//check if noble exists
bool nobleExists(const string& noblename, vector<Noble*>& nobles);
//returns noble given name, returns null otherwise
Noble* findNoble(const string& name, vector<Noble*>& nobles);

//classes
//class warrior
class Warrior {
public:
	Warrior(string nm, int str) : name(nm), strength(str), liege("") { }

	string getName() { return name; }
	int getStrength() { return strength; }
	string getLiege() { return liege; }

	void setName(string nm) { name = nm; }
	void setStrength(int str) { strength = str; }
	void setLiege(string noble) { liege = noble; }

	friend ostream &operator << (ostream &o, const Warrior &warrior) {
		o << warrior.name << ": " << warrior.strength;
		return o;
	}
private:
	string name;
	int strength;
	//name of owner
	string liege;
};

class Noble {
public:
	Noble(string nm) : name(nm), alive(true), armySize(0) {	}

	string getName() { return name; }
	bool getAlive() { return alive; }
	int getArmySize() { return armySize; }

	void setName(string nm) { name = nm; }
	void setAlive(bool isalive) { alive = isalive; }
	void setArmySize(int size) { armySize = size; }
	
	void hire(const string& warriorname, vector<Warrior*>& warriors) {
		for (Warrior* warrior: warriors) {
			if (warrior->getName() == warriorname) {
				//check if warrior already hired
				if (warrior->getLiege() == "") {
					warrior->setLiege(name);
					armySize++;
					return;
				}
				else {
					cout << "Warrior already hired.";
					return;
				}
			}
		}
		cout << "Warrior doesn't exist.";
	}

	void fire(const string& warriorname, vector<Warrior*>& warriors) {
		for (Warrior* warrior: warriors) {
			if (warrior->getName() == warriorname) {
				//check if i hired warrior
				if (warrior->getLiege() == name) {
					warrior->setLiege("");
					armySize--;
					return;
				}
				else {
					cout << "Warrior not hired by this noble.";
					return;
				}
			}
		}
		cout << "Warrior doesn't exist.";
	}

	//gets strength of army
	int armyStrength(vector<Warrior*>& warriors) {
		int strength = 0;
		for (Warrior* warrior : warriors) {
			if (warrior->getLiege() == name) {
				strength += warrior->getStrength();
			}
		}
		return strength;
	}

	void armyRemoveStrength(int strength, vector<Warrior*>& warriors) {
		//how mumch str to remove
		int toRemove = strength / armySize;
		//iterate once more to set strength
		for (Warrior* warrior : warriors) {
			if (warrior->getLiege() == name) {
				warrior->setStrength(warrior->getStrength() - toRemove);
			}
		}
	}
	
	void battle(Noble &enemy, vector<Warrior*>& warriors) {
		//battle text
		cout << getName() << " battles "
			 << enemy.getName() << endl;
		
		//strengths
		int str = armyStrength(warriors);
		int strEnemy = enemy.armyStrength(warriors);
		
		//both dead
		if (!getAlive() && !enemy.getAlive()) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		//same strength, non 0
		else if (str == strEnemy) {
			//change army strengths
			armyRemoveStrength(strEnemy, warriors);
			enemy.armyRemoveStrength(str, warriors);
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
			armyRemoveStrength(strEnemy, warriors);
			enemy.armyRemoveStrength(strEnemy, warriors);
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
			armyRemoveStrength(str, warriors);
			enemy.armyRemoveStrength(str, warriors);
			//im ded
			setAlive(false);
		}
	}

	friend ostream &operator << (ostream &o, const Noble &noble) {
		cout << noble.name << " has an army of " << noble.armySize;
		return o;
	}
	
private:
	string name;
	bool alive;
	int armySize;
};

bool nobleExists(const string& noblename, vector<Noble*>& nobles) {
	for (Noble* noble : nobles) {
		if (noble->getName() == noblename) {
			return true;
		}
	}
	return false;
}

bool warriorExists(const string& warriorname, vector<Warrior*>& warriors) {
	for (Warrior* warrior : warriors) {
		if (warrior->getName() == warriorname) {
			return true;
		}
	}
	return false;	
}

Noble* findNoble(const string& name, vector<Noble*>& nobles) {
	for (Noble* noble : nobles) {
		if (noble->getName() == name) {
			return noble;
		}
	}
	return NULL;
}

//methods
int main() {
	vector<Noble*> nobles;
	vector<Warrior*> warriors;

	//open file
	ifstream inputstream(INPUTFILE);

	string command;
	while (inputstream >> command) {
		if (command == "Noble") {
			string name;
			inputstream >> name;
			//check if noble exists
			if (nobleExists(name, nobles)) {
				cout << "Noble exists.";
			}
			else {
				Noble* nobleP = new Noble(name);
				nobles.push_back(nobleP);
			}
		}
		else if (command == "Warrior") {
			string name;
			int strength;
			inputstream >> name >> strength;
			//check if warrior exists
			if (warriorExists(name, warriors)) {
				cout << "Warrior exists.";
			}
			else {
				Warrior* warriorP = new Warrior(name, strength);
				warriors.push_back(warriorP);
			}
		}
		else if (command == "Hire") {
			string noble;
			string warrior;
			inputstream >> noble >> warrior;
			if (nobleExists(noble, nobles)) {
				if (warriorExists(warrior, warriors)) {
					findNoble(noble, nobles)->hire(warrior, warriors);
				}
				else {
					cout << "Warrior doesn't exist.";
				}
			}
			else {
				cout << "Noble doesn't exist.";
			}
		}
		else if (command == "Fire") {
			string noble;
			string warrior;
			inputstream >> noble >> warrior;
			if (nobleExists(noble, nobles)) {
				if (warriorExists(warrior, warriors)) {
					findNoble(noble, nobles)->fire(warrior, warriors);
				}
				else {
					cout << "Warrior doesn't exist.";
				}
			}
			else {
				cout << "Noble doesn't exist.";
			}
		}
		else if (command == "Battle") {
			string challenger;
			string defender;
			inputstream >> challenger >> defender;
			if (nobleExists(challenger, nobles) &&
				nobleExists(defender, nobles)) {
				findNoble(challenger, nobles)->
					battle(*findNoble(defender, nobles), warriors);
			}
			else {
				cout << "Nobles don't exist." << endl;
			}
		}
		else if (command == "Status") {
			cout << "Status" << endl << "======" << endl;
			cout << "Nobles:" << endl;
			for (Noble* noble : nobles) {
				cout << *noble << endl;
				//slow nested loop cause rules say we can't store
				//list of warriors in nobles :(
				for (Warrior* warrior : warriors) {
					if (warrior->getLiege() == noble->getName()) {
						cout << "\t" << *warrior << endl;
					}
				}
			}
			//print none if no nobles
			if (nobles.size() == 0) {
				cout << "NONE" << endl;
			}
			
			cout << "Unemployed Warriors:" << endl;
			//see if there are any unemployed
			bool found = false;
			for (Warrior* warrior : warriors) {
				if (warrior->getLiege() == "") {
					cout << "\t" << *warrior << endl;
					found = true;
				}
			}
			//no unemployed warriors found
			if (!found) {
				cout << "NONE" << endl;
			}
		}
		else if (command == "Clear") {
			for (Noble* noble : nobles) {
				delete noble;
			}
			nobles.clear();
			for (Warrior* warrior : warriors) {
				delete warrior;
			}
			warriors.clear();
		}
	}

	inputstream.close();
	return 0;
}
