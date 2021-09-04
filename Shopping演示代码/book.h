#include "goods.h"

class Book : public Goods {
public:
	Book(string, double, string);
	~Book();
	void show() const;
private:
	string author;
};

