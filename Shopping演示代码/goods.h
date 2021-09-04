#ifndef __GOODS_H__
#define __GOODS_H__

#include <string>
using namespace std;

class Goods {
public:
	Goods(string, double);
	virtual ~Goods();
	virtual void show() const = 0;
	double get_price();
protected:
	string name;
	double price;
};

#endif

