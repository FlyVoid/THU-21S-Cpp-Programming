#include <iostream>
#include "shop.h"
#include "cart.h"
#include "book.h"
#include "food.h"
using namespace std;

Shop shop;
Cart cart;

int main() {
	cout << "顾客您好！" << endl;
	cout << "本店提供以下商品：" << endl;
	shop.show();
	while (true) {
		cout << "请输入指令(b:加入购物车, p:查看购物车, r:移出购物车, f:结账)" << endl; 
		char c;
		cin >> c;
		if (c == 'f') {
			if (cart.number() == 0) {
				cout << "不再逛逛吗？" << endl;
				shop.show();
				cout << "打折还不行吗？" << endl;
				continue;
			}
			cout << "请支付：" << cart.price() << endl;
			cout << "谢谢！欢迎下次再来！" << endl;
			break;
		} else if (c == 'b') {
			shop.show();
			cout << "输入想要购买的商品的序号" << endl;
			int id = 0;
			cin >> id;
			if (id <= 0 || id > shop.number()) {
				cout << "您在逗我？" << endl;
			} else {
				cart.add(shop.get(id));
			}
		} else if (c == 'p') {
			if (cart.number() == 0) {
				cout << "您的购物车是空的！" << endl;
			} else {
				cart.show();
			}
		} else if (c == 'r') {
			if (cart.number() == 0) {
				cout << "您的购物车是空的！" << endl;
			} else {
				cart.show();
				cout << "输入想要移出的商品的序号" << endl;
				int id = 0;
				cin >> id;
				if (id <= 0 || id > cart.number()) {
					cout << "您在逗我？" << endl;
				} else {
					cart.del(id);
				}
			}
		} else {
			cout << "您在逗我？" << endl;
		}
	}
	return 0;
}

