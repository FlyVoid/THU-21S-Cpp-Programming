#include <iostream>
#include "shop.h"
#include "cart.h"
#include "book.h"
#include "food.h"
using namespace std;

Shop shop;
Cart cart;

int main() {
	cout << "�˿����ã�" << endl;
	cout << "�����ṩ������Ʒ��" << endl;
	shop.show();
	while (true) {
		cout << "������ָ��(b:���빺�ﳵ, p:�鿴���ﳵ, r:�Ƴ����ﳵ, f:����)" << endl; 
		char c;
		cin >> c;
		if (c == 'f') {
			if (cart.number() == 0) {
				cout << "���ٹ����" << endl;
				shop.show();
				cout << "���ۻ�������" << endl;
				continue;
			}
			cout << "��֧����" << cart.price() << endl;
			cout << "лл����ӭ�´�������" << endl;
			break;
		} else if (c == 'b') {
			shop.show();
			cout << "������Ҫ�������Ʒ�����" << endl;
			int id = 0;
			cin >> id;
			if (id <= 0 || id > shop.number()) {
				cout << "���ڶ��ң�" << endl;
			} else {
				cart.add(shop.get(id));
			}
		} else if (c == 'p') {
			if (cart.number() == 0) {
				cout << "���Ĺ��ﳵ�ǿյģ�" << endl;
			} else {
				cart.show();
			}
		} else if (c == 'r') {
			if (cart.number() == 0) {
				cout << "���Ĺ��ﳵ�ǿյģ�" << endl;
			} else {
				cart.show();
				cout << "������Ҫ�Ƴ�����Ʒ�����" << endl;
				int id = 0;
				cin >> id;
				if (id <= 0 || id > cart.number()) {
					cout << "���ڶ��ң�" << endl;
				} else {
					cart.del(id);
				}
			}
		} else {
			cout << "���ڶ��ң�" << endl;
		}
	}
	return 0;
}

