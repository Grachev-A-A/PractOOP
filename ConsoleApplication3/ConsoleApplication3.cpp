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
	out_array(a, n);
	out_array_right(a, n);

	inp_array_d1(a, n);
	out_array(a, n);
	inp_array_d2(a, n);
	out_array(a, n);
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
