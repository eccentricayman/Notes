//hw02.cpp
//Ayman Ahmed
//takes file input, creates warriors, haves them fight
//i think the filename was supposed to be hw02?

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string INPUTFILE = "warriors.txt";
struct Warrior {
		string name;
		int strength;
	};

//given a name and a strength, creates a warrior and appends it to vect
void addWarrior(string name, int strength, vector<Warrior> &warriors) {
	Warrior toAdd;
	toAdd.name = name;
	toAdd.strength = strength;
	warriors.push_back(toAdd);
}

//given two warrior structs, makes them fight and updates their strengths,
//returns a string with the battle results and who battles who
string battle(string challengerName, string defenderName, vector<Warrior> &warriors) {
	size_t counter = 0;
	//these are the indices of the warriors doing battle
	int challenger;
	int defender;
	while (counter < warriors.size()) {
		if (warriors[counter].name == challengerName) {
			challenger = counter;
		}
		if (warriors[counter].name == defenderName) {
			defender = counter;
		}
		counter++;
	}
	
	string retstr = warriors[challenger].name + " battles " + warriors[defender].name + "\n";
	//both 0 strength
	
	if (!warriors[challenger].strength && !warriors[defender].strength) {
		retstr += "Oh, NO! They're both dead! Yuck!";
	}
	//challenger and defender same strength non zero
	else if (warriors[challenger].strength == warriors[defender].strength) {			   
		retstr += "Mutual Annihilation: " + warriors[challenger].name + " and " + 
				   warriors[defender].name + " die at each other's hands";
		warriors[challenger].strength = 0;
		warriors[defender].strength = 0;
	}
	//challenger is stronger
	else if (warriors[challenger].strength > warriors[defender].strength) {
		retstr += warriors[challenger].name + " defeats " + warriors[defender].name;
		warriors[challenger].strength -= warriors[defender].strength;
		warriors[defender].strength = 0;
	}
	//defender is stronger
	else if (warriors[challenger].strength < warriors[defender].strength) {
		retstr += "He's dead, " + warriors[defender].name;
		warriors[challenger].strength = 0;
		warriors[defender].strength -= warriors[challenger].strength;
	}
	
	return retstr;
}

//given vector of warriors,
//prints  status of all the warriors to console
void status(vector<Warrior> warriors) {
	cout << "There are: " << warriors.size() << " warriors" << endl;
	for (Warrior warrior : warriors) {
		cout << "Warrior: " << warrior.name << ", strength: " <<
			warrior.strength << endl;
	}
}

//given empty vector, reads input into it and updates it
void parseInput(vector<Warrior> warriors) {
	ifstream inputstream(INPUTFILE);
	if (inputstream) {
		string command;
		//parse over each command
		while (inputstream >> command) {
			if (command == "Warrior") {
				string name;
				int strength;
				//get strength and name from file
				inputstream >> name;
				inputstream >> strength;
				addWarrior(name, strength, warriors);
			}
			if (command == "Status") {
				status(warriors);
			}
			if (command == "Battle") {
				string challenger;
				string defender;
				//get warrior names from file
				inputstream >> challenger;
				inputstream >> defender;
				cout << battle(challenger, defender, warriors) << endl;
			}
		}
	}
	inputstream.close();
}


int main() {
	vector<Warrior> warriors = vector<Warrior>();
	parseInput(warriors);
	
	return 0;
}
