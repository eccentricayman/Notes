// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void displayList(const list<int> &listu) {
	for (list<int>::const_iterator a = listu.begin();
		 a != listu.end();
		 ++++a) {
		cout << *a << " ";
	}
}

void displayListRF(const list<int> &listu) {
	for (int integ : listu) {
		cout << integ << " ";
	}
}

void displayAltAuto(const list<int> &listu) {
	for (auto a = listu.begin() ; a != listu.end() ; ++++a) {
		cout << *a << " ";
	}
}

list<int>::const_iterator findInList(const list<int> &listu, int intu) {
	for (list<int>::const_iterator a = listu.begin() ;
		 a != listu.end() ; ++a) {
		if (*a == intu) {
			return a;
		}
	}
	return listu.end();
}

auto findInListAuto(const list<int> &listu, int intu) {
	for (auto a = listu.begin() ; a != listu.end() ; ++a) {
		if (*a == intu) {
			return a;
		}
	}
	return listu.end();
}

bool even(int intu) {
	return !(intu % 2);
}

class Functoru {
public:
	bool operator() (int x) {
		return (x % 2) == 0;
	}
};

list<int>::iterator ourFind(list<int>::iterator begin,
							list<int>::iterator end,
							int toFind) {
	cout << "ourfind: ";
	for (list<int>::iterator a = begin ; a != end ; ++a) {
		if (*a == toFind) {
			return a;
		}
	}
	return end;
}

template <class T, class TI>
T ourFindTemplate(T begin, T end,
				   TI toFind) {
	cout << "ourfind template: ";
	for (T a = begin ; a != end ; ++a) {
		if (*a == toFind) {
			return a;
		}
	}
	return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
	vector<int> vectoru;
	for (int a = 0 ; a < 10 ; a++) {
		vectoru.push_back(10 - a);
	}
	for (int integ : vectoru) {
		cout << integ << " ";
	}
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
	list<int> listu(vectoru.begin(), vectoru.end());
	for (int integ : listu) {
		cout << integ << " ";
	}
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
	sort(vectoru.begin(), vectoru.end());
	for (int integ : vectoru) {
		cout << integ << " ";
	}
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
	for (size_t a = 0 ; a < vectoru.size() ; a++) {
		if (a % 2 == 0) {
			cout << vectoru[a] << " ";
		}
	}
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
	// for (size_t a = 0 ; a < listu.size() ; a++) {
	// 	if (a % 2 == 0) {
	// 		cout << listu[a] << " ";
	// 	}
	// }
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
	for (vector<int>::iterator a = vectoru.begin();
		 a != vectoru.end();
		 a += 2) {
		cout << *a << " ";
	}
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
	for (list<int>::iterator a = listu.begin();
		 a != listu.end();
		 ++++a) {
		cout << *a << " ";
	}
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
	listu.sort();
	for (int integ : listu) {
		cout << integ << " ";
	}
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
	displayList(listu);
    cout << "\n=======\n";

    // 10. Calling the function that prints the listvectoru, using ranged-for
    cout << "Task 10:\n";
	displayListRF(listu);
    cout << "\n=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
	displayAltAuto(listu);
    cout << "\n=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
	auto twelve = findInList(listu, 3);
	if (twelve == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *twelve;
	}
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
	auto thirteen = findInListAuto(listu, 3);
	if (thirteen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *thirteen;
	}
    cout << "\n=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
	auto fourteen = find(listu.begin(), listu.end(), 3);
	if (fourteen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *fourteen;
	}
    cout << "\n=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
	auto fifteen = find_if(listu.begin(), listu.end(), even);
	if (fifteen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *fifteen;
	}
    cout << "\n=======\n";

    // 16. Functor
    cout << "Task 16:\n";
	Functoru functoru;
	auto sixteen = find_if(listu.begin(), listu.end(), functoru);
	if (sixteen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *sixteen;
	}
    cout << "\n=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
	auto seventeen = find_if(listu.begin(),
							 listu.end(),
							 [] (int x) { return (x % 2) == 0; });
	if (seventeen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *seventeen;
	}
    cout << "\n=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
	int arr[10];
	copy(vectoru.begin(), vectoru.end(), arr);
	for (int integ : arr) {
		cout << integ << " ";
	}
	cout << endl;
	auto eighteen = find(begin(arr), end(arr), 3);
	if (eighteen == end(arr)) {
		cout << "not found";
	}
	else {
		cout << *eighteen;
	}
    cout << "\n=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
	cout << *ourFind(listu.begin(), listu.end(), 3);
	auto nineteen = ourFind(listu.begin(), listu.end(), 3);
	if (nineteen == listu.end()) {
		cout << "not found";
	}
	else {
		cout << *nineteen;
	}
    cout << "\n=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
	auto twenty = ourFindTemplate(vectoru.begin(), vectoru.end(), 3);
	if (twenty == vectoru.end()) {
		cout << "not found";
	}
	else {
		cout << *twenty;
	}
    cout << "\n=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
	ifstream pooh("pooh-nopunc.txt");
	string word;
	
	vector<string> poohs;
	while (pooh >> word) {
		if (find(poohs.begin(), poohs.end(), word) == poohs.end()) {
			poohs.push_back(word);
		}
	}

	cout << poohs.size();
	pooh.close();
    cout << "\n\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
	pooh = 	ifstream("pooh-nopunc.txt");
	set<string> poohsu;
	while (pooh >> word) {
		poohsu.insert(word);
	}
	cout << poohsu.size();
    cout << "\n=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
	pooh = ifstream("pooh-nopunc.txt");
	map<string, vector<int>> wordMap;
	int ctr = 0;
	while (pooh >> word) {
		wordMap[word].push_back(ctr);
		ctr++;
	}

	for (auto pair : wordMap) {
		cout << pair.first << ": ";
		for (int occurence : pair.second) {
			cout << occurence << " ";
		}
		cout << endl;
	}
    cout << "\n=======\n";
}
