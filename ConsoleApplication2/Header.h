#pragma once
#include <iostream>
using namespace std;

int sum(int a);
int fdig_ldig(int a);
int count_del(int a);
int is_prime(int a);
int is_progress(int a);
double gorner(int n, int x);
int is_palindrom(int a);


int is_palindrom(int x) {
	int s = 0, copy = x;
	while (x) {
		s = s * 10 + x % 10;
		x /= 10;
	}
	return (s == copy) ? 1 : 0;
}

double gorner(int n, int x) {
	// s = s*x+a
	double a, s = 0;
	cout << "Введите " << n + 1 << " коэффициентов многочлена\n";
	for (int i = n; i >= 0; i--) {
		cin >> a;
		s = s * x + a;
	}
	return s;
}

int is_progress(int x) {
	if (x < 10) return 0;
	if (x < 100) return 1;
	int a = x % 10;
	x /= 10;
	int b = x % 10;
	int d = b - a;
	while (x) {
		if (b - a != d) return 0;
		a = b;
		x /= 10;
		b = x % 10;
	}
	return 1;

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
