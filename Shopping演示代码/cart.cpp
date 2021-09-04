#include <iostream>
#include "cart.h"
using namespace std;

Cart::Cart() {
	n = 0;
}
Cart::~Cart() {
}
double Cart::price() const {
	double res = 0.0;
	for (int i = 0; i < n; i++)
		res += g[i]->get_price();
	return res;
}
void Cart::add(Goods * p) {
	g[n] = p;
	n++;
}
void Cart::del(int i) {
	for (int j = i - 1; j + 1 < n; j++)
		g[j] = g[j + 1];
	n--;
}
void Cart::show() const {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": ";
		g[i]->show();
	}
}
int Cart::number() const {
	return n;
}

