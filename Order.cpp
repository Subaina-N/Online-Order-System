#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() {
	capacity = 0;
	users = NULL;
	orders = NULL;
	orderQuantity = NULL;
}

void Order::reSize(string*& arrUsers, int*& arrQty, Cart**& arrOrders,int& cap) {
	int* qtyTemp = new int[cap];
	string* userTemp = new string[cap];
	Cart** orderTemp = new Cart * [cap];
	for (int i = 0; i < cap; i++) {
		qtyTemp[i] = arrQty[i];
		userTemp[i]= arrUsers[i];
		orderTemp[i] = arrOrders[i];
	}
	delete[] arrUsers;
	arrUsers = NULL;
	delete[] arrQty;
	arrQty = NULL;
	delete[] arrOrders;
	arrOrders = NULL;

	arrUsers = new string[cap + 1];
	arrQty = new int[cap + 1];
	arrOrders = new Cart * [cap + 1];

	for (int i = 0; i < cap - 1; i++) {
		arrUsers[i] = userTemp[i];
		arrQty[i] = qtyTemp[i];
		arrOrders[i] = orderTemp[i];

	}
	cap++;

}

void Order::placeOrder(user* user) {
	if (!users) {
		users = new string[1];
		users[0] = user->getUserName();
		orderQuantity = new int[1];
		orderQuantity[0] = 1;
		orders = new Cart * [1];
		orders[0] = new Cart[5];
		orders[0][0] = *user->userCart;
		capacity++;

	}
	else {
		for (int i = 0; i < capacity; i++) {
			if (users[i] == user->getUserName()) {
				orderQuantity[i]++;
				orders[i][orderQuantity[i] - 1] = *user->userCart;
			}
			else {
				reSize(users, orderQuantity, orders, capacity);
				users[capacity - 1] = user->getUserName();
				orders[i][capacity - 1] = *user->userCart;
				orderQuantity[capacity - 1]++;
			}
		}
	}

}