
#include "pch.h"
#include <iostream>
#include <locale>

int sum(int a);
void sum(int a, int* s);
void sum(int a, int& s);

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите число: ";
	int x;
	cin >> x;
	int s = sum(x);
	cout << "Сумма цифр = " << s << endl;
	cout << "Сумма цифр = " << sum(x) << endl;
	if (!(sum(x) % 7))
		cout << "Сумма цифр делится на 7" << endl;
	else
		cout << "Сумма цифр не делится на 7" << endl;

	int res;
	sum(x, &res);
	cout << "Сумма цифр = " << res << endl;
	cout << "Адрес = " << &res << endl;
	sum(x, res);
	cout << "Сумма цифр = " << res << endl;
	cout << "Адрес = " << &res << endl;
}

int sum(int a)
{
	int s = 0;
	while (a) {
		s += a % 10;
		a /= 10;
	}
	return s;
}

void sum(int a, int * s)
{
	*s = 0;
	while (a) {
		*s += a % 10;
		a /= 10;
	}
}

void sum(int a, int & s)
{
	s = 0;
	while (a) {
		s += a % 10;
		a /= 10;
	}
}
