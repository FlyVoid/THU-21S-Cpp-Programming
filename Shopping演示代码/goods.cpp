#include "goods.h"

Goods::Goods(string n, double p) : name(n), price(p) {
}
Goods::~Goods() {
}
double Goods::get_price() {
	return price;
}

