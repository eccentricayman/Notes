//hw01.cpp
//Ayman Ahmed
//Meant to print out decrypted caesar cipher code in a encrypted.txt file
//with the cipher number on the first line of the file, in backwards order.
/////////////////////////////////////////////////////
// PLEASE READ: I DIDNT SEE THE SPECIFIC FUNCTION  //
// REQUIREMENTS SO I MADE MY OWN, SORRY IN ADVANCE //
/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//filename
string ENCRYPTED_FILE = "encrypted.txt";

//filename is name of file, returns first line as integer, the cipher
//otherwise it returns 0 as the cipher (no cipher/no change)
int readCipher(string filename) {
	ifstream filestream;
	int cipher;

	filestream.open(filename);
	if (filestream) {
		filestream >> cipher;
	}
	else {
		cipher = 0;
	}

	filestream.close();
	return cipher;
}

//filename is name of file, reads each line into a vector of strings
//if it doesnt exist, returns empty vector
vector<string> readContent(string filename) {
	ifstream filestream;
	vector<string> lines;

	filestream.open(filename);
	if (filestream) {
		//ignore cipher
		string empty;
		getline(filestream, empty);
		
		int counter = 0;
		string line;
		while (getline(filestream, line)) {
			lines.push_back(line);
			counter++;
		}
	}

	filestream.close();
	return lines;
}

//todecrypt is char, cipher is int
//returns decrypted char
char decryptChar(char todecrypt, int cipher) {
	//check lowercase
	if (todecrypt >= 97 && todecrypt <= 122) {
		//decipher
		todecrypt -= cipher;

		//if it goes below a, wrap around to z
		if (todecrypt < 97) {
			todecrypt = 'z' - (96 - todecrypt);
		}
	}
	return todecrypt;
}

//todecrypt is string, cipher is int
//returns decrypted line
string decryptString(string todecrypt, int cipher) {
	for (size_t b = 0 ; b < todecrypt.length() ; b++) {
		todecrypt[b] = decryptChar(todecrypt[b], cipher);
	}
	return todecrypt;
}

//lines is vector of strings with encrypted text, cipher is the cipher #
//returns decrypted vector of strings
vector<string> deCipher(vector<string> lines, int cipher) {
	vector<string> decrypted = lines;
	
	for (size_t a = 0 ; a < decrypted.size() ; a++) {
		decrypted[a] = decryptString(decrypted[a], cipher);
	}
	return decrypted;
}

//lines is a vector of strings, func. returns nothing and prints vector
//in reverse order
void printVectorBackwards(vector<string> lines) {
	for (size_t c = lines.size() - 1; c > 0 ; c--) {
		cout << lines[c] << endl;
	}
}

int main() {
	//vector of each line, the cipher, and the file
	vector<string> lines;
	int cipher;

	//read cipher from file
	cipher = readCipher(ENCRYPTED_FILE);

	//read file into vector
	lines = readContent(ENCRYPTED_FILE);

	//decipher
	lines = deCipher(lines, cipher);

	//print out deciphered vector backwards
	printVectorBackwards(lines);
	
	return 0;
}
