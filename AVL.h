#pragma once
#include "AVL_Node.h"
#include "user.h"
#include "UtilityFunctions.h"
#include <string>
#include "Glist.h"

class AVL 
{
public:
	AVL_Node* root;
	AVL();
	int height(AVL_Node*);
	int B_factor(AVL_Node*);
	AVL_Node* RR_rotation(AVL_Node*);
	AVL_Node* LL_rotation(AVL_Node*);
	AVL_Node* LR_rotation(AVL_Node*);
	AVL_Node* RL_rotation(AVL_Node*);
	AVL_Node* balance(AVL_Node*);
	AVL_Node* search(int);
	bool userLoginCheck(user*);
	void loadDataFromFile();
	void insert(user*);
	void Delete(user*);
	void inorder(AVL_Node*);

};