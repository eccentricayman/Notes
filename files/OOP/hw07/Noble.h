#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {

	class Protector;

	class Noble {
	public:
		Noble(std::string nm);
		virtual ~Noble();
		std::string getName() const;
		bool getDead() const;
		virtual int getStrength() const = 0;
		virtual void setStrength(int strength) = 0;
		void setDead(bool isdead);
		virtual void roar() const = 0;
	
		void battle(Noble& enemy);
	private:
		std::string name;
		bool dead;
	};

	class Lord : public Noble {
	public:
		Lord(std::string nm);
		~Lord();
		int getStrength() const;
		void setStrength(int strength);
	
		void hires(Protector& protector);
		void fires(Protector& protector);
		void deserted(Protector& protector);
		void roar() const;
	private:
		std::vector<Protector*> army;
	};

	class PersonWithStrengthtoFight : public Noble {
	public:
		PersonWithStrengthtoFight(std::string nm, int str);
		int getStrength() const;
		void setStrength(int str);
	
		void roar() const;
	private:
		int strength;
	};

}
