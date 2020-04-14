//rec03.cpp
//Ayman Ahmed
//this file has bank accounts but like no real money

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string INPUTFILE = "accounts.txt";

//openInput opens the stream file
void openInput(ifstream &inputstream, string filename) {
	inputstream.open(filename);
}

//////////DEFINITIONS////////////////

//struct data
struct AccountStruct;

//this function reads input into structs	
void readInputStruct(ifstream &inputstream,
					 vector<AccountStruct> &accounts);

//class account
class Account;

//read input into classes
void readInputClass(ifstream &inputstream, vector<Account> &accounts);

//transaction class
class Transaction;

//read inputs and commands froma file into classes with transaction commands
void readInputTransactions(ifstream &inputstream, vector<Account> &accounts);

//deposits or withdraws to account number
void transactionToAccount(string type, int account, const double &amount, 
					  vector<Account> &accounts);

///////////DATA STRUCTURES///////////////////
struct AccountStruct { 
	string name;
	int number;
};

class Account {
public:
	Account(string namep, int numberp) {
		name = namep;
		number = numberp;
		balance = 0;
		history = vector<Transaction>();
	}
	
	string getName() const {
		return name;
	}
	
	int getNumber() const {
		return number;
	}
	
	string setName(const string &newName) {
		string temp = name;
		name = newName;
		return temp;
	}
	
	int setNumber(int newNumber) {
		int temp = number;
		number = newNumber;
		return temp;
	}
	
	void deposit(double amount) {
		balance += amount;
		history.emplace_back("deposit", amount);
	}
	
	void withdraw(double amount) {
		if (balance - amount < 0.00) {
			cout << "Error: Cannot withdraw more than bank contains." << endl;
		}
		else {
			balance -= amount;
			history.emplace_back("withdrawal", amount);
		}
	}
	
	friend ostream &operator << (ostream &output, const Account &account);
	
private:
	string name;
	int number;
	double balance;
	vector<Transaction> history;
};

class Transaction {
public:
	Transaction(string newType, double newAmount) {
		type = newType;
		amount = newAmount;
	}
	
	string getType() const {
		return type;
	}
	
	int getAmount() const {
		return amount;
	}
	
	string setType(string newType) {
		string temp = type;
		type = newType;
		return temp;
	}
	
	int setAmount(int newAmount) {
		int temp = amount;
		amount = newAmount;
		return temp;
	}
	
private:
	string type;
	double amount;
};

//output operator for account
ostream &operator << (ostream &output, const Account &account) {
	//output << account.getName() << "," << account.getNumber();
	output << account.name << ", " << account.number;
	if (account.history.size() > 0) {
		output << "\n" << "Transactions\n";
		for (Transaction transaction : account.history) {
			output << transaction.getType() << ": " << transaction.getAmount() << endl;
		}
	}
	return output;
}

/////////////////PART 1//////////////////
//this function reads input from a file to create accounts in struct
//and puts them in a vector	
void readInputStruct(ifstream &inputstream,
					 vector<AccountStruct> &accounts) {
	string line;
	int number;
	
	//open stream
	openInput(inputstream, INPUTFILE);
	
	//readin each line
	while (getline(inputstream, line)) {
		//get the account number on next line
		inputstream >> number;
		
		AccountStruct account;
		account.name = line;
		account.number = number;
		accounts.push_back(account);
		
		//skip the account line in loop
		getline(inputstream, line);
	}
	//close file
	inputstream.close();
	
	//display all objects
	for (AccountStruct account : accounts) {
		cout << account.name << ", " << account.number << endl;
	}
	
	//empty vector
	accounts.clear();
	
	//reopen file
	inputstream.open(INPUTFILE);
	
	//read each line, again
	while (getline(inputstream, line)) {
		//get the account number on next line
		inputstream >> number;
		
		AccountStruct account{line, number};
		accounts.push_back(account);
		
		//skip the number line in loop
		getline(inputstream, line);
	}
	//close file, again
	inputstream.close();

	//display all objects, again
	for (AccountStruct account : accounts) {
		cout << account.name << ", " << account.number << endl;
	}
}

///////////////PART 2///////////////////
//this func reads input from a file to create accounts using classes
//and puts em in a vector parameter
void readInputClass(ifstream &inputstream, vector<Account> &accounts) {
	string line;
	int number;
	
	//open stream
	openInput(inputstream, INPUTFILE);
	
	//readin each line
	while (getline(inputstream, line)) {
		//get the account number on next line
		inputstream >> number;
		
		//Account account(line, number);
		accounts.push_back(Account(line, number));
		
		//skip the number line in loop
		getline(inputstream, line);
	}
	
	//clear vector
	accounts.clear();
	//close file
	inputstream.close();
	//open stream
	openInput(inputstream, INPUTFILE);
	
	//reread into vector, but using emplace_back
	while (getline(inputstream, line)) {
		//get the account number on next line
		inputstream >> number;
		
		//Account account(line, number);
		accounts.emplace_back(line, number);
		
		//skip the number line in loop
		getline(inputstream, line);
	}
	
	//close file
	inputstream.close();
	
	//display all objects
	for (Account account : accounts) {
		cout << account.getName() << ", " << account.getNumber() << endl;
	}
	
	//display using output operator
	for (const Account &account : accounts) {
		cout << account << endl;
	}
}
///////////////PART 3/////////////
void readInputTransactions(ifstream &inputstream, vector<Account> &accounts) {
	string command;
	string name;
	int account;
	double amount;
	
	//open stream
	openInput(inputstream, "transactions.txt");
	
	//readin each line
	while (inputstream >> command) {
		if (command == "Account") {
			inputstream >> name >> account;
			accounts.emplace_back(name, account);
		}
		else if (command == "Deposit") {
			inputstream >> account >> amount;
			transactionToAccount("deposit", account, amount, accounts);
		}
		else if (command == "Withdraw") {
			inputstream >> account >> amount;
			transactionToAccount("withdrawal", account, amount, accounts);
		}
	}
	
	inputstream.close();
	for (const Account &account : accounts) {
		cout << account << endl;
	}
}

void transactionToAccount(string type, int accountNumber, 
						  const double &amount, 
						  vector<Account> &accounts) {
	for (Account &account : accounts) {
		if (account.getNumber() == accountNumber) {
			if (type == "deposit") {
				account.deposit(amount);
			}
			else if (type == "withdrawal") {
				account.withdraw(amount);
			}		
		}
	}
}
///////////PART 4////////////////





////////////////////////////////

int main() {
	vector<AccountStruct> structAccounts = vector<AccountStruct>();
	vector<Account> classAccounts = vector<Account>();
	ifstream stream;
	
	//read input into struct vector (part 1)
	//readInputStruct(stream, structAccounts);
	//read input into class vector (part 2)
	//readInputClass(stream, classAccounts);
	//read input and transactions
	readInputTransactions(stream, classAccounts);
	return 0;
}
