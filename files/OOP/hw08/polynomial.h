#include <iostream>
#include <vector>

class Polynomial {
public:
	struct Node {
		friend std::ostream& operator <<
		(std::ostream& os, const Node& node);
		Node();
		Node(int num, Node* nxt);
		~Node();
		int data;
		Node* next;
	};
 
	friend std::ostream& operator <<
	(std::ostream& os, const Node& node);
	friend std::ostream& operator <<
	(std::ostream& os, const Polynomial& polynomial);
	
	Polynomial();
	Polynomial(std::vector<int> input);
	Polynomial(const Polynomial& other);
	
	Polynomial& operator += (const Polynomial &rhs);
	Polynomial& operator = (const Polynomial& rhs);
	bool operator == (const Polynomial &other) const;
	bool operator != (const Polynomial &other) const;
	
	int evaluate(int value) const;
	
	friend void printList(Node *node, int degree);
	friend Polynomial operator + (Polynomial &lhs,
								  const Polynomial &rhs);
private:
	//members
	Node* head;
	int degree;
};
