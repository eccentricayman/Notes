#include "Protector.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {

	//protector methods
	Protector::Protector(string nm, int str) : name(nm), strength(str),
											   dead(false), lord(nullptr) { }
	Protector::~Protector() {
		delete lord;
	}
	string Protector::getName() const { return name; }
	int Protector::getStrength() const { return strength; }
	bool Protector::getDead() const { return dead; }
	Lord* Protector::getLord() const { return lord; }
	void Protector::setStrength(int str) { strength = str; }
	void Protector::setDead(bool isdead) { dead = isdead; }
	
	bool Protector::hired(Lord* newLord) {
		if (dead == false && lord == nullptr) {
			lord = newLord;
			return true;
		}
		else {
			return false;
		}
	}
	void Protector::fired() {
		delete lord;
		lord = nullptr;
	}
	void Protector::quit() {
		lord -> deserted(*this);
		delete lord;
		lord = nullptr;
	}

	//wizard methods
	Wizard::Wizard(string nm, int str) : Protector(nm, str) { }
	
	void Wizard::defend() const {
		if (getLord() != nullptr) {
			cout << "POOF!" << endl;
		}
	}

	//warior methods
	Warrior::Warrior(string nm, int str) : Protector(nm, str) { }
	void Warrior::defend() const {
		if (getLord() != nullptr) {
			cout << Protector::getName() << " says: Take that in the name of my lord, "
				 << getLord() -> getName() << endl;
		}
	}

	//archer methods
	Archer::Archer(string nm, int str) : Warrior(nm, str) { }
	void Archer::defend() const {
		cout << "TWANG! ";
		Warrior::defend();
	}

	//swordsman methods
	Swordsman::Swordsman(string nm, int str) : Warrior(nm, str) { }
	void Swordsman::defend() const {
		cout << "CLANG! ";
		Warrior::defend();
	}

}
