//hw02.cpp
//Ayman Ahmed
//takes file input, creates warriors with weapons, haves them fight

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string INPUTFILE = "warriors.txt";

//warrior class
class Warrior;
//given vector of warriors,
//prints  status of all the warriors to console
void status(const vector<Warrior> &warriors);
//given vector of warriors and warrior names, returns
//returns index of warrior matching name
//else, returns -1 if not found
int findWarrior(const string &name, vector<Warrior> &warriors);
//parses input from file, reads warriors into vector using commands
void parseInput(vector<Warrior> &warriors);

class Warrior {
	friend ostream& operator << 
	(ostream& os, const Warrior& theWarrior);
	
public:
	Warrior(const string& nm, const string &weaponnm, int str)
		: name(nm), weapon(weaponnm, str) { }
	
	string getName() { return name; }
	string getWeaponName() { return weapon.getName(); }
	int getWeaponStrength() { return weapon.getStrength(); }
	
	void setName(const string &newName) { name = newName; }
	void setWeaponName(const string &newName) { weapon.setName(newName); }
	void setWeaponStrength(int newStr) { weapon.setStrength(newStr); }
	
	//given a warrior, challenges him to a battle and updates strengths
	//returning battle results as a string
	string battle(Warrior &defender) {
		string retstr = getName() + " battles " + defender.getName() + "\n";
		
		//both 0 str
		if (!getWeaponStrength() && !defender.getWeaponStrength()) {
			retstr += "Oh, NO! They're both dead! Yuck!";
		}
		//same strength, non 0
		else if (getWeaponStrength() == defender.getWeaponStrength()) {
			retstr += "Mutual Annihilation: " + getName() + " and " + 
				defender.getName() + " die at each other's hands";
			//update strengths
			setWeaponStrength(0);
			defender.setWeaponStrength(0);
		}
		//challenger is stronger
		else if (getWeaponStrength() > defender.getWeaponStrength()) {
			//check if defender is dead before
			if (!defender.getWeaponStrength()) {
				retstr += "He's dead, " + getName();
			}
			else {
				retstr += getName() + " defeats " + defender.getName();
			}
			//updates str
			setWeaponStrength(getWeaponStrength() - 
							  defender.getWeaponStrength());
			defender.setWeaponStrength(0);
		}
		//defender is stronger
		else if (getWeaponStrength() < defender.getWeaponStrength()) {
			//check if challenger was dead already
			if (!getWeaponStrength()) {
				retstr += "He's dead, " + defender.getName();
			}
			else {
				retstr += defender.getName() + " defeats " + getName();
			}
			setWeaponStrength(0);
			defender.setWeaponStrength(defender.getWeaponStrength() - getWeaponStrength());
		}
		//return string log
		return retstr;
	}
	
private:
	//weapon class
	class Weapon {
		//output operator for weapon
		friend ostream& operator << 
		(ostream& os, const Weapon& theWeapon) {
			os << "weapon: " << theWeapon.name << 
				", " << theWeapon.strength;
			return os;
		}
		
	public:
		Weapon(string nm, int str) : name(nm), strength(str) { }
		
		string getName() { return name; }
		int getStrength() { return strength; }
		
		void setName(const string &newName) { name = newName; }
		void setStrength(int newStrength) { strength = newStrength; }
		
	private:
		string name;
		int strength;
	};
	
	string name;
	Weapon weapon;
};

//output operator for warrior
ostream& operator << (ostream& os, const Warrior& theWarrior) {
	os << "Warrior: " << theWarrior.name
	   << ", " << theWarrior.weapon;
	return os;
}

void status(const vector<Warrior> &warriors) {
	cout << "There are: " << warriors.size() << " warriors" << endl;
	for (const Warrior &warrior : warriors) {
		cout << warrior << endl;
	}
}

int findWarrior(const string &name, vector<Warrior> &warriors) {
	for (size_t a = 0 ; a < warriors.size() ; a++) {
		if (warriors[a].getName() == name) {
			return a;
		}
	}
	return -1;
}

void parseInput(vector<Warrior> &warriors) {
	ifstream inputstream(INPUTFILE);
	if (inputstream) {
		string command;
		//parse over each command
		while (inputstream >> command) {
			//new warrior
			if (command == "Warrior") {
				string name, weaponName;
				int strength;
				inputstream >> name >> weaponName >> strength;
				warriors.emplace_back(name, weaponName, strength);
			}
			//status of warriors
			if (command == "Status") {
				status(warriors);
			}
			//battle
			if (command == "Battle") {
				string challenger, defender;
				inputstream >> challenger >> defender;
				//find challenger index and defender index
				int cindex, dindex;
				cindex = findWarrior(challenger, warriors);
				dindex = findWarrior(defender, warriors);
				//battle them and print
				cout << warriors[cindex].battle(warriors[dindex]) << endl;
			}
		}
	}
	inputstream.close();
}

int main() {
	vector<Warrior> warriors = vector<Warrior>();
	parseInput(warriors);
	
	return 0;	
}
