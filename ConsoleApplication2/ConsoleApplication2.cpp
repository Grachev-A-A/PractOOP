// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <locale>
// Cумма цифр
int sum(int a);
// Равны ли первая и последняя цифры?
int fdig_ldig(int a);
int count_del(int a);
int is_prime(int a);
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x, OK = 1, num;
	while (OK) {
		cout << "1. Сумма цифр числа\n";
		cout << "2. Равенство первой и последней цифры\n";
		cout<< "3. Кол-во делителей числа\n";
		cout << "4. Простое число?\n";

		cout << "7. Exit\n";
		cout << "Введите номер задачи:\n";
		cin >> num;
		if (num != 7) {
			cout << "Введите число:\n";
			cin >> x;
		}
		switch (num) {
		case 1: cout << "1 - Сумма цифр равна: " << sum(x) << endl;
			break;
		case 2: if (fdig_ldig(x))
			cout << "2 - Цифры равны\n";
				else
			cout << "2 - Цифры не равны\n";
			break;
		case 3: cout << "3 - Делителей у числа:  " << count_del(x) << endl;
			break;
		case 4: if (is_prime(x))
			cout << "4 - Простое\n";
				else
			cout << "4 - Не простое\n";
			break;
		case 7: OK = 0;
			break;
		default:
			cout << "Доступные номера 1 2 3 4 7\n";
			break;
		}
	}
}

int is_prime(int a) {
	if (a <= 1) return 0;
	int d = 2;
	for (; d*d <= a; d++) {
		if (a%d == 0) return 0;
	}return 1;
}

int count_del(int a) {
	a = abs(a);
	if (a == 1) return a;
	int c = 2;
	for (int d = 2; d <= a / 2; d++) {
		if (a%d == 0) c++;
	}
	return c;
}


int fdig_ldig(int a) {
	if (a < 0) a *= -1;
	int l = a % 10;
	while (a > 9) {
		a /= 10;
	}
	return (a == l) ? 1 : 0;
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



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
