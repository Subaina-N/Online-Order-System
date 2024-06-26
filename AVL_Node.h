#pragma once                // ensure header file is added only once
#include "GList.h"

class AVL_Node {
private:
	int userID;
	AVL_Node* left;
	AVL_Node* right;
	
public:
	GList<user>* usersList = new GList<user>();
	void setLeft(AVL_Node* a) {
		left = a;
	}
	AVL_Node* getLeft() {
		return left;
	}
	void setRight(AVL_Node* r) {
		right = r;
	}
	AVL_Node* getRight() {
		return right;
	}
	int getUSerid() { return userID; }
	void setUserID(int a) { userID = a; }

};