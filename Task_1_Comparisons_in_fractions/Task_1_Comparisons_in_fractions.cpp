#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	//bool operator<=> (const Fraction&) const = default;
	bool operator==(Fraction& r_op) {
		if (numerator_ == r_op.numerator_)
			if(denominator_ == r_op.denominator_)
				return true;
		return false;
	}
	bool operator!=(Fraction& r_op) {
		if (numerator_ != r_op.numerator_)
			return true;
		else
			if (denominator_ != r_op.denominator_)
				return true;
		return false;
	}
	bool operator<(Fraction& r_op) {
		if (numerator_ < r_op.numerator_)
				return true;
		return false;
	}
	bool operator>(Fraction& r_op) {
		if (numerator_ > r_op.numerator_)
			return true;
		return false;
	}
	bool operator<=(Fraction& r_op) {
		if (numerator_ < r_op.numerator_)
			return true;
		if (denominator_ == r_op.denominator_)
			return true;
		return false;
	}
	bool operator>=(Fraction& r_op) {
		if (numerator_ > r_op.numerator_)
			return true;
		if (denominator_ == r_op.denominator_)
			return true;
		return false;
	}


};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}