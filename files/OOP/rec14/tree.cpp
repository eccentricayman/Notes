#include <iostream>
#include <stdexcept>
using namespace std;

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  // Provide this code
	int max = -1;
	TNode* current = root;
	while (current != nullptr) {
		if (current -> data > max) {
			max = current -> data;
		}
		current = current -> right;
	}
	return max;
}

bool evenBits(int n) {
	if (n == 0) {
		//return extra 1 at end to flip value
		//because 1 = true, 0 = false
		return true;
	}
	else {
		//add 1 for every single bit that is one
		//then get remainder
		if (n & 1) {
			return !evenBits(n >> 1);	
		}
		return evenBits(n >> 1);
	}
}

struct Node {
	Node(int d, Node* r = nullptr) : data(d), right(r) { }
	int data;
	Node* right;
};

Node* sumLists(Node* l1, Node* l2) {
	Node* retNode = nullptr;
	if (l1 == nullptr && l2 == nullptr) {
		return retNode;
	}
	else if (l1 && l2 == nullptr) {
		retNode = new Node(l1 -> data);
		retNode -> right = sumLists(l1 -> right, nullptr);
	}
	else if (l1 == nullptr && l2) {
		retNode = new Node(l2 -> data);
		retNode -> right = sumLists(nullptr, l2 -> right);
	}
	else {
		retNode = new Node(l1 -> data + l2 -> data);
		retNode -> right = sumLists(l1 -> right, l2 -> right);
	}
	return retNode;
}

int treeMax(TNode* root) {
	if (root == nullptr) {
		throw invalid_argument("emptu");
	}
	else {
		int currMax = root -> data;
		int lMax = currMax;
		int rMax = currMax;
		if (root -> left != nullptr) {
			lMax = treeMax(root -> left);
		}
		if (root -> right != nullptr) {
			rMax = treeMax(root -> right);
		}
		if (lMax > currMax) {
			currMax = lMax;
		}
		if (rMax > currMax) {
			currMax = rMax;
		}
		return currMax;
	}
}

bool palindrome(char word[], int limit) {
	if (limit == 0) {
		return true;
	}
	if (word[0] != word[limit - 1]) {
		return false;
	}
	else {
		return palindrome(++word, ----limit);
	}
	return true;
}

int hanoi(int stacks, char from, char to, char travel) {
	if (stacks == 1) {
		return 1;
	}
	else {
		return 1 + (hanoi(stacks - 1, from, travel, to) * 2);
	}
}

void mystery(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      mystery(n/2); 
      cout << 'b'; 
      mystery(n/2); 
   } 
   cout << 'c'; 
}

int main() {

  TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
  TNode u(2), v(3), w(4), x(6, &u, &v), y(21, &w), z(45, &x, &y);
  cout << max(&f) << endl;

  //1
  cout << boolalpha;
  for (int a = 0 ; a < 10 ; a++) {
	  cout << evenBits(a) << endl;
  }

  //2
  Node* a1 = new Node(1, new Node(2, new Node(3)));
  Node* a2 = new Node(1, new Node(2, new Node(3, new Node(9))));
  Node* summo = sumLists(a1, a2);
  while (summo != nullptr) {
	  cout << summo -> data << " -> ";
	  summo = summo -> right;
  }
  cout << "END" << endl;

  //3
  try {
	  cout << treeMax(&f) << endl;
	  cout << treeMax(&z) << endl;
	  cout << treeMax(new TNode()) << endl;
	  cout << treeMax(nullptr) << endl;
  }
  catch (invalid_argument exception) {
	  cout << "error!" << endl;
  }

  //4
  cout << boolalpha;
  char s1[] = "noon";
  char s2[] = "ihaterecursion";
  char s3[] = "racecar";
  cout << palindrome(s1, 4) << endl;
  cout << palindrome(s2, 14) << endl;
  cout << palindrome(s3, 7) << endl;
  //5
  cout << hanoi(1, 'a', 'b', 'c') << endl;
  cout << hanoi(2, 'a', 'b', 'c') << endl;
  cout << hanoi(3, 'a', 'b', 'c') << endl;
  cout << hanoi(4, 'a', 'b', 'c') << endl;
  cout << hanoi(5, 'a', 'b', 'c') << endl;
  cout << hanoi(6, 'a', 'b', 'c') << endl;
  cout << hanoi(7, 'a', 'b', 'c') << endl;
  cout << hanoi(8, 'a', 'b', 'c') << endl;
  cout << hanoi(9, 'a', 'b', 'c') << endl;
  cout << hanoi(10, 'a', 'b', 'c') << endl;
	  
  //6
  //mystery(2);
}

  
  
