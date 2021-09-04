#include "goods.h"

class Shop {
public:
	Shop();
	~Shop();
public:
	void show() const;
	int number() const;
	Goods * get(int) const;
private:
	Goods * g[3];
	int n;
};
