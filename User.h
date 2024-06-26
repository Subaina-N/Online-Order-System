#pragma once
#include "cart.h"
#include <string>
using namespace std;
class user {
private:
	string userName;
	string password;
	string name;
	string address;
	string email;
	string mobile;
	int userID;

public:
	Cart* userCart;
	user();
	void userSignUp();
	void userLogin();
	void showProfile();
	// getters  //
	string getUserName();
	string getPassword();
	string getName();
	string getAddress();
	string getEmail();
	string getMobile();
	int getUSerID();

	// setter

	void setUserName(string);
	void setPassword(string);
	void setName(string);
	void setAddress(string);
	void setEmail(string);
	void setMobile(string);
	void setUserID(int);
	bool operator ==(user);
	bool operator !=(user);
	friend ostream& operator << (ostream&, user&);

};