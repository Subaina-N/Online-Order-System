#include "Item.h"
Item::Item() {
	price = 0;
	name = "";
}
Item::Item(string n, int p) {
	price = p;
	name = n;
}
void Item::setName(string name) {
	this->name = name;
}
string Item::getName() {
	return name;
}
void Item::setPrice(int a) {
	price = a;
}
int Item::getPrice() {
	return price;
}
bool Item::operator==(Item item) {
	if (price == item.price && name == item.name) {
		return true;
	}
	else return false;
	}
bool Item::operator!=(Item item) {
	return !(*(this) == item);
}