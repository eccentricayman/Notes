#include "Noble.h"
#include "Protector.h"
using namespace std;

namespace WarriorCraft {

	//noble methods
	Noble::Noble(string nm) : name(nm), dead(false) { }
	Noble::~Noble() {}
	string Noble::getName() const { return name; }
	bool Noble::getDead() const { return dead; }
	void Noble::setDead(bool isdead) { dead = isdead; }
	void Noble::roar() const { cout << ""; }
	void Noble::battle(Noble& enemy) {
		//battle text
		cout << getName() << " battles "
			 << enemy.getName() << endl;

		int str = getStrength();
		int strEnemy = enemy.getStrength();

		if (getDead() && enemy.getDead()) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		//same strength, non 0
		else if (str == strEnemy) {
			//scream
			roar();
			//change army strengths
			setStrength(strEnemy);
			enemy.setStrength(str);
			//kill nobles
			setDead(true);
			enemy.setDead(true);
		
			cout << "Mutual Annihilation: " <<
				getName() << " and " << enemy.getName()
				 << " die at each other's hands" << endl;
		}
		//person starting battle is stronger
		else if (str > strEnemy) {
			roar();
			//check if enemy is alive before fight
			if (!enemy.getDead()) {

				cout << getName() << " defeats " 
					 << enemy.getName() << endl;	
			}
			else {
				cout << "He's dead, " << getName() << endl;
			}
			//update army strengths
			setStrength(strEnemy);
			enemy.setStrength(strEnemy);
			//enemy noble ded
			enemy.setDead(true);
		}
		//enemy is stronger
		else if (str < strEnemy) {

			//check if we're alive before fighting
			if (!getDead()) {
				roar();
				cout << enemy.getName() << 
					" defeats " << getName() << endl;
			}
			else {
				cout << "He's dead, " << enemy.getName() << endl;
			}
			//update army strengths
			setStrength(str);
			enemy.setStrength(str);
			//im ded
			setDead(true);
		}
	}

	//lord methods
	Lord::Lord(string nm) : Noble(nm) { };
	Lord::~Lord() {
		for (size_t a = 0 ; a < army.size() ; a++) {
			delete army[a];
		}
		army.clear();
	}

	int Lord::getStrength() const {
		int str = 0;
		for (Protector* protector : army) {
			str += protector -> getStrength();
		}
		return str;
	}

	void Lord::setStrength(int strength) {
		if (army.size() > 0) {
			int spread = strength / army.size();
			for (Protector* protector : army) {
				if (protector -> getStrength() - spread < 0) {
					protector -> setStrength(0);
					protector -> setDead(true);
				}
				else {
					protector -> setStrength(protector ->
											 getStrength() - spread);
				}
			}
		}
	}

	void Lord::hires(Protector& protector) {
		bool hired = protector.hired(this);
		if (hired) {
			Protector* proP = &protector;
			army.push_back(proP);
		}
	}

	void Lord::fires(Protector& protector) {
		protector.fired();
	
		bool removed = false;
		for (size_t a = 0 ; a < army.size() - 1 ; a++) {
			//assignment said unique names
			if (protector.getName() == army[a] -> getName() && !removed) {
				delete army[a];
				removed = true;
			}
			if (removed) {
				army[a] = army[a + 1];
			}
		}
		army.pop_back();
	}

	void Lord::deserted(Protector& protector) {
		bool removed = false;
		for (size_t a = 0 ; a < army.size() - 1 ; a++) {
			//assignment said unique names
			if (protector.getName() == army[a] -> getName() && !removed) {
				delete army[a];
				removed = true;
			}
			if (removed) {
				army[a] = army[a + 1];
			}
		}
		army.pop_back();
	}

	void Lord::roar() const {
		for (size_t a = 0 ; a < army.size() ; a++) {
			army[a] -> defend();
		}
	}

	//person with str to fight methods
	PersonWithStrengthtoFight::PersonWithStrengthtoFight(string nm, int str) :
		Noble(nm), strength(str) { }

	int PersonWithStrengthtoFight::getStrength() const { return strength; }
	void PersonWithStrengthtoFight::setStrength(int str) {
		strength -= str;
		if (strength < 0) { strength = 0; }
	}

	void PersonWithStrengthtoFight::roar() const {
		cout << "UGH!!!" << endl;
	}
	
}
