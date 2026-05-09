#pragma once 
#include<fstream>
#include"Abstract.h"
using namespace std;
class Teacher:public Abstract {

	float AverageFeedback;
	char ** list;
	int number;//for now assuming that each teacher can be assigned a specific number of course IDs

public:
	Teacher() {
		name = "";
		email = "";
		ID = "";
		AverageFeedback = 0.0;
		number = 3;//assuming 3
		list = new char*[number];
	}

	Teacher(string name , string ID , string email) {
		this->name = name;
		this->email = email;
		this->ID = ID;
		AverageFeedback = 0.0;
		this->number = 3;
		list = new char*[number];
	}

	//course ID feature depends on the Course class 
	
	void displayProfile() override{
		cout << "ID : " << ID << endl;
		cout << "Name : " << name << endl;
		cout << "Email : " << email << endl;
		cout << "Average Feedback : " << AverageFeedback<< endl;
		cout << "list : "<< endl;
		for (int i = 0; i < number; i++)
		{
			cout << list[i] << endl;
		}
	}

	//Feedback sytem 

	void Feedback() {}

	~Teacher() {
		delete[] list;
	}

	void save_to_file() {
		ofstream Teachers("Teachers.txt");
		if (Teachers.is_open())
		{
			Teachers << ID << "|" << name << "|" << email << "|" << AverageFeedback << endl;
		}
		else
		{
			cout << "File Not Found " << endl;
			Teachers.close();
		}
	}
};