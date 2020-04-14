//rec01.cpp
//Ayman Ahmed
//this game implements ya boi conway's game of life YERRRRRRRRRR
//runs for 10 generations, prints output in term
//each inner vector is a row

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int GENERATIONS = 10;
string INPUTF = "life.txt";

//this functions reads initial state of board from file
//into a vector of ints, and returns that vector of ints
//0 = dead, 1 = alive
vector< vector<int> > readInitialState() {
	vector< vector<int> > board;

	ifstream inputstream;
	inputstream.open(INPUTF);
	if (inputstream) {
		int counter = 0;
		string row;
		//get every line of the file
		while (getline(inputstream, row)) {
			//pushback sub-vector
			board.push_back(vector<int>());
			//iterate over each char in line
			for (size_t a = 0 ; a <= row.length() ; a++) {
				if (row[a] == '*') {
					board[counter].push_back(1);
				}
				else {
					board[counter].push_back(0);
				}
			}
			counter++;
		}
	}
	inputstream.close();
	return board;
}

//given board and coords, return bool of if this cell is alive
//if it doesnt exist return 0
int isAlive(vector< vector<int> > board, int x, int y) {
	int limitx = board.size() - 1;
	int limity = board[0].size() - 1;
	
	//check if it exists
	if (x >= 0 && x <= limitx && y >= 0 && y <= limity) {
		return board[x][y];
	}
	//if out of limits
	else {
		return 0;
	}
}

//willSurvive calculates whether a cell will live or not in the next turn
//returns int, 0 = false, 1 = true
int cellWillSurvive(vector< vector<int> > board, int x, int y) {
	int livingNeighbors = 0;

	//top left (x - 1, y - 1)
	livingNeighbors += isAlive(board, x - 1, y - 1);
	
	//middle left (x - 1, y)
	livingNeighbors += isAlive(board, x - 1, y);
	
	//bottom left (x - 1, y + 1)
	livingNeighbors += isAlive(board, x - 1, y + 1);
	
	//top (x, y - 1)
	livingNeighbors += isAlive(board, x, y - 1);

	//bottom (x, y + 1)
	livingNeighbors += isAlive(board, x, y + 1);
	
	//top right (x + 1, y - 1)
	livingNeighbors += isAlive(board, x + 1, y - 1);
	
	//middle right (x + 1, y)
	livingNeighbors += isAlive(board, x + 1, y);
	
	//bottom right (x + 1, y + 1)
	livingNeighbors += isAlive(board, x + 1, y + 1);

	//does this lil boi SURVIVE
	//what to do if current cell is alive / dead
	if (board[x][y] == 1) {
		//lonely
		if (livingNeighbors < 2) {
			return 0;
		}
		//just enough
		if (livingNeighbors >= 2 && livingNeighbors <= 3) {
			return 1;
		}
		//too many ppl
		if (livingNeighbors > 3) {
			return 0;
		}
	}
	else {
		//if cell ded + 3 buddies revive
		if (livingNeighbors == 3) {
			return 1;
		}
		//nah otherwise
		else {
			return 0;
		}
	}
	return 0;
}

//tickboard takes board, and returns updated board!!
//has a second vector with the updated cells for next turn
//so updated cells dont interfere with current cells
vector< vector<int> > tickBoard(vector< vector<int> > board) {
	vector <vector<int> > updates;
	//make updates into an empty board, fill out subvectors
	size_t counter = 0;
	while (counter < board.size()) {
		updates.push_back(vector<int>());
		counter++;
	}

	//start checking each cell one by one
	for (size_t a = 0 ; a < board.size() ; a++) {
		for (size_t b = 0 ; b < board[a].size() ; b++) {
			//check if cell will survive, and record update
			//in second vector
			int willSurvive = cellWillSurvive(board, a, b);
			updates[a].push_back(willSurvive);
		}
	}

	//updates are done by now, time to push each update to original board
	for (size_t a = 0 ; a < board.size() ; a++) {
		for (size_t b = 0 ; b < board[a].size() ; b++) {
			board[a][b] = updates[a][b];
		}
	}

	return board;
}

//this function given a board and filename prints the board 
//gen is the generation, if 0 is initial board
void printBoard(vector< vector<int> > board, int gen) {
	//check if initial
	if (!gen) {
		cout << "Initial World" << endl;
	}
	//else print generation
	else {
		cout << "Generation " << gen << endl;
	}
	
	for (size_t a = 0 ; a < board.size() ; a++) {
		for (size_t b = 0 ; b < board[a].size() ; b++) {
			// dash for dead, asterisk live
			if (board[a][b]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		//row done
		cout << endl;
	}
	//newline after board
	cout << endl;
}

//this function takes a board, updates it a specific number
//of ticks, and then returns a printable string of the board updates
void updateBoard(vector< vector<int> > board, int ticks) {
	//run each board over tick then print to file
	for (int a = 1 ; a <= ticks ; a++) {
		board = tickBoard(board);
		printBoard(board, a);
	}
}

int main() {
	vector< vector<int> > board;

	//read initial state into the boardo
	board = readInitialState();
	printBoard(board, 0);
	
	//update board file over certain numba o ticks (10)
	//and print it
	updateBoard(board, GENERATIONS);
	
	return 0;
}
