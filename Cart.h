#pragma once
#include <iostream>
#include "Item.h"
using namespace std;

class Cart {
private:
	int* quantity;
	Item* items;
	int capacity;
public:
	Cart() {
		quantity = new int[1];
		items = NULL;
		capacity = 0;
	}
	bool isEmpty() {
		if (!items) {
			return true;
		}
		else return false;
	}
	void resize(int*& quant, Item*& list, int& cap, int qt) { // qt quantity of new item user added
		Item* temp = new Item[cap];
		int* qtyTemp = new int[cap];
		for (int i = 0; i < cap; i++) {
			temp[i] = list[i];
			qtyTemp[i] = quant[i];
		}
		delete[] list;
		list = NULL;
		delete[] quant;
		quant = NULL;
		cap++;
		list = new Item[cap];
		quant = new int[cap];
		for (int i = 0; i < cap - 1; i++) {
			list[i] = temp[i];
			quant[i] = qtyTemp[i];
		}
		// Initialize the newly added element
		quant[cap - 1] = qt;
		delete[] temp;
		delete[] qtyTemp;
	}


	void insertItem(Item* item, int qt) {
		if (items == NULL) {
			items = new Item[1];
			items[0] = *item;
			quantity[0] = qt;
			capacity++;

		}
		else {
			for (int i = 0; i < capacity; i++) {
				if (items[i].getName() == item->getName()) {
					quantity[i] += qt;
					break;
				}
				else {
					resize(quantity, items, capacity, qt);
					items[capacity - 1] = *item;
					quantity[capacity - 1] = qt;
					break;
				}
			}
		}
	}
	void printCart() {
		cout << "\n\n\t\tOrder Items: \t\tPrice: \t\t\tQuantity:" << endl;
		for (int i = 0; i < capacity; i++) {
			cout << "\t\t" << items[i].getName() << "\t\t\t" << items[i].getPrice() << "\t\t\t" << quantity[i] << endl;

		}
	}
	void printSlip() {
		int totalPrice = 0, totalQty = 0;
		for (int i = 0; i < capacity; i++) {
			totalPrice += items[i].getPrice() * quantity[i];
			totalQty += quantity[i];
		}
		cout << "\n\t\t\tTotal Items: " << totalQty << endl;
		cout << "\t\t\tTotal Price: " << totalPrice << endl;
	}
};
