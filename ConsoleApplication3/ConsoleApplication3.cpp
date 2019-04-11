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
void dell_palindrom(int*x, int &n);
void dell_palindrom1(int*x, int &n);
void sort_boobl(int*x, int n);
int sort_boobl_good(int*x, int n);
void sort_insert(int*x, int n);
void create_pal_array(int*x, int n, int* &y, int &ny);
void dell_arrayD(int*&x, int&n, int p);
void insert_arrayD(int*x, int&n, int p, int b);

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
	//inp_array(a, n);
	/*out_array(a, n);
	out_array_right(a, n);*/

	/*inp_array_d1(a, n);
	out_array(a, n);
	inp_array_d2(a, n);
	out_array(a, n);*/
	////Кол-во палиндромов
	//int s = count_palindrom(a, n);
	//if (s)
	//	cout << "Кол-во палиндромов в массиве = " << s << endl;
	//else
	//	cout << "В массиве нет палиндромов!\n";
	// //Индекс первого
	//s = index_first_palindrom(a, n);
	//if (s < 0)
	//	cout << "В массиве нет палиндромов!\n";
	//else
	//	cout << "Первый палиндром имеет индекс " << s << endl;
	////Максимальный палиндром
	//int max;
	//s = max_palindrom(a, n, max);
	//if (s)
	//	cout << "Максимальный палиндром имеет значение = " << max << endl;
	//else
	//	cout << "В массиве нет палиндромов!\n";

	////Вставка в массив
	//int p;
	//cout << "Index for insert: \n";
	//cin >> p;
	//if (p >= 0 && p <= n && (n + 1) < len) {
	//	int b;
	//	cout << "Значение для вставки:\n";
	//	cin >> b;
	//	insert_array(a, n, p, b);
	//	out_array(a, n);
	//	// Удаление
	//	dell_array(a, n, p);
	//	out_array(a, n);
	//}
	//else {
	//	cout << "Позиция вне индексов массива!\n";
	//}
	/*dell_palindrom1(a, n);
	if (n) 
		out_array(a, n);
	else
		cout << "Массив пуст!\n";*/

	//sort_boobl(a, n);
	//out_array(a, n);
	////inp_array(a, n);
	//cout << "Кол-во проходов = " << sort_boobl_good(a, n) << endl;

	//sort_insert(a, n);
	//out_array(a, n);

	int *c = new int[n];
	if (c == NULL) {
		cout << "Out Of Memory!\n";
		return 1;
	}
	inp_array(c, n);
	out_array(c, n);

	int nc, *ca;
	create_pal_array(c, n, ca, nc);
	if (nc)
		out_array(ca, nc);
	else
		cout << "Нет палиндромов!\n";
	dell_arrayD(c, n, 2);
	out_array(c, n);
	cout << "Значение для вставки:\n";
	int b;
	cin >> b;
	insert_array(c, n, 2, b);
	out_array(c, n);
	delete[]c;
	delete[]ca;
}



void create_pal_array(int*x, int n, int* &y, int &ny) {
	ny = 0;
	y = new int[0];

	for (int i = 0; i < n; i++) {
		if (palindrom(x[i])) {
			y = (int*)realloc(y, ++ny * sizeof(int));
			y[ny - 1] = x[i];
		}
	}
}

void sort_insert(int*x, int n) {
	int tmp, j;
	for (int i = 1; i < n; i++) {
		tmp = x[i];
		j = i;
		while (j > 0 && x[j - 1] > tmp) {
			x[j] = x[j - 1];
			j--;
		}
		x[j] = tmp;
	}
}

void sort_boobl(int*x, int n) {
	int tmp;
	for (int j = 1; j < n; j++) {
		for (int i = n - 1; i >= j; i--) {
			if (x[i] < x[i - 1]) {
				tmp = x[i];
				x[i] = x[i - 1];
				x[i - 1] = tmp;
			}
		}
	}
}

int sort_boobl_good(int*x, int n) {
	int tmp, flag;
	for (int j = 1; j < n; j++) {
		flag = 1;
		for (int i = n - 1; i >= j; i--) {
			if (x[i] < x[i - 1]) {
				flag = 0;
				tmp = x[i];
				x[i] = x[i - 1];
				x[i - 1] = tmp;
			}
		}
		if (flag)
			return j;
	}
}

void dell_palindrom(int*x, int &n) {
	for (int i = 0; i < n;) {
		if (palindrom(x[i]))
			dell_array(x, n, i);
		else
			i++;
	}
}void dell_palindrom1(int*x, int &n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		x[j] = x[i];
		if (!palindrom(x[i]))
			j++;
	}
	n = j;
}

void dell_array(int*x, int&n, int p) {
	for (int i = p; i < n-1 ; i++)
		x[i] = x[i + 1];
	n--;
}void dell_arrayD(int*&x, int&n, int p) {
	for (int i = p; i < n-1 ; i++)
		x[i] = x[i + 1];
	n--;
	x = (int*)realloc(x, n * sizeof(int));
}

void insert_array(int*x, int&n, int p, int b) {
	for (int i = n; i >= p + 1; i--)
		x[i] = x[i - 1];
	x[p] = b;
	n++;
}
void insert_arrayD(int*x, int&n, int p, int b) {
	x = (int*)realloc(x, (n + 1) * sizeof(int));
	for (int i = n; i >= p + 1; i--)
		x[i] = x[i - 1];
	x[p] = b;
	n++;
}

int max_palindrom(int *x, int n, int &max) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (palindrom(x[i])) {
			if (!flag) {
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
