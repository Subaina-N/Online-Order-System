#pragma once
#include <iostream>
#include "Node.h"
#include "user.h"

using namespace std;

template <typename T>
class GList
{
private:
	Node<T>* root;

public:
	int noe;
	GList();
	~GList();
	bool isEmpty();
	void Insert(T*);
	void Delete(T*);
	bool searchingList(user*);
	void Print();
	Node<T>* Get(int);
	bool operator == (GList);
	bool operator != (GList);

	
};


