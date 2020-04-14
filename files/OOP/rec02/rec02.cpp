//rec02.cpp
//Ayman Ahmed
//prompts for file input of molecular formulas, stores and organizes them
// it can also print them

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct MolecularFormula {
	int carbon, hydrogen;
	vector<string> names;
};

//this function requests user input for the filename until it
//gets a functioning stream, takes a unopened stream to attach to
void openStream(ifstream &stream);

//this function given formula with c & h and string of formula name
//inserts it into the vector
void insertFormula(int carbon, int hydrogen, const string &formulaName,
				   vector<MolecularFormula> &formulas);

//finds if a formula already exists in the vector and returns index
int findFormula(int carbon, int hydrogen, 
				const vector<MolecularFormula> &formulas);

//this function reads the input of the stream into the vector
void parseFormulas(ifstream &inputstream, 
				   vector<MolecularFormula> &formulas);

//this function sorts the vector of formulas in place
void sortFormulas(vector<MolecularFormula> &formulas);

//this function prints the formulas
void printFormulas(const vector<MolecularFormula> &formulas);

int main() {
	ifstream inputstream;
	vector<MolecularFormula> formulas;
	
	//open stream
	openStream(inputstream);
	
	//read in from fileformulas[b].hydrogen > formulas[b + 1].hydrogen
	parseFormulas(inputstream, formulas);

	//sort the vector
	sortFormulas(formulas);

	//print the vector
	printFormulas(formulas);

	return 0;
}

void openStream(ifstream &stream) {
	int openStream = 0;
	//keep asking for input while stream is not open
	while (!openStream) {
		string filename;
		cout << "Please enter the filename: ";
		cin >> filename;
		//open the file and make openStream true if it opens
		stream.open(filename);
		if (stream) {
			openStream = 1;
		}
		else {
			stream.clear();
		}
	}
}

int findFormula(int carbon, int hydrogen, 
				const vector<MolecularFormula> &formulas) {
	for (size_t index = 0 ; index < formulas.size() ; index++) {
		if (formulas[index].carbon == carbon &&
			formulas[index].hydrogen == hydrogen) {
			return index;
		}
	}
	//if not found
	return -1;
}

void insertFormula(int carbon, int hydrogen, const string &formulaName,
				   vector<MolecularFormula> &formulas) {
	//see if it exists
	int index = findFormula(carbon, hydrogen, formulas);
	
	//if it doesn't exist, add to vector
	if (index == -1) {
		MolecularFormula newFormula;
		newFormula.carbon = carbon;
		newFormula.hydrogen = hydrogen;
		newFormula.names.push_back(formulaName);
		//add to vector
		formulas.push_back(newFormula);
	}
	//if it exists, add the name to existiexistsng entry
	else {
		formulas[index].names.push_back(formulaName);
	}
}

void parseFormulas(ifstream &inputstream, 
				   vector<MolecularFormula> &formulas) {
	string formulaName;
	while (inputstream >> formulaName) {
		//chars for carbon and hydrogen, unused later so single letter
		//variable
		char garbage;
		int carbon, hydrogen;
		inputstream >> garbage >> carbon >> garbage >> hydrogen;
		
		insertFormula(carbon, hydrogen, formulaName, formulas);
	}
}

void sortFormulas(vector<MolecularFormula> &formulas) {
	//bubblesort
	int swapped;
	//iterate over whole list
	for (size_t a = 0 ; a < formulas.size() - 1 ; a++) {
		swapped = 0;
		//check every two elements starting at a
		for (size_t b = 0 ; b < formulas.size() - a - 1 ; b++) {
			//if current is greater carbon than the one above, swap
			if (formulas[b].carbon > formulas[b + 1].carbon) {
				MolecularFormula tempSwap = formulas[b + 1];
				formulas[b + 1] = formulas[b];
				formulas[b] = tempSwap;
				swapped = true;
			}
			//check for equal carbon then organize hydrogen
			if (formulas[b].carbon == formulas[b + 1].carbon) {
				//swap for hydrogen
				if (formulas[b].hydrogen > formulas[b + 1].hydrogen) {
					MolecularFormula tempSwap = formulas[b + 1];
					formulas[b + 1] = formulas[b];
					formulas[b] = tempSwap;
					swapped = true;
				}
			}
		}
		//if nothing is swapped, exit the loop
		if (swapped == false) {
			break;
		}
	}
}

void printFormulas(const vector<MolecularFormula> &formulas) {
	for (const MolecularFormula &formula : formulas) {
		cout << "C" << formula.carbon << "H" << formula.hydrogen << " ";
		for (const string &name : formula.names) {
			cout << name << " ";
		}
		cout << endl;
	}
}
