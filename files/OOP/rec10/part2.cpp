#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
	virtual void makeSound() const = 0;
	virtual void play() const = 0;
};
void Instrument::makeSound() const {
	cout << "To make a sound...";
}
void Instrument::play() const {
	cout << "";
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
	void play() const {
		cout << "Toot" << endl;
	}
};

class Trombone : public Brass {
public:
	Trombone(unsigned int mp) : Brass(mp) { };
	void play() const {
		cout << "Blat" << endl;
	}
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
	void play() const {
		cout << "Screech" << endl;
	}
};

class Cello : public String {
public:
	Cello(unsigned int ptch) : String(ptch) { };
	void play() const {
		cout << "Squawk" << endl;
	}
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
	void play() const {
		cout << "Boom" << endl;
	}
};

class Cymbal : public Percussion {
public:
	Cymbal() : Percussion() { };
	void play() const {
		cout << "Crash" << endl;
	}
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

	void play() {
		if (instr) instr->play();
		else cout << endl;
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

	void dailyTestPlay() const {
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


class Orch {
public:
	Orch() { };
	
	void addPlayer(Musician& musician) {
		Musician* musicianP = &musician;
		musicians.push_back(musicianP);
	}

	void play() const {
		for (Musician* musician : musicians) {
			musician->play();
		}
	}
private:
	vector<Musician*> musicians;
};

// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    //THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main

