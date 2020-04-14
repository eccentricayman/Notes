/*
	testRational.cpp
	CS2124
	Implement the class Rational, so that the following program works.
 */

#include <iostream>

// If time allows use  separate compilation, otherwise just define the class below
#include "Rational.h"

using namespace std;

// If time allows after implementing separate compilation, then wrap the class in a namespace.
using namespace CS2124;

// class Rational;

// int gcd(int, int);
// Rational operator + (Rational, const Rational&);
// bool operator != (const Rational&, const Rational&);
// Rational& operator -- (Rational&);
// Rational operator -- (Rational&, int);
// bool operator <= (const Rational& lhs, const Rational& rhs);
// bool operator > (const Rational& lhs, const Rational& rhs);
// bool operator >= (const Rational& lhs, const Rational& rhs);

// class Rational {
// 	//friend ostream& operator << (ostream& os, const Rational& rational);
// 	friend ostream& operator << (ostream& os, const Rational& rational) {
// 		os << rational.numerator << "/" << rational.denominator;
// 		return os;
// 	}

// 	//friend istream& operator >> (istream& is, Rational& rational);
// 	friend istream& operator >> (istream& is, Rational& rational) {
// 		char garbage;
// 		is >> rational.numerator >> garbage >> rational.denominator;

// 		rational.simplify();
// 		return is;
// 	}
	
// 	friend bool operator == (const Rational&, const Rational&);
// 	friend bool operator < (const Rational&, const Rational&);
// public:
// 	// Rational();
// 	// Rational(int);
// 	// Rational(int, int);
	
// 	//int getNumerator() const;
// 	//int getDenominator() const;
	
// 	//void setNumerator(int);
// 	//void setDenominator(int);
	
// 	//void simplify();
	
// 	//Rational& operator += (const Rational&);
// 	//Rational& operator ++ ();
// 	//Rational operator ++ (int);
// 	//operator bool() const;

// 	Rational() {};
// 	Rational(int number) : numerator(number), denominator(1) {
// 		simplify();
// 	}
// 	Rational(int num, int den) : numerator(num), denominator(den) {
// 		simplify();
// 	}

// 	int getNumerator() const { return numerator; }
// 	int getDenominator() const { return denominator; }

// 	void setNumerator(int num) { numerator = num; }
// 	void setDenominator(int den) {denominator = den; }
	
// 	void simplify() {
// 		int toDivide = gcd(numerator, denominator);
// 		numerator /= toDivide;
// 		denominator /= toDivide;
// 		//remove negatives / move them to top 
// 		if (denominator < 0) {
// 			numerator *= -1;
// 			denominator *= -1;
// 		}
// 	}

// 	explicit operator bool() const {
// 		if (numerator == 0) {
// 			return false;
// 		}
// 		else {
// 			return true;
// 		}
// 	}
	
// 	Rational& operator += (const Rational& rhs) {
// 		int newD = denominator * rhs.denominator;
// 		int newN = 0;

// 		//new numerators added together
// 		newN += numerator * (newD / denominator);
// 		newN += rhs.numerator * (newD / rhs.denominator);
		
// 		numerator = newN;
// 		denominator = newD;
		
// 		simplify();
// 		return *this;
// 	}

// 	Rational& operator ++ () {
// 		numerator += denominator;
// 		return *this;
// 	}

// 	Rational operator ++ (int) {
// 		Rational temp(*this);
// 		operator++();
// 		return temp;
// 	}
	
// private:
// 	int numerator;
// 	int denominator;
// };

// int gcd(int x, int y) {
//     while (y != 0) {
//         int temp = x % y;
//         x = y;
//         y = temp;
//     }
//     return x;
// }

// Rational operator + (Rational lhs, const Rational& rhs) {
// 	lhs += rhs;
// 	return lhs;
// }

// bool operator == (const Rational& lhs, const Rational& rhs) {
// 	if (lhs.numerator == rhs.numerator &&
// 		lhs.denominator == rhs.denominator) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

// bool operator != (const Rational& lhs, const Rational& rhs) {
// 	return !(lhs == rhs);
// }

// Rational& operator -- (Rational& rational) {
// 	rational.setNumerator(rational.getNumerator() -
// 						  rational.getDenominator());
// 	return rational;
// }

// Rational operator -- (Rational& rational, int) {
// 	Rational temp(rational);
// 	operator--(rational);
// 	return temp;
// }

// bool operator < (const Rational& lhs, const Rational& rhs) {
// 	double left = (double) lhs.numerator / (double) lhs.denominator;
// 	double right = (double) rhs.numerator / (double) rhs.denominator;
// 	return left < right;
// }

// bool operator <= (const Rational& lhs, const Rational& rhs) {
// 	if (lhs == rhs || lhs < rhs) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

// bool operator > (const Rational& lhs, const Rational& rhs) {
// 	if (!(lhs <= rhs)) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

// bool operator >= (const Rational& lhs, const Rational& rhs) {
// 	if (lhs == rhs || lhs > rhs) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;
    
    Rational a, b;
    cout << "Input two rational numbers, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
	cout << endl;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;
    
	// Implement as non-member, but not a friend
	cout << "a + one: " << (a + one) << endl;
	cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // // How does this manage to work?
    // // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
     cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;

	cout << "++ ++a = " << (++ ++a) << endl;
	cout << "a = " << a << endl;
	cout << "-- --a = " << (-- --a) << endl;
	cout << "a = " << a << endl;

	cout << "a++ ++ = " << (a++ ++) << endl;
	cout << "a = " << a << endl;

    // // Even though the above example, (a++ ++), compiled, the
    // // following shouldn't.
    // // But some compiler vendors might let it...  Is your compiler
    // // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
	//cout << "a = " << a << endl;
	//cannot decrement value of type rational, good compiler


	// Should report that 1 is true
	if (Rational(1)) {
	 	cout << "1 is true" << endl;
	} else {
	 	cout << "1 is false" << endl;
	} 

	// Should report that 0 is false
	if (Rational(0)) {
		cout << "0 is true" << endl;
	} else {
		cout << "0 is false" << endl;
	}
	
}
