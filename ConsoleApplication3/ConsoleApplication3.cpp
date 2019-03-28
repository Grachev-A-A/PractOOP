// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <locale>
#include <iostream>

void inp_array(int x[], int n);
void out_array(int* x, int n);
void out_array_right(int* x, int n);
void inp_array_d1(int x[], int n);
void inp_array_d2(int x[], int n);
int palindrom(int a);
int count_palindrom(int *x, int n);
int index_first_palindrom(int *x, int n);
int max_palindrom(int *x, int n, int &max);
void insert_array(int*x, int&n, int p, int b);
void dell_array(int*x, int&n, int p);

using namespace std;

const int len = 100;
int main()
{
	setlocale(LC_ALL, "rus");
	int a[len], n;
	cout << "Inp n\n";
	cin >> n;
	if (n <= 0 || n > len) {
		cout << "Size must be > 0 and < len!\n";
		return 1;
	}
	inp_array(a, n);
	/*out_array(a, n);
	out_array_right(a, n);*/

	/*inp_array_d1(a, n);
	out_array(a, n);
	inp_array_d2(a, n);
	out_array(a, n);*/
	//Кол-во палиндромов
	int s = count_palindrom(a, n);
	if (s)
		cout << "Кол-во палиндромов в массиве = " << s << endl;
	else
		cout << "В массиве нет палиндромов!\n";
	// Индекс первого
	s = index_first_palindrom(a, n);
	if (s < 0)
		cout << "В массиве нет палиндромов!\n";
	else
		cout << "Первый палиндром имеет индекс " << s << endl;
	//Максимальный палиндром
	int max;
	s = max_palindrom(a, n, max);
	if (s)
		cout << "Максимальный палиндром имеет значение = " << max << endl;
	else
		cout << "В массиве нет палиндромов!\n";

	//Вставка в массив
	int p;
	cout << "Index for insert: \n";
	cin >> p;
	if (p >= 0 && p <= n && (n + 1) < len) {
		int b;
		cout << "Значение для вставки:\n";
		cin >> b;
		insert_array(a, n, p, b);
		out_array(a, n);
		// Удаление
		dell_array(a, n, p);
		out_array(a, n);
	}
	else {
		cout << "Позиция вне индексов массива!\n";
	}

}

void dell_array(int*x, int&n, int p) {
	for (int i = p; i < n-1 ; i++)
		x[i] = x[i + 1];
	n--;
}

void insert_array(int*x, int&n, int p, int b) {
	for (int i = n; i >= p + 1; i--)
		x[i] = x[i - 1];
	x[p] = b;
	n++;
}

int max_palindrom(int *x, int n, int &max) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (palindrom(x[i])) {
			if (flag == 0) {
				max = x[i];
				flag = 1;
			}
			else
				max = max > x[i] ? max : x[i];
		}
	}
	return flag;
}

int index_first_palindrom(int *x, int n) {
	for (int i = 0; i < n; i++) {
		if (palindrom(x[i])) return i;
	}
	return -1;
}

int count_palindrom(int *x, int n) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (palindrom(x[i])) c++;
	}
	return c;
}

int palindrom(int a) {
	int s = 0, copia = a;
	while (a) {
		s = s * 10 + a % 10;
		a /= 10;
	}
	return s == copia ? 1 : 0;
}

void inp_array(int x[], int n) {
	cout << "Inp " << n << " numbers!\n";
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}
void out_array(int* x, int n) {
	cout << "\nArray:\n";
	for (int i = 0; i < n; i++) {
		cout << x[i]<<" ";
	}
	cout << endl;
}
void out_array_right(int* x, int n) {
	cout << "\nArray (reversed):\n";
	for (int i = n-1; i >= 0; i--) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void inp_array_d1(int x[], int n) {
	for (int i = 0; i < n; i++) {
		x[i] = rand();
	}
}

void inp_array_d2(int x[], int n) {
	srand(time_t(0));
	for (int i = 0; i < n; i++) {
		x[i] = rand();
	}
}
