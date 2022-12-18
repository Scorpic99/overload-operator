#include <iostream>
using namespace std;

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
	void print() {

		cout << numerator_ << "/" << denominator_ << endl;
	}
	Fraction operator+(Fraction r_op) {
		int r_op1 = denominator_ * r_op.denominator_;//знаменатель
		int l_numerator = numerator_ * r_op.denominator_;
		int r_numerator = r_op.numerator_ * denominator_;
		int l_op1 = l_numerator + r_numerator;
		return Fraction(l_op1, r_op1);
	}
	Fraction operator-(Fraction r_op) {
		int r_op1 = denominator_ * r_op.denominator_;//знаменатель
		int l_numerator = numerator_ * r_op.denominator_;
		int r_numerator = r_op.numerator_ * denominator_;
		int l_op1 = l_numerator - r_numerator;
		return Fraction(l_op1, r_op1);
	}
	Fraction operator*(Fraction r_op) {
		int l_op1 = numerator_ * r_op.numerator_;
		int r_op1 = denominator_ * r_op.denominator_;//знаменатель
		if (denominator_ == r_op.numerator_) {
			l_op1 = numerator_;
			r_op1 = r_op.denominator_;
		}
		else if (numerator_ == r_op.denominator_) {
			l_op1 = r_op.numerator_;
			r_op1 = denominator_;
		}
		return Fraction(l_op1, r_op1);
	}
	Fraction operator/(Fraction r_op) {

		int l_op1 = numerator_ * r_op.denominator_;
		int r_op1 = denominator_ * r_op.numerator_;//знаменатель
		if (denominator_ == r_op.denominator_) {
			l_op1 = numerator_;
			r_op1 = r_op.numerator_;
		}
		else if (numerator_ == r_op.numerator_) {
			l_op1 = r_op.denominator_;
			r_op1 = denominator_;
		}
		return Fraction(l_op1, r_op1);
	}
	Fraction operator++() {
		int l_op1 = numerator_ + denominator_;
		return Fraction(l_op1, denominator_);

	}
	Fraction operator--() {
		int l_op1 = numerator_ - denominator_;
		return Fraction(l_op1, denominator_);
	}	
	Fraction& operator++(int) {
		Fraction temp(*this);
		int l_op1 = numerator_ + denominator_;
		Fraction(l_op1, denominator_);
		return temp;
	}
	Fraction& operator--(int) {
		Fraction temp(*this);
		int l_op1 = numerator_ - denominator_;
		Fraction(l_op1, denominator_);
		return temp;
	}
	Fraction operator-();
};

Fraction Fraction::operator-() {
	int l_op1 = numerator_ * (-1);
	int r_op1 = denominator_ * (-1);;
	return Fraction(l_op1, r_op1);
}

int main()
{
	setlocale(LC_ALL,"Rus");
	int num_num1 = 0, num_den1 = 0, num_num2 = 0, num_den2 = 0;	
	cout << "Введите числитель дроби 1: " << endl;
	cin >> num_num1;
	cout << "Введите числитель дроби 2: " << endl;
	cin >> num_den1;
	cout << "Введите знаменатель дроби 1: " << endl;
	cin >> num_num2;
	cout << "Введите знаменатель дроби 2: " << endl;
	cin >> num_den2;
	Fraction f1(num_num1, num_den1), f2(num_num2, num_den2), f3(0, 0);
	f3 = f1 + f2;
	f3.print();
	f3 = f1 - f2;
	f3.print();
	f3 = f1 * f2;
	f3.print();
	f3 = f1 / f2;
	f3.print();
	f3 = -f1 / (-f2);
	f3.print();
	f3 = ++f1 * f2;
	f3.print();
	f3 = f1++ / f2;
	f3.print();
	f3 = ++f1;
	f3.print();

	return 0;
}