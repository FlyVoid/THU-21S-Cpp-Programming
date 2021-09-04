#include <iostream>
#include "shop.h"
#include "book.h"
#include "food.h"
using namespace std;

Shop::Shop() {
	g[0] = new Book("aaa", 1.0, "bbb");
	g[1] = new Book("bbb", 2.0, "ccc");
	g[2] = new Food("xxx", 3.0, 365);
	n = 3;
}
Shop::~Shop() {
	for (int i = 0; i < n; i++)
		delete g[i];
}
void Shop::show() const {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": ";
		g[i]->show();
	}
}
int Shop::number() const {
	return n;
}
Goods * Shop::get(int i) const {
	return g[i - 1];
}

