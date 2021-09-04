#include "goods.h"

class Cart {
public:
	Cart();
	~Cart();
public:
	double price() const;
	void add(Goods *);
	void del(int);
	void show() const;
	int number() const;
private:
	Goods * g[100];
	int n;
};
