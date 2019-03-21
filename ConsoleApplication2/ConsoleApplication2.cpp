#include "pch.h"
#include <iostream>
#include <locale>
#include "Header.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x, OK = 1, num;
	while (OK) {
		cout << "1. Сумма цифр числа\n";
		cout << "2. Равенство первой и последней цифры\n";
		cout<< "3. Кол-во делителей числа\n";
		cout << "4. Простое число\n";
		cout << "5. Прогрессия\n";
		cout << "6. Многочлен\n";
		cout << "7. Палиндром\n";
		cout << "8. Exit\n";
		cout << "Введите номер задачи:\n";
		cin >> num;
		if (num != 8) {
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
		case 5:
			if(is_progress(x))
				cout << "5 - Прогрессия\n";
			else
				cout << "5 - Не прогрессия\n";
			break;
		case 6: {
			int n;
			cout << "Inp n\n";
			cin >> n;
			cout << "6 - Значение = " << gorner(n, x) << endl;
			break; }
		case 7:
			if (is_palindrom(x))
				cout << "7 - Палиндром\n";
			else
				cout << "5 - Не палиндром\n";
			break;
		case 8: OK = 0;
			break;
		default:
			cout << "Доступные номера 1 2 3 4 5 6 7 8\n";
			break;
		}
	}
}
