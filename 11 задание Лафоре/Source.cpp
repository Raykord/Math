#include <iostream>
using namespace std;

class Fraction		//����� �����
{
private:
	int cel;		//����� ����� �����
	int chisl;		//���������
	int znam;		//�����������
public:
	Fraction()
	{ }
	Fraction(int a, int c, int z) : cel(a), chisl(c), znam(z)
	{}
	void show()		//�������� �����
	{
		cout << cel << " " << chisl << "/" << znam;
	}
	void input()	//������ �����
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

Fraction Fraction::fadd(Fraction a, Fraction b)		//���������� �����
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
Fraction Fraction::fsub(Fraction a, Fraction b)		//��������� ������
{
	Fraction result;
	if (a.znam == b.znam)		//�������� ��� ������ �����������
	{
		result.cel = a.cel - b.cel;
		result.chisl = a.chisl - b.chisl;
		result.znam = a.znam;

		return check(result);
	}
	else		//�������� ��� ������ ������������ 
	{
		result.cel = a.cel - b.cel;
		result.chisl = a.chisl * b.znam - b.chisl * a.znam;
		result.znam = a.znam * b.znam;
		return check(result);
	}
}

Fraction Fraction::fmul(Fraction a, Fraction b)		//��������� ������
{
	Fraction result;
	if (a.cel != 0 && b.cel != 0)		//�������� ������� ����� �����
		result.cel = a.cel * b.cel;
	else
		result.cel = a.cel + b.cel;
	result.chisl = a.chisl * b.chisl;
	result.znam = a.znam * b.znam;
	return check(result);
}

Fraction Fraction::fdiv(Fraction a, Fraction b)		//������� ������		
{
	Fraction result, temp;
	if (a.cel != 0)		 //�������� ������� ������ � ��� ������� � �����
	{
		a.chisl = a.chisl + a.znam * a.cel;
		a.cel = 0;
	}
	if (b.cel != 0)		 //�������� ������� ������ � ��� ������� � �����
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

Fraction Fraction::check(Fraction result)		//���������� ����� � ����������� ����
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