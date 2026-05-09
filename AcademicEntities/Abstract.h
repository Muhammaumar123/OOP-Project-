# pragma once 
#include<string>
using namespace std;
class Abstract {
	protected:
		string name;
	string ID;
	string email;
public:
	virtual void displayProfile() = 0;
	string getName() { return name; }
	string getID() { return ID; }
	string getEmail() { return email; }
	void setEmail(string email) { this->email = email; }
};