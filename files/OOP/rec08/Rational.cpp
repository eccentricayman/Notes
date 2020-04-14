#include <iostream>
#include "Rational.h"
using namespace std;

namespace CS2124 {

	ostream& operator << (ostream& os, const Rational& rational) {
		os << rational.numerator << "/" << rational.denominator;
		return os;
	}
	
	istream& operator >> (istream& is, Rational& rational) {
		char garbage;
		is >> rational.numerator >> garbage >> rational.denominator;
		
		rational.simplify();
		return is;
	}

	Rational::Rational() {};
	Rational::Rational(int number) : numerator(number), denominator(1) {
		simplify();
	}
	Rational::Rational(int num, int den) : numerator(num),
										   denominator(den) {
		simplify();
	}

	int Rational::getNumerator() const { return numerator; }
	int Rational::getDenominator() const { return denominator; }

	void Rational::setNumerator(int num) { numerator = num; }
	void Rational::setDenominator(int den) {denominator = den; }
	
	void Rational::simplify() {
		int toDivide = gcd(numerator, denominator);
		numerator /= toDivide;
		denominator /= toDivide;
		//remove negatives / move them to top 
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}

	Rational::operator bool() const {
		if (numerator == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	
	Rational& Rational::operator += (const Rational& rhs) {
		int newD = denominator * rhs.denominator;
		int newN = 0;

		//new numerators added together
		newN += numerator * (newD / denominator);
		newN += rhs.numerator * (newD / rhs.denominator);
		
		numerator = newN;
		denominator = newD;
		
		simplify();
		return *this;
	}

	Rational& Rational::operator ++ () {
		numerator += denominator;
		return *this;
	}

	Rational Rational::operator ++ (int) {
		Rational temp(*this);
		operator++();
		return temp;
	}

	//non member funcs //
	int gcd(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	Rational operator + (Rational lhs, const Rational& rhs) {
		lhs += rhs;
		return lhs;
	}

	bool operator == (const Rational& lhs, const Rational& rhs) {
		if (lhs.numerator == rhs.numerator &&
			lhs.denominator == rhs.denominator) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator != (const Rational& lhs, const Rational& rhs) {
		return !(lhs == rhs);
	}

	Rational& operator -- (Rational& rational) {
		rational.setNumerator(rational.getNumerator() -
							  rational.getDenominator());
		return rational;
	}

	Rational operator -- (Rational& rational, int) {
		Rational temp(rational);
		operator--(rational);
		return temp;
	}

	bool operator < (const Rational& lhs, const Rational& rhs) {
		double left = (double) lhs.numerator / (double) lhs.denominator;
		double right = (double) rhs.numerator / (double) rhs.denominator;
		return left < right;
	}

	bool operator <= (const Rational& lhs, const Rational& rhs) {
		if (lhs == rhs || lhs < rhs) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator > (const Rational& lhs, const Rational& rhs) {
		if (!(lhs <= rhs)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator >= (const Rational& lhs, const Rational& rhs) {
		if (lhs == rhs || lhs > rhs) {
			return true;
		}
		else {
			return false;
		}
	}

	
}
