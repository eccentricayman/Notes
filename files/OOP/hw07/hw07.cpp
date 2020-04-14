#include <iostream>
#include <vector>
#include "Noble.h"
#include "Protector.h"
using namespace std;
using namespace WarriorCraft;
//namespace WarriorCraft {

// class Noble;
// class Protector;

// class Noble {
// public:
// 	Noble(string nm);
// 	string getName() const;
// 	bool getDead() const;
// 	virtual int getStrength() const = 0;
// 	virtual void setStrength(int strength) = 0;
// 	void setDead(bool isdead);
	
// 	void battle(Noble& enemy);
// 	virtual void roar() = 0;
// private:
// 	string name;
// 	bool dead;
// };

// class Lord : public Noble {
// public:
// 	using Noble::Noble;
// 	~Lord();
// 	int getStrength() const;
// 	void setStrength(int strength);
	
// 	void hires(Protector& protector);
// 	void fires(Protector& protector);
// 	void deserted(Protector& protector);
// 	void roar();
// private:
// 	vector<Protector*> army;
// };

// class PersonWithStrengthtoFight : public Noble {
// public:
// 	PersonWithStrengthtoFight(string nm, int str);
// 	int getStrength() const;
// 	void setStrength(int str);
	
// 	void roar();
// private:
// 	int strength;
// };

// class Protector {
// public:
// 	Protector(string nm, int str);
// 	virtual ~Protector() {
// 		lord = nullptr;
// 	}
	
// 	string getName() const;
// 	int getStrength() const;
// 	bool getDead() const;
// 	Lord* getLord();
// 	void setStrength(int str);
// 	void setDead(bool isdead);
	
// 	bool hired(Lord* newLord);
// 	void fired();
// 	void quit();
// 	virtual void defend() = 0;
// private:
// 	string name;
// 	int strength;
// 	bool dead;
// 	Lord* lord;
// };


// class Wizard : public Protector {
// public:
// 	using Protector::Protector;
// 	void defend();
// };

// class Warrior : public Protector {
// public:
// 	using Protector::Protector;
// 	virtual void defend() = 0;
// };

// class Archer : public Warrior {
// public:
// 	using Warrior::Warrior;
// 	void defend();
// };

// class Swordsman : public Warrior {
// public:
// 	using Warrior::Warrior;
// 	void defend();
// };

// //noble methods
// Noble::Noble(string nm) : name(nm), dead(false) { }
// string Noble::getName() const { return name; }
// bool Noble::getDead() const { return dead; }
// void Noble::setDead(bool isdead) { dead = isdead; }
// void Noble::battle(Noble& enemy) {
// 	//battle text
// 	cout << getName() << " battles "
// 		 << enemy.getName() << endl;

// 	int str = getStrength();
// 	int strEnemy = enemy.getStrength();

// 	if (getDead() && enemy.getDead()) {
// 			cout << "Oh, NO! They're both dead! Yuck!" << endl;
// 	}
// 	//same strength, non 0
// 	else if (str == strEnemy) {
// 		//scream
// 		roar();
// 		//change army strengths
// 		setStrength(strEnemy);
// 		enemy.setStrength(str);
// 		//kill nobles
// 		setDead(true);
// 		enemy.setDead(true);
		
// 		cout << "Mutual Annihilation: " <<
// 			getName() << " and " << enemy.getName()
// 			 << " die at each other's hands" << endl;
// 	}
// 	//person starting battle is stronger
// 	else if (str > strEnemy) {
// 		roar();
// 		//check if enemy is alive before fight
// 		if (!enemy.getDead()) {

// 			cout << getName() << " defeats " 
// 				 << enemy.getName() << endl;	
// 		}
// 		else {
// 			cout << "He's dead, " << getName() << endl;
// 		}
// 		//update army strengths
// 		setStrength(strEnemy);
// 		enemy.setStrength(strEnemy);
// 		//enemy noble ded
// 		enemy.setDead(true);
// 	}
// 	//enemy is stronger
// 	else if (str < strEnemy) {

// 		//check if we're alive before fighting
// 		if (!getDead()) {
// 			roar();
// 			cout << enemy.getName() << 
// 				" defeats " << getName() << endl;
// 		}
// 		else {
// 			cout << "He's dead, " << enemy.getName() << endl;
// 		}
// 		//update army strengths
// 		setStrength(str);
// 		enemy.setStrength(str);
// 		//im ded
// 		setDead(true);
// 	}
// }

// //lord methods
// Lord::~Lord() {
// 	for (Protector* p : army) {
// 		delete p;
// 	}
// 	army.clear();
// }

// int Lord::getStrength() const {
// 	int str = 0;
// 	for (Protector* protector : army) {
// 		str += protector -> getStrength();
// 	}
// 	return str;
// }

// void Lord::setStrength(int strength) {
// 	if (army.size() > 0) {
// 		int spread = strength / army.size();
// 		for (Protector* protector : army) {
// 			if (protector -> getStrength() - spread < 0) {
// 				protector -> setStrength(0);
// 				protector -> setDead(true);
// 			}
// 			else {
// 				protector -> setStrength(protector ->
// 										 getStrength() - spread);
// 			}
// 		}
// 	}
// }

// void Lord::hires(Protector& protector) {
// 	bool hired = protector.hired(this);
// 	if (hired) {
// 		Protector* proP = &protector;
// 		army.push_back(proP);
// 	}
// }

// void Lord::fires(Protector& protector) {
// 	protector.fired();
	
// 	bool removed = false;
// 	for (size_t a = 0 ; a < army.size() - 1 ; a++) {
// 		//assignment said unique names
// 		if (protector.getName() == army[a] -> getName()) {
// 			delete army[a];
// 			removed = true;
// 		}
// 		if (removed) {
// 			army[a] = army[a + 1];
// 		}
// 	}
// 	army.pop_back();
// }

// void Lord::deserted(Protector& protector) {
// 	bool removed = false;
// 	for (size_t a = 0 ; a < army.size() - 1 ; a++) {
// 		//assignment said unique names
// 		if (protector.getName() == army[a] -> getName()) {
// 			delete army[a];
// 			removed = true;
// 		}
// 		if (removed) {
// 			army[a] = army[a + 1];
// 		}
// 	}
// 	army.pop_back();
// }

// void Lord::roar() {
// 	for (Protector* protector : army) {
// 		protector -> defend();
// 	}
// }

// //person with str to fight methods
// PersonWithStrengthtoFight::PersonWithStrengthtoFight(string nm, int str) :
// 	Noble(nm), strength(str) { }

// int PersonWithStrengthtoFight::getStrength() const { return strength; }
// void PersonWithStrengthtoFight::setStrength(int str) { strength = str; }

// void PersonWithStrengthtoFight::roar() {
// 	cout << "UGH!!!" << endl;
// }

// //protector methods
// Protector::Protector(string nm, int str) : name(nm), strength(str),
// 										   dead(false), lord(nullptr) { }
// string Protector::getName() const { return name; }
// int Protector::getStrength() const { return strength; }
// bool Protector::getDead() const { return dead; }
// Lord* Protector::getLord() { return lord; }
// void Protector::setStrength(int str) { strength = str; }
// void Protector::setDead(bool isdead) { dead = isdead; }

// bool Protector::hired(Lord* newLord) {
// 	if (dead == false && lord == nullptr) {
// 		lord = newLord;
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }
// void Protector::fired() {
// 	lord = nullptr;
// }
// void Protector::quit() {
// 	lord -> deserted(*this);
// 	lord = nullptr;
// }

// //wizard methods
// void Wizard::defend() {
// 	if (getLord() != nullptr) {
// 		cout << "POOF!" << endl;
// 	}
// }

// //warior methods
// void Warrior::defend() {
// 	if (getLord() != nullptr) {
// 		cout << getName() << " says: Take that in the name of my lord, "
// 			 << getLord() -> getName() << endl;
// 	}
// }

// //archer methods
// void Archer::defend() {
// 	cout << "TWANG! ";
// 	Warrior::defend();
// }

// //swordsman methods
// void Swordsman::defend() {
// 	cout << "CLANG! ";
// 	Warrior::defend();
// }

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthtoFight randy("Randolf the Elder", 250); 	
	joe.battle(randy);	
	joe.battle(sam);	
	Lord janet("Janet");	
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);	
	janet.hires(stout);	
	PersonWithStrengthtoFight barclay("Barclay the Bold", 300);	
	janet.battle(barclay);	
	janet.hires(samantha);	
	Archer pethora("Pethora", 50);	
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
	cout << "test";
}

//}
