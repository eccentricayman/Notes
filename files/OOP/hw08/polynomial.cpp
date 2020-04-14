#include "polynomial.h"
using namespace std;

ostream& operator << (ostream& os, const Polynomial::Node& node) {
	os << node.data;
	return os;
}

Polynomial::Node::Node() : next(nullptr) { }
Polynomial::Node::Node(int num, Node* nxt) : data(num),
											 next(nxt) { }
Polynomial::Node::~Node() {
	delete next;
}

Polynomial::Polynomial() : head(new Node(0, nullptr)),
						   degree(0) { }

Polynomial::Polynomial(vector<int> input) {
	//ignore 0 case because out of use case scope
	degree = input.size() - 1;
	if (input.size() == 1 && input[0] == 0) {
		head = new Node(0, nullptr);
	}
	else {
		head = new Node();
		Node* current = head;
		for (int a = input.size() - 1 ; a >= 0 ; --a) {
			current -> data = input[a];
			current -> next = new Node();
			current = current -> next;
		}
	}
}

Polynomial::Polynomial(const Polynomial &other) {
	Node* curr = head;
	Node* othercurr = other.head;

	while (othercurr != nullptr) {
		curr = new Node(othercurr -> data, nullptr);
		curr = curr -> next;
		othercurr = othercurr -> next;
	}
	degree = other.degree;
}

Polynomial& Polynomial::operator = (const Polynomial &rhs) {
	Node* curr = head;
	Node* othercurr = rhs.head;

	while (othercurr != nullptr) {
		curr = new Node(othercurr -> data, nullptr);
		curr = curr -> next;
		othercurr = othercurr -> next;
	}

	while (curr != nullptr) {
		Node* temp = curr -> next;
		delete curr;
		curr = temp;
	}
	
	degree = rhs.degree;

	return *this;
}

void printList(Polynomial::Node *node, int degree, int current) {
	if (node -> next != nullptr) {
		//recurse
		printList(node -> next, degree, current - 1);
		if (node -> data == 0) {
			cout << "";
		}
		//1 coeff without x
		else if (node -> data == 1 && current == degree) {
			cout << " + " << node -> data;
		}
		//1 coeff with x at beginning of func
		else if (node -> data == 1 && current == 0) {
			cout << "";
		}
		//1 coeff with x not at beginning
		else if (node -> data == 1 && current > 0) {
			cout << " + ";
		}
		//> 1 coeff
		else if (node -> data > 1 && current > 0) {
			cout << " + " << node -> data;
		}
		//negative coeff
		else {
			cout << node -> data;
		}
		if (node -> data != 0) {
			if (degree - current == 1) {
				cout << "x";
			}
			else if (degree - current > 1) {
				cout << "x^" << degree - current;
			}
		}
	}
}

ostream& operator << (ostream& os, const Polynomial& polynomial) {
	if (polynomial.degree == 0) {
		os << polynomial.head -> data;
	}
	else {
		printList(polynomial.head, polynomial.degree, polynomial.degree);
	}
	return os;
}

Polynomial& Polynomial::operator += (const Polynomial &rhs) {
	Polynomial::Node* curr1 = head;
	Polynomial::Node* curr2 = rhs.head;

	if (degree > rhs.degree) {
		while (curr2 != nullptr) {
			curr1 -> data += curr2 -> data;
			curr1 = curr1 -> next;
			curr2 = curr2 -> next;
		}
	}
	else {
		degree = rhs.degree;
		while (curr1 != nullptr) {
			curr1 -> data += curr2 -> data;
			curr1 = curr1 -> next;
			curr2 = curr2 -> next;
		}

		while (curr2 != nullptr) {
			curr1 = new Polynomial::Node(curr2 -> data, nullptr);
			curr1 = curr1 -> next;
			curr2 = curr2 -> next;
		}
	}
	return *this;
}

Polynomial operator + (Polynomial &lhs,
					   const Polynomial &rhs) {
	lhs += rhs;
	return lhs;
}

bool Polynomial::operator == (const Polynomial &other) const {
	if (degree == other.degree) {
		Polynomial::Node* curr = head;
		Polynomial::Node* othercurr = other.head;
		while (curr != nullptr) {
			if (curr -> data != othercurr -> data) {
				return false;
			}
			curr = curr -> next;
			othercurr = othercurr -> next;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Polynomial::operator != (const Polynomial &other) const {
	return !(*this == other);
}

int Polynomial::evaluate(int value) const {
	Polynomial::Node* curr = head;
	int deg = 1;
	int sum = 0;
	
	while (curr != nullptr) {
		sum += head -> data * (value ^ deg);
		curr = curr -> next;
	}
	return sum;
}
