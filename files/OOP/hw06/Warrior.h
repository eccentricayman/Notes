#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
	
	class Noble;

	class Warrior {
		friend std::ostream& operator <<
			(std::ostream& os, const Warrior& warrior);	
	public:
		Warrior(std::string nm, int str);
	
		std::string getName() const;
		int getStrength() const;
		Noble* getEmployer();
	
		void setName(std::string &newnm);
		void setStrength(int newstr);
		void setEmployer(Noble* newnoble);

		void runaway();
	
	private:
		std::string name;
		int strength;
		Noble* employer;
	};
	
}
