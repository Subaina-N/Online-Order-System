#include <iostream>
#include <string>
#include "User.h"
#include "UtilityFunctions.h"



using namespace std;

user::user() {
	userName = " ";
	password = "";
	name = "";
	address = "";
	email = "";
	mobile = "";
	userID = 0;
	userCart = new Cart();
}

// Getters

string user::getUserName() {
	return this->userName;
}
string user::getPassword() {
	return this->password;
}
string user::getName() {
	return this->name;
}
string user::getAddress() {
	return this->address;
}
string user::getEmail() {
	return this->email;
}
string user::getMobile() {
	return this->mobile;
}
int user::getUSerID() {
	return this->userID;
}

// setter

void user::setUserName(string usname) {
	this->userName = usname;
}
void user::setPassword(string pass) {
	this->password = pass;
}
void user::setName(string naem) {
	this->name = naem;
}
void user::setAddress(string add) {
	this->address = add;
}
void user::setEmail(string em) {
	this->email = em;
}
void user::setMobile(string mob) {
	this->mobile = mob;
}
void user::setUserID(int id) {
	this->userID = id;
}

// login

void user::userLogin() {
	string inputUserName, inputPassword;
	cout << "\n\n\n\t\t\t Enter UserName: ";
	getline(cin, inputUserName);
	cout << "\n\t\t\t  Enter Password: ";
	getline(cin, inputPassword);

	// Assuming userID is set from the first character of username
	int userID = static_cast<int>(inputUserName[0]);

	setUserID(userID); // Set the userID

	// Set the captured values directly
	setUserName(inputUserName);
	setPassword(inputPassword);

	
}


void user::userSignUp() {
	string inputData;
	cout << "\n\n\t\t\tSet Username:  ";
	getline(cin, inputData);
	setUserName(inputData);

	// converting first character of user name to ASCII value
	char userChar = ' ';
	int charAscii = 0;
	userChar = inputData[0];
	charAscii = (int)userChar;

		cout<< "\n\t\t\tSet Password: ";
		getline(cin, inputData);
		setPassword(inputData);

		cout<<"\n\t\t\tSet Name : ";
		getline(cin, inputData);
		setName(inputData);

		cout << "\n\t\t\tSet Address: ";
		getline(cin, inputData);
		setAddress(inputData);

		cout << "\n\t\t\tSet Email : ";
		getline(cin, inputData);
		setEmail(inputData);

		cout << "\n\t\t\tSet Mobile : ";
		getline(cin, inputData);
		setMobile(inputData);

		setUserID(charAscii);
		cout << endl;
		ofstream outFile("userDatabase.txt", ios::app);
		if (outFile.is_open()) {
			outFile << userID << "\n"
				<< userName << "\n"
				<< password << "\n"
				<< name << "\n"
				<< address << "\n"
				<< email << "\n"
				<< mobile << "\n\n";
			outFile.close();
			
		}
		else {
			cout << "Error opening file for writing!" << endl;
		}

}

void user::showProfile() {
	userProfile();

	cout << "\n\n\n\t\t\t User ID: " << userID << endl;
	cout<< "\n\n\n\t\t\t User Name " << userName<< endl;
	cout << "\n\n\n\t\t\t  Name " << name << endl;
	cout << "\n\n\n\t\t\t Address " << address << endl;
	cout << "\n\n\n\t\t\t Email " << email << endl;
	cout << "\n\n\n\t\t\t Mobile " << mobile << endl;
	cout << "\n\t";
	for (int i = 0; i < 70; i++) {
		cout << char(220);
	}
	cout << endl;
	cout << "\n\tPress any key to Continue: ";

}
// operator overloading
bool user::operator==(user temp) {
	if (userID == temp.userID && userName == temp.userName && password == temp.password && email == temp.email && address == temp.address && mobile == temp.mobile) {
		return true;
	}
	else return false;
}
bool user::operator!=(user temp) {
	return !(*(this) == temp);
}

