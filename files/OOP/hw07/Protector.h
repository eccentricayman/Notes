#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {

	class Noble;
	class Lord;

	class Protector {
	public:
		Protector(std::string nm, int str);
		virtual ~Protector();
	
		std::string getName() const;
		int getStrength() const;
		bool getDead() const;
		Lord* getLord() const;
		void setStrength(int str);
		void setDead(bool isdead);
	
		bool hired(Lord* newLord);
		void fired();
		void quit();
		virtual void defend() const = 0;
	private:
		std::string name;
		int strength;
		bool dead;
		Lord* lord;
	};


	class Wizard : public Protector {
	public:
		Wizard(std::string nm, int str);
		void defend() const;
	};

	class Warrior : public Protector {
	public:
		Warrior(std::string nm, int str);
		virtual void defend() const = 0;
	};

	class Archer : public Warrior {
	public:
		Archer(std::string nm, int str);
		void defend() const;
	};

	class Swordsman : public Warrior {
	public:
		Swordsman(std::string nm, int str);
		void defend() const;
	};

	
}
