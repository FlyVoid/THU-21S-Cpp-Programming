#include <iostream>
#include "book.h"
using namespace std;

Book::Book(string n, double p, string a) : Goods(n, p), author(a) {
}
Book::~Book() {
}
void Book::show() const {
	cout << name << ", " << price << ", " << author << endl;
}

