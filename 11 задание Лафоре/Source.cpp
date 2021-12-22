#include <iostream>
using namespace std;

class Fraction		//класс дроби
{
private:
	int cel;		//целая часть дроби
	int chisl;		//числитель
	int znam;		//знаменатель
public:
	Fraction()
	{ }
	Fraction(int a, int c, int z) : cel(a), chisl(c), znam(z)
	{}
	void show()		//показать дробь
	{
		cout << cel << " " << chisl << "/" << znam;
	}
	void input()	//ввести дробь
	{
		cout << "Integer: ";
		cin >> cel;
		cout << "Number: ";
		cin >> chisl;
		cout << "Denominator: ";
		cin >> znam;
	}
	Fraction fadd(Fraction, Fraction);
	Fraction fsub(Fraction, Fraction);
	Fraction fmul(Fraction, Fraction);
	Fraction fdiv(Fraction, Fraction);
	Fraction check(Fraction);
};

Fraction Fraction::fadd(Fraction a, Fraction b)		//сумировать дроби
{
	Fraction result;
	if (a.znam == b.znam)
	{
		result.cel = a.cel + b.cel;
		result.chisl = a.chisl + b.chisl;
		result.znam = a.znam;

		return check(result);
	}
	else
	{
		result.cel = a.cel + b.cel;
		result.chisl = a.chisl * b.znam + b.chisl * a.znam;
		result.znam = a.znam * b.znam;
		return check(result);
	}
}
Fraction Fraction::fsub(Fraction a, Fraction b)		//вычитание дробей
{
	Fraction result;
	if (a.znam == b.znam)		//действия при равном знаменателе
	{
		result.cel = a.cel - b.cel;
		result.chisl = a.chisl - b.chisl;
		result.znam = a.znam;

		return check(result);
	}
	else		//действия при разных знаменателях 
	{
		result.cel = a.cel - b.cel;
		result.chisl = a.chisl * b.znam - b.chisl * a.znam;
		result.znam = a.znam * b.znam;
		return check(result);
	}
}

Fraction Fraction::fmul(Fraction a, Fraction b)		//умножение дробей
{
	Fraction result;
	if (a.cel != 0 && b.cel != 0)		//проверка наличия целой части
		result.cel = a.cel * b.cel;
	else
		result.cel = a.cel + b.cel;
	result.chisl = a.chisl * b.chisl;
	result.znam = a.znam * b.znam;
	return check(result);
}

Fraction Fraction::fdiv(Fraction a, Fraction b)		//деление дробей		
{
	Fraction result, temp;
	if (a.cel != 0)		 //проверка наличия целого и его перевод в дробь
	{
		a.chisl = a.chisl + a.znam * a.cel;
		a.cel = 0;
	}
	if (b.cel != 0)		 //проверка наличия целого и его перевод в дробь
	{
		b.chisl = b.chisl + b.znam * b.cel;
		b.cel = 0;
	}
	temp.chisl = b.chisl;
	b.chisl = b.znam;
	b.znam = temp.chisl;
	result.chisl = a.chisl * b.chisl;
	result.znam = a.znam * b.znam;
	result.cel = 0;
	return check(result);
}

Fraction Fraction::check(Fraction result)		//приведение дроби к нормальному виду
{
	if (result.chisl > result.znam)
	{
		result.cel = result.cel + result.chisl / result.znam;
		result.chisl %= result.znam;
		return result;
	}
	else
		return result;
}

int main()
{
	Fraction c;
	Fraction a;
	Fraction b;
	cout << "Input first fraction: " << endl;
	a.input();
	cout << "Input second fraction: " << endl;
	b.input();
	cout << "Fractions "; a.show(); cout << " and "; b.show(); cout << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	c = c.fadd(a, b);
	cout << "Addition = "; c.show(); cout << endl;
	c = c.fsub(a, b);
	cout << "Subtraction = "; c.show(); cout << endl;
	c = c.fmul(a, b);
	cout << "Multiplication = "; c.show(); cout << endl;
	c = c.fdiv(a, b);
	cout << "Division = "; c.show(); cout << endl;
	return 0;
}