#include <iostream>
#include <string>
#include <fstream>
#include "AVL.h"
#include "user.h"
#include "Glist.h"

// implementation of  AVL
using namespace std;

AVL::AVL() 
{
	root = NULL;
}

// checking height of AVL
int AVL::height(AVL_Node* temp) {
	int heights = 0;
	if (temp != 0) {
		int left_height = height(temp->getLeft());
		int right_height = height(temp->getRight());
		int max_height = max(left_height, right_height);
		heights = max_height + 1;
	}
	return heights;
}

//calculating Balance factor
int AVL::B_factor(AVL_Node* temp) {
	int left_height = height(temp->getLeft());
	int right_height = height(temp->getRight());
	int b_factor = left_height - right_height;
	return b_factor;
}

// logic for RR Rotation
AVL_Node* AVL::RR_rotation(AVL_Node* parent) {
	AVL_Node* temp;
	temp = parent->getRight();
	parent->setRight(temp->getLeft());
	temp->setLeft(parent);
	return temp;
}

// logic for LL Rotation
AVL_Node* AVL::LL_rotation(AVL_Node* parent) {
	AVL_Node* temp;
	temp = parent->getLeft();
	parent->setLeft(temp->getRight());
	temp->setRight(parent);
	return temp;
}

// logic for RL Rotation
AVL_Node* AVL::RL_rotation(AVL_Node* parent) {
	AVL_Node* temp;
	temp = parent->getRight();
	parent->setRight(LL_rotation(temp));
	return RR_rotation(parent);
}

// logic for LR Rotation
AVL_Node* AVL::LR_rotation(AVL_Node* parent) {
	AVL_Node* temp;
	temp = parent->getLeft();
	parent->setLeft(RR_rotation(temp));
	return LL_rotation(parent);
}

// balancing tree
AVL_Node* AVL::balance(AVL_Node* temp) {
	int bal_factor = B_factor(temp);
	if (bal_factor > 1) {  // if balance factor grater than 1 then rotation will be LL or LR
		if (B_factor(temp->getLeft()) > 0) { temp = LL_rotation(temp); }
		else temp = LR_rotation(temp);
	}
	else if (bal_factor < -1) {  // if balance factor less than -1 then rotation will be RR or RL
		if (B_factor(temp->getRight()) > 0) {
			temp = RL_rotation(temp);
		}
		else temp = RR_rotation(temp);
	}
	return temp;
}

// for login
bool AVL::userLoginCheck(user* obj) {  //user object
	AVL_Node* temp = this->search(obj->getUSerID());
	if (temp == NULL) {
		
		return false;
	}
	else {
		if (temp->usersList->searchingList(obj) ) {
			
			return true;
		}
		else return false;

	}

}

// loading data from file to avl
void AVL::loadDataFromFile() {
	fstream readFile;
	string readFileString;
	int readFileInt;

	readFile.open("userDatabase.txt", ios::in);

	if (!readFile) {
		cout << "\nFile Couldn't Open!!" << endl;
		return;
	}

	while (readFile >> readFileInt) {
		user* obj = new user();
		obj->setUserID(readFileInt);

		readFile.ignore(); // Ignore the newline after the userID

		getline(readFile, readFileString);
		obj->setUserName(readFileString);

		getline(readFile, readFileString);
		obj->setPassword(readFileString);

		getline(readFile, readFileString);
		obj->setName(readFileString);

		getline(readFile, readFileString);
		obj->setAddress(readFileString);

		getline(readFile, readFileString);
		obj->setEmail(readFileString);

		getline(readFile, readFileString);
		obj->setMobile(readFileString);

		

		// passing node to AVL 
		insert(obj);
	}

	cout<<"Data loading complete!\n";
	readFile.close();
}



// search for specific user
AVL_Node* AVL::search(int data) {
	AVL_Node* temp = root;
	while (temp && temp->getUSerid() != data) {
		if (temp->getUSerid() > data) temp = temp->getLeft();
			
		else temp = temp->getRight();
	}
	return temp;
}

// adding user into AVL
void AVL::insert(user* obj) {
	int key = obj->getUSerID();
	AVL_Node* newNode = new AVL_Node();
	newNode->setUserID(key);
	newNode->setLeft(NULL);
	newNode->setRight(NULL);
	AVL_Node* temp = search(obj->getUSerID());
	if (temp == NULL) {
		if (!root) {
			root = newNode;
		}
		else {
			AVL_Node* parent = NULL;
			AVL_Node* child = root;
			while (child && child->getUSerid() != key) {
				parent = child;
				if (child->getUSerid() < key) {
					child = child->getRight();
					if (!child) {
						parent->setRight(newNode);//Set Left Right with New Node
						root = balance(root);
					}
				}
				else if (child->getUSerid() > key) {
					child = child->getLeft();
					if (!child) {
						parent->setLeft(newNode);//Set Left Child with New Node
						root = balance(root);
					}
				}
			}


		}
		//  user data to list
		newNode->usersList->Insert(obj);
	}
	else {
		temp->usersList->Insert(obj);
	}
}




// traversal
void AVL::inorder(AVL_Node* temp) {
	if (temp == NULL) {
		return;
	}
	inorder(temp->getLeft());
	cout << temp->getUSerid() << " ";
	inorder(temp->getRight());
}