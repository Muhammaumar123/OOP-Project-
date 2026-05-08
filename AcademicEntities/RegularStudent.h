#pragma once
#include"student.h"
#include<fstream>
# include<string>
//student.h has already inherited Abstract class
class RegularStudent:public student  {
	string type;
	float GPA;
public:
	RegularStudent() {
		type = "Regular Student";
		ID = "";
		name = "";
		email = "";
		GPA = 0.0;
	}
	RegularStudent(string name, string email, float GPA, string ID, string type = "Regular Student") {
	//This is the Parameterized Constructor 
		this->email = email;
		this->ID = ID;
		this->GPA = GPA;
		this->name = name;
		this->type = type;
	}
	float calculateGPA()override {
	//Incomplete Because I first have to add the Course section first 
		return GPA;
	}
	void save_to_file() {
		ofstream RegularStud("RegularStudent.txt" , ios::app);
		
			if (RegularStud.is_open())
			{
				RegularStud << ID << "|" << name << "|" << type << "|" << GPA<<"|"<<email << "\n";
				RegularStud.close();
			}
			else
			{
				cout << "File Not found !";
			}
		
		
	}
	void displayProfile() override {
		cout << "ID : " << ID << endl;
		cout << "Name : " << name << endl;
		cout << "Type : " << type << endl;
		cout << "Email : " << email << endl;
		cout << "GPA : " << GPA << endl;
	}
	void viewTranscript() override{/*need some more data first*/ }
};