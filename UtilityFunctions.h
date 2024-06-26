#pragma once
#include <string>
#include <fstream>
#include "AVL.h"
#include "GList.h"
#include "user.h"
#include "Item.h"


ostream& operator<<(ostream& _out, user& temp);
ostream& operator<<(ostream& _out, Item& temp);


//Loading Menu Functions
void initializeMenu(int&, GList<Item>**&, string*&);

void LoadMenu(string, GList<Item>**&, string*&, int&);
void ReSize(GList<Item>**&, string*&, int&);
Item* SelectItem(string* arr, GList<Item>**, int capacity);

//Other Functions
void line();
void heading();
void mainScreen();
void mainPage();
void userMainMenu();
void userLoginMenu();
void userSignUpMenu();
void userAfterLogin();
void userProfile();

void displayMenuCategory();
void displayMenuItems();
void orderMenu();
