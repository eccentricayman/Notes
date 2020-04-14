// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
	friend ostream& operator << (ostream& os, const List& list) {
		Node* current = list.header -> next;
		os << "HEAD -> ";
		while (current -> next != nullptr) {
			os << current -> data << " -> ";
			current = current -> next;
		}
		os << "END" << endl;
		return os;
	}
private:
	//node struct
	struct Node {
		friend ostream& operator << (ostream& os, const Node& node) {
			os << node.data;
			return os;
		}
		Node() : next(nullptr), prior(nullptr) { }
		Node(int num, Node* nxt, Node* prev) : data(num),
											   next(nxt), prior(prev) { }
		int data;
		Node* next;
		Node* prior;
	};
	//members
	int listSize;
	Node* header;
	Node* trailer;
public:
	class Iterator {
		friend class List;
		friend bool operator != (const Iterator& lhs,
								 const Iterator &rhs) {
			return lhs.node != rhs.node;
		}
		friend bool operator == (const Iterator &lhs,
								 const Iterator &rhs) {
			return !(lhs != rhs);
		}
	public:
		Iterator(Node* nodeP) : node(nodeP) { }
		Iterator& operator++() {
			node = node -> next;
			return *this;
		}
		Iterator& operator--() {
			node = node -> prior;
			return *this;
		}
		int& operator*() {
			return node -> data;
		}
	private:
		Node* node;
	};
	
	//list methods
	List() : listSize(0) {
		Node* front = new Node();
		Node* back = new Node();
		front -> next = back;
		back -> prior = front;
		header = front;
		trailer = back;
	}
	//------------------
	~List() {
		Node* current = header;
		Node* nextNode;
		while (current != nullptr) {
			nextNode = current -> next;
			delete current;
			current = nextNode;
		}
	}
	List(const List& list) : List() {
		Node* current = list.header;
		while (current -> next != nullptr) {
			push_back(current -> data);
			current = current -> next;
		}
		listSize = list.listSize;
	}
	List& operator = (const List& list) {
		Node* front = new Node();
		Node* back = new Node();
		front -> next = back;
		back -> prior = front;
		header = front;
		trailer = back;
		Node* current = list.header;
		Node* nextNode;
		while (current -> next != nullptr) {
			nextNode = current -> next;
			insert(Iterator(trailer), current -> data);
			delete current;
			current = nextNode;
		}
		listSize = list.listSize;
		return *this;
	}
	//-----------------------------
	void push_back(int data) {
		Node* newNode = new Node(data, trailer, trailer -> prior);
		trailer -> prior -> next = newNode;
		trailer -> prior = newNode;
		listSize++;
	}
	void pop_back() {
		Node* toPop = trailer -> prior;
		Node* newLast = trailer -> prior -> prior;
		newLast -> next = trailer;
		trailer -> prior = newLast;
		delete toPop;
		listSize--;
	}
	int& front() const {
		return header -> next -> data;
	}
	int& back() const {
		return trailer -> prior -> data;
	}
	size_t size() const {
		return listSize;
	}
	int& operator[] (const int index) const {
		int ctr = 0;
		Node* current = header -> next;
		while (ctr < index) {
			current = current -> next;
			ctr++;
		}
		return current -> data;
	}
	//-------------------------------------
	void push_front(int data) {
		Node* newNode = new Node(data, header -> next, header);
		header -> next -> prior = newNode;
		header -> next = newNode;
		listSize++;
	}
	void pop_front() {
		Node* toPop = header -> next;
		Node* newFront = header -> next -> next;
		newFront -> prior = header;
		header -> next = newFront;
		delete toPop;
		listSize--;
	}
	//------------------------------------------
	void clear() {
		Node* current = header -> next;
		Node* nextNode;
		while (current -> next != nullptr) {
			nextNode = current -> next;
			delete current;
			listSize--;
			current = nextNode;
		}
		header -> next = trailer;
		trailer -> prior = header;
	}
	//-------------------------------------------
	Iterator begin() {
		return Iterator(header -> next);
	}
	Iterator end() {
		return Iterator(trailer);
	}
	//-------------------------------
	Iterator insert(Iterator iter, int data) {
		Node* newNode = new Node(data, iter.node, iter.node -> prior);
		iter.node -> prior -> next = newNode;
		iter.node -> prior = newNode;
		listSize++;
		return Iterator(newNode);
	}
	//-----------------------------
	Iterator erase(Iterator iter) {
		Node* newNext = iter.node -> next;
		Node* newPrior = iter.node -> prior;
		newPrior -> next = newNext;
		newNext -> prior = newPrior;
		delete iter.node;
		listSize--;
		return Iterator(newNext);
	}
};

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
// 	theList.front() = 17;
// 	theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}    

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
    

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // // Task 8
    // cout << "\n------Task Eight------\n";
    // cout << "Copy control\n";
    // cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    // myList.clear();
    // for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    // printListInfo(myList);
    // cout << "Calling doNothing(myList)\n";
    // doNothing(myList);
    // cout << "Back from doNothing(myList)\n";
    // printListInfo(myList);

    // cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    // List listTwo;
    // for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    // printListInfo(listTwo);
    // cout << "listTwo = myList\n";
    // listTwo = myList;
    // cout << "myList: ";
    // printListInfo(myList);
    // cout << "listTwo: ";
    // printListInfo(listTwo);
    // cout << "===================\n";
}
