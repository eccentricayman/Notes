#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {

	class Warrior;

	class Noble {
		friend std::ostream& operator <<
			(std::ostream& os, const Noble& noble);
	public:
		Noble(std::string newName);
	
		std::string getName() const;
		bool getAlive() const;
	
		void setName(std::string &nm);
		void setAlive(bool alv);
	
		//check if i employ this warrior, returns index if i do
		int employed(const Warrior &warrior);
	
		//hires a warrior, returns bool for success
		bool hire(Warrior &warrior);
	
		//fires, returns bool for success
		bool fire(Warrior* warrior);

		//when one of my warriors runs
		void runaway(Warrior* warrior);
	
		//gets the combined strength of this noble's army
		//returns as int
		int armyStrength();
	
		//evenly removed amount of army strength spread over all warriors
		void armyRemoveStrength(int strength);
	
		//battles another noble, affecting army strength and noble life
		void battle(Noble &enemy);
	
	private:
		std::string name;
		bool alive;
		std::vector<Warrior*> army;
	};
	
}
