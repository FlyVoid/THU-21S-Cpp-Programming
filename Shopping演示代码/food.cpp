#include <iostream>
#include "food.h"
using namespace std;

Food::Food(string n, double p, int d) : Goods(n, p), date(d) {
}
Food::~Food() {
}
void Food::show() const {
	cout << name << ", " << price << ", " << date << endl;
}

