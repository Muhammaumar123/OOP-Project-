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
};