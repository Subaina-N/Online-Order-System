#pragma once
#include <iostream>
using namespace std;
class Item {
private:
	int price;
	string name;
public:
	Item();
	Item(string, int);
	void setName(string);
	string getName();
	void setPrice(int);
	int getPrice();
	bool operator==(Item);
	bool operator !=(Item);
	friend ostream& operator <<(ostream& _out, Item& temp);
};