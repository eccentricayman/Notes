#include "Warrior.h"
#include "Noble.h"
using namespace std;

namespace WarriorCraft {

	ostream& operator << (ostream& os, const Warrior& warrior) {
		os << warrior.name << ": " << warrior.strength;
		return os;
	}

	Warrior::Warrior(string nm, int str) : name(nm), strength(str) {
		employer = NULL;
	};

	string Warrior::getName() const { return name; }
	int Warrior::getStrength() const { return strength; }
	Noble* Warrior::getEmployer() { return employer; }

	void Warrior::setName(string &newnm) { name = newnm; }
	void Warrior::setStrength(int newstr) { strength = newstr; }
	void Warrior::setEmployer(Noble* newnoble) { employer = newnoble; }

	void Warrior::runaway() {
		if (employer != NULL) {
			employer->runaway(this);
			cout << name << " flees in terror, abandoning his lord, "
				 << employer->getName() << endl;
			employer = NULL;
		}
	}
	
}

