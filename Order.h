#pragma once
#include "User.h"
#include "Glist.h"
#include "cart.h"

class Order {

private:
	string* users;
	int* orderQuantity;
	Cart** orders;
	int capacity;
public:
	Order();
	void placeOrder(user* user);
	void reSize(string*&, int*&, Cart**&, int&);
};
