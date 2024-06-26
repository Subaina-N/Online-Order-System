#include<iostream>
#include "UtilityFunctions.h"
#include "AVL.h"
#include "user.h"
#include "cart.h"
#include "IMP.cpp"
#include "Order.h"
#include <thread>

using namespace std;


// Global Variables //
AVL avlObj;
AVL_Node avlNode;
user* userObj = new user();
Order* userOrders = new Order();

int menuCap = 5;
string* menuLabels = new string[menuCap];
GList<Item>** menu = new GList<Item>*[menuCap];


// Main Function //
int main() {

	initializeMenu(menuCap, menu, menuLabels);


	int mainPageOpt = 0;
	int userMainMenuOpt = 0;
	int userAfterLoginOpt = 0;


	while (true)
	{
		system("cls");

		mainScreen();


		while (true)
		{
			system("cls");
			mainPage();
			cin >> mainPageOpt;

			if (mainPageOpt == 1)
			{
				avlObj.loadDataFromFile();

				system("cls");
				userMainMenu();
				cin >> userMainMenuOpt;

				if (userMainMenuOpt == 1)
				{
					system("cls");
					userLoginMenu();

					cin.ignore();
					userObj->userLogin();

					if (avlObj.userLoginCheck(userObj) == true) {

						cout << "\n\t\t\tLogin Successfully!! Press any key to continue: ";
						reEnter1: system("pause>0");

						while (true)
						{
							system("cls");
							userAfterLogin();
							cin >> userAfterLoginOpt;


							if (userAfterLoginOpt == 1)
							{
								system("cls");
								userObj->showProfile();
							}
							else if (userAfterLoginOpt == 2)
							{
								int itemQuantity = 0;

								Item* x = SelectItem(menuLabels, menu, menuCap);

								cout << "\n\t\t\t   Enter Select Item Quantity: ";
								cin >> itemQuantity;

								userObj->userCart->insertItem(x, itemQuantity);

								cout << "\n\t\t\t   Item Added to Cart Successfully!!!" << endl;

							}
							else if (userAfterLoginOpt == 3)
							{
								int checkOutOpt = 0;

								while (true)
								{
								reEnter2: system("cls");
									orderMenu();
									cin >> checkOutOpt;

									if (checkOutOpt == 1)
									{
										if (userObj->userCart->isEmpty() == true) {
											cout << "\n\t\t\tCART IS EMPTY!!!\n" << endl;
										}
										else {
											userObj->userCart->printCart();
											cout << endl;
										}
									}
									else if (checkOutOpt == 2)
									{
										cout << "\n\t\t\tPlaced to: " << userObj->getName() << endl;
										userOrders->placeOrder(userObj);
										userObj->userCart->printSlip();
										cout << "\n\t\t\tPlaced at: " << userObj->getAddress();
										cout << "\n\n\t\t\tOrder Placed Successfully!!!\n " << endl;
										std::this_thread::sleep_for(std::chrono::seconds(2));
										cout << "\n\n\t\t\tOrder is delivered" << endl;
									}
									else if (checkOutOpt == 3)
									{
										break;
									}
									else
									{
										cout << "\n\t\t\t   InValid Option!! Press any key to continue: ";
										system("pause>0");
										goto reEnter2;
									}
									system("pause");
								}


							}
							
							else if (userAfterLoginOpt == 4)
							{
								break;
							}
							else
							{
								cout << "\nINAVLID OPTION!! Press Any Key to Continue!!" << endl;
								goto reEnter1;
							}

							system("pause>0");
						}

					}
					else {
						cout << "\n\t\t\tLogin Error!!" << endl;
					}

					system("pause");
				}
				else if (userMainMenuOpt == 2)
				{
					cin.ignore();

					system("cls");
					userSignUpMenu();

					userObj->userSignUp();
					avlObj.insert(userObj);

					system("pause");
				}
				else if (userMainMenuOpt == 3)
				{
					break;
				}
				else
				{
					cout << "\nINAVLID OPTION!! Press Any Key to Continue!!" << endl;
					system("pause>0");
				}
			}
			else if (mainPageOpt == 2)
			{
			return 0;
				
			}
			else
			{
				cout << "\nINVALID OPTION!! Press any key to continue: " << endl;
				system("pause>0");
			}
		}
	}


	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}