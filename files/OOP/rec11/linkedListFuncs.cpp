/*
  functions for use with CS2124 rec11
  -jbs
*/
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

void displayList(Node* node) {
	while (node != nullptr) {
		cout << node->data << " ";
		node = node -> next;
	}
	cout << endl;
}

//list is the list to add in, location is where we're adding it in
void splice(Node* list, Node* location) {
	if (location != nullptr) {
		Node* oldNext = location->next;
		location->next = list;
		
		Node* listEnd = list;
		while (listEnd->next != nullptr) {
			listEnd = listEnd->next;
		}
		listEnd->next = oldNext;
	}
	else {
		location = list;
	}
}

//returns pointer to node where sublist starts or nullptr
Node* isSublist(Node* sublist, Node* list) {
	//sublist original start
	Node* original = sublist;
	while (list != nullptr) {
		//check if we went over whole sublist
		if (sublist == nullptr) {
			return original;
		}
		//if we didnt, keep going over it
		if (list->data == sublist->data) {
			sublist = sublist -> next;
		}
		//reset sublist if no match
		else {
			sublist = original;
		}
		list = list -> next;
	}
	//edge case to check end of list
	if (sublist == nullptr) {
		return original;
	}
	else {
		return nullptr;
	}
}

Node* sharedListBruteForce(Node* one, Node* two) {
	Node* originalTwo = two;
	while (one != nullptr) {
		while (two != nullptr) {
			//same node address
			if (one == two) {
				//or two, doesnt matter too much
				return two;
			}
			two = two -> next;
		}
		one = one -> next;
		two = originalTwo;
	}
	return nullptr;
}

Node* sharedListUsingSet(Node* one, Node* two) {
	unordered_set<Node*> stuff;
	while (one != nullptr) {
		stuff.insert(one);
		one = one -> next;
	}
	while (two != nullptr) {
		//found it
		if (stuff.find(two) != stuff.end()) {
			return two;
		}
		two = two -> next;
	}
	return nullptr;
}

int main() {
	cout << "testing splice" << endl;
	Node* l1 = listBuild({5, 7, 9, 1});
	Node* node = l1->next->next->next;
	Node* l2 = listBuild({6, 3, 2});
	displayList(l1);
	displayList(l2);
	
	splice(l2, node);
	displayList(l1);

	cout << endl;

	cout << "is sublist" << endl;
	Node* l3 = listBuild({2, 9, 1});
	Node* l4 = listBuild({5, 7, 6, 3, 2, 9, 1});
	displayList(l3);
	displayList(l4);
	Node* location = isSublist(l3, l4);
	
	if (location == nullptr) {
		cout << "np";
	}
	else {
		cout << location->data;
	}

	cout << endl << endl;

	cout << "shared list brute force" << endl;
	Node* l5 = listBuild({2, 3, 4, 5});
	Node* l6 = listBuild({2, 3, 3});
	l6->next->next->next = l5->next->next;
	displayList(l5);
	displayList(l6);

	Node* shared = sharedListBruteForce(l5, l6);
	if (shared == nullptr) {
		cout << "np";
	}
	else {
		cout << shared->data;
	}

	cout << endl;

	cout << "shared list using set" << endl;
	Node* shared2 = sharedListUsingSet(l5, l6);
	if (shared2 == nullptr) {
		cout << "np";
	}
	else {
		cout << shared2->data;
	}
}
