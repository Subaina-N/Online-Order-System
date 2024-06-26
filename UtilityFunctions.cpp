#include "UtilityFunctions.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& _out, user& temp) {
    _out << temp.userName<< endl << temp.password << endl << temp.userID << endl << temp.email << endl << temp.mobile << endl << temp.address << endl;
    return _out;
}

ostream& operator<<(ostream& _out, Item& temp) {
    _out << "Item Name: " << temp.name << endl << "\t\t\t\t" << "Item Price: " << temp.price << endl;
    return _out;
}

//Loading Menu Functions

void initializeMenu(int& menuCap, GList<Item>**& menu, string*& menuLabels) {
    for (int i = 0; i < menuCap; i++) {
        menu[i] = new GList<Item>();
    }

    LoadMenu("Menu List.txt", menu, menuLabels, menuCap);
}

void LoadMenu(string fileName, GList<Item>**& list, string*& arr, int& capacity) {
    fstream file;
    file.open(fileName, ios::in);

    if (!file) {
        cout << "Couldn't Open\n";
    }
    else {
        int index = -1;
        int price;
        string _name;
        while (!file.eof()) {
            if (index == capacity - 1) {
                ReSize(list, arr, capacity);
            }
            getline(file, _name);
            if (_name[0] == 'C' && _name[1] == 'a' && _name[2] == 't' && _name[3] == 'e' && _name[4] == 'g' && _name[5] == 'o' && _name[6] == 'r' && _name[7] == 'y' && _name[8] == '_') {
                index++;
                arr[index] = _name;
                getline(file, _name);
            }
            file >> price;
            Item* x = new Item(_name, price);
            getline(file, _name);
            list[index]->Insert(x);
        }
    }
}

void ReSize(GList<Item>**& list, string*& arr, int& capacity) {
    int i = 0;
    string* temp = new string[capacity];
    GList<Item>** templist = new GList<Item>*[capacity];

    for (i = 0; i < capacity; i++) {
        temp[i] = arr[i];
        templist[i] = list[i];
    }

    delete[] arr;
    arr = NULL;

    delete[] list;
    list = NULL;

    arr = new string[capacity + 1];
    list = new GList<Item>*[capacity + 1];

    for (i = 0; i < capacity; i++) {
        arr[i] = temp[i];
        list[i] = templist[i];
    }

    capacity++;

    list[capacity - 1] = new GList<Item>();
}

Item* SelectItem(string* arr, GList<Item>** menu, int capacity) {
    int selection = 0, op = 0;

    while (1) {
        system("cls");

        displayMenuCategory();

        for (int i = 0; i < capacity - 1; i++) {
            cout << "\t\t\t\t" << i + 1 << ". " << arr[i] << endl;
        }

        cout << "\n\t\t\t   Select Category-->";
        cin >> op;
        
        line();

        if (op > 0 && op <= capacity - 1) {
            system("cls");
            displayMenuItems();

            menu[op - 1]->Print();

            cout << "\n\t\t\t   Select Item-->";
            cin >> selection;
          if (selection > 0 && selection <= menu[op - 1]->noe) {
                return &(menu[op - 1]->Get(selection - 1)->_data);
            }
            else {
                cout << "Wrong Selection\n";
                system("pause");
            }
        }
        else if (op == '0') {
            return NULL;
        }
        else {
            cout << "Wrong Selection\n";
            system("pause");
        }
    }
}

//Extra Functions
void line() {
    cout << "\n\t";
    for (int i = 0; i < 70; i++) {
        cout << char(220);
    }
    cout << endl;
}

void heading() {
    line();
    cout << "\n\t\t\t   RESTURANT ORDERING SYSTEM\t\t\t" << endl;
    line();
}

void mainScreen() {
    heading();
    cout << endl;

    for (int i = 0; i < 4; i++) {
        cout << "\t\t/////////////////////////////////////////////////////\n";
    }

    for (int i = 0; i < 2; i++) {
        cout << "\t\t////                                             ////\n";
    }

    cout << "\t\t////      //////   /////    /////      //////    ////\n";
    cout << "\t\t////    /////  //  /////    /////    /////  //   ////\n";
    cout << "\t\t////    /////      /////    /////    /////       ////\n";
    cout << "\t\t////     /////     //////////////     /////      ////\n";
    cout << "\t\t////      /////    //////////////      /////     ////\n";
    cout << "\t\t////       /////   /////    /////       /////    ////\n";
    cout << "\t\t////       /////   /////    /////       /////    ////\n";
    cout << "\t\t////  //  /////    /////    /////  //  /////     ////\n";
    cout << "\t\t////   //////      /////    /////   //////       ////\n";

    for (int i = 0; i < 2; i++) {
        cout << "\t\t////                                             ////\n";
    }

    for (int i = 0; i < 4; i++) {
        cout << "\t\t/////////////////////////////////////////////////////\n";
    }

    line();

    cout << "\n\tPress any key to Continue: ";
    system("pause>0");
}

void mainPage() {
    heading();
    cout << "\n\t\t\t\t1 -	User Panel\t\t\t\n" << endl;
    cout << "\t\t\t\t2 -	Exit\t\t\t" << endl;
    line();

    cout << "\n\tEnter the Option: ";
}

void userMainMenu() {
    heading();
    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " USER PANEL ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }

    cout << "\n\n\t\t\t\t   1 - Login\t\t\t\n" << endl;
    cout << "\t\t\t\t   2 - Sign Up\t\t\t\n" << endl;
    cout << "\t\t\t\t   3 - Exit\t\t\t" << endl;

    line();

    cout << "\n\tEnter the Option: ";
}

void userLoginMenu() {
    heading();
    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " USER LOGIN ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }
}

void userSignUpMenu() {

    heading();
    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " USER SIGN UP ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }

    cout << endl;
}

void userAfterLogin() {
    heading();
    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " USER MENU ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }

    cout << "\n\n\n\t\t\t\t  1 - Show Profile\t\t\t\n" << endl;
    cout << "\t\t\t\t  2 - View Menu\t\t\t\n" << endl;
    cout << "\t\t\t\t  3 - Check Out\t\t\t\n" << endl;
    
    cout << "\t\t\t\t  4 - Logout\t\t\t\n" << endl;

    line();

    cout << "\n\tEnter the Option: ";
}


void userProfile() {
    line();

    cout << "\n\t\t\t   RESTURANT ORDERING SYSTEM\t\t\t" << endl;

    line();

    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " USER PROFILE ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }
}


void displayMenuCategory() {
    heading();
    cout << "\n\t\t\t\t Menu Categories\t\t\t" << endl;
    line();
    cout << endl;
}

void displayMenuItems() {
    heading();
    cout << "\n\t\t\t\t Menu Items\t\t\t" << endl;
    line();
    cout << endl;
}


void orderMenu() {
    heading();
    cout << "\n\n\t\t\t     ";
    for (int i = 0; i < 5; i++) {
        cout << char(219);
    }

    cout << " CHECKOUT ";

    for (int k = 0; k < 5; k++) {
        cout << char(219);
    }

    cout << "\n\n\t\t\t\t   1 - View Order\t\t\t\n" << endl;
    cout << "\t\t\t\t   2 - Procceed to CheckOut\t\t\t\n" << endl;
    cout << "\t\t\t\t   3 - Exit\t\t\t" << endl;

    line();

    cout << "\n\tEnter the Option: ";
}