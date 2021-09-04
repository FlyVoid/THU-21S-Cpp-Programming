#include "goods.h"

class Food : public Goods {
public:
	Food(string, double, int);
	~Food();
	void show() const;
private:
	int date;
};

