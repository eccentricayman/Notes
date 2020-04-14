#include <iostream>

namespace CS2124 {
	
	class Rational;
	
	int gcd(int, int);
	Rational operator + (Rational, const Rational&);
	bool operator != (const Rational&, const Rational&);
	Rational& operator -- (Rational&);
	Rational operator -- (Rational&, int);
	bool operator <= (const Rational& lhs, const Rational& rhs);
	bool operator > (const Rational& lhs, const Rational& rhs);
	bool operator >= (const Rational& lhs, const Rational& rhs);
	
	class Rational {
		friend std::ostream& operator << (std::ostream& os,
									 const Rational& rational);
		friend std::istream& operator >> (std::istream& is,
										  Rational& rational);
		
		friend bool operator == (const Rational&, const Rational&);
		friend bool operator < (const Rational&, const Rational&);
	public:
		Rational();
		Rational(int);
		Rational(int, int);
		
		int getNumerator() const;
		int getDenominator() const;
		
		void setNumerator(int);
		void setDenominator(int);
		
		void simplify();
		
		Rational& operator += (const Rational&);
		Rational& operator ++ ();
		Rational operator ++ (int);
		explicit operator bool() const;
		
	private:
		int numerator;
		int denominator;
	};
}
