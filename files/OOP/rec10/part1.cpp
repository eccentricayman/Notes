#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
	virtual void makeSound() const = 0;
};
void Instrument::makeSound() const {
	cout << "To make a sound...";
}


class Brass : public Instrument {
public:
	Brass(unsigned int mp) : mouthpiece(mp) {};
	void makeSound() const {
		Instrument::makeSound();
		cout << " blow on a mouthpiece of size " << mouthpiece << endl;
	}
private:
	unsigned int mouthpiece;
};

class Trumpet : public Brass {
public:
	Trumpet(unsigned int mp) : Brass(mp) { };
};

class Trombone : public Brass {
public:
	Trombone(unsigned int mp) : Brass(mp) { };
};




class String : public Instrument {
public:
	String(unsigned int ptch) : pitch(ptch) { };
	void makeSound() const {
		Instrument::makeSound();
		cout << " bow a string with pitch " << pitch << endl;
	}
private:
	const unsigned int pitch;
};

class Violin : public String {
public:
	Violin(unsigned int ptch) : String(ptch) { };
};

class Cello : public String {
public:
	Cello(unsigned int ptch) : String(ptch) { };
};




class Percussion : public Instrument {
public:
	Percussion() {};
	void makeSound() const {
		Instrument::makeSound();
		cout << " hit me!" << endl;
	}
};

class Drum : public Percussion {
public:
	Drum() : Percussion() { };
};

class Cymbal : public Percussion {
public:
	Cymbal() : Percussion() { };
};




class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound(); 
        else cerr << "have no instr\n" << endl;
    }

private:
    Instrument* instr;
};


class MILL {
public:
	MILL() { };
	void receiveInstr(Instrument &instrument) {
		cout << "Received Instrument, testing..." << endl;
		instrument.makeSound();
		Instrument* instrumentP = &instrument;
		
		bool space = false;
		for (size_t a = 0 ; a < bin.size() ; a++) {
			if (bin[a] == nullptr) {
				bin[a] = instrumentP;
				space = true;
				break;
			}
		}
		//there's no space
		if (!space) {
			bin.push_back(instrumentP);
		}
	}

	void dailyTestPlay() {
		cout << "Daily testing..." << endl;
		for (Instrument* instr : bin) {
			if (instr != nullptr) {
				instr->makeSound();
			}
		}
	}

	Instrument* loanOut() {
		if (bin.size() == 0) {
			return nullptr;
		}
		else {
			Instrument* toLoan = bin[0];
			for (size_t a = 0 ; a < bin.size() - 1; a++) {
				bin[a] = bin[a + 1];
			}
			bin[bin.size() - 1] = nullptr;
			return toLoan;
		}
	}
private:
	vector<Instrument*> bin;
};

// PART ONE
int main() {

	cout << "Define some instruments ------------------------------------\n";
    Drum drum;
    Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12) ;
	Violin violin(567) ;
  
	// use the debugger to look at the mill
	cout << "Define the MILL --------------------------------------------\n";
	MILL mill;
  
	cout << "Put the instruments into the MILL --------------------------\n";
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);
  
    cout << "Daily test -------------------------------------------------\n";
	cout << endl;
    cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;
  
    cout << "Define some Musicians---------------------------------------\n";
	Musician harpo;
	Musician groucho;
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
	groucho.testPlay();	
	cout << endl;
    groucho.acceptInstr(mill.loanOut());
	cout << endl;
	groucho.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
  
	cout << "------next-----------" << endl;
  
	groucho.testPlay();	
	cout << endl;
	mill.receiveInstr(*groucho.giveBackInstr());
	harpo.acceptInstr(mill.loanOut());
	groucho.acceptInstr(mill.loanOut());
	cout << endl;
	groucho.testPlay();
	cout << endl;
	harpo.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
  
	cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
  
	// fifth
	mill.receiveInstr(*groucho.giveBackInstr());
	cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
	mill.receiveInstr(*harpo.giveBackInstr());

  
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;
	
	cout << endl;
}
