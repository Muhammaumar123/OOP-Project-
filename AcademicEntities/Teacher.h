#pragma once 
#include<fstream>
#include"Abstract.h"
#include<iostream>
#include <cstring>
using namespace std;
class Teacher:public Abstract {

	float AverageFeedback;
	char** list;
	int number;//for now assuming that each teacher can be assigned a specific number of course IDs

public:

	Teacher() {
		name = "";
		email = "";
		ID = "";
		AverageFeedback = 0.0;
		number = 5;//assuming 5
		list = new char*[number];
	}

	Teacher(string name , string ID , string email) {
		this->name = name;
		this->email = email;
		this->ID = ID;
		AverageFeedback = 0.0;
		this->number = 3;
		list = new char* [number];
		for (int i = 0; i < number; i++)
			list[i] = nullptr;
	}

	//course ID feature depends on the Course class 
	string getID() { return ID; }

	void displayProfile() override{
		cout << "ID : " << ID << endl;
		cout << "Name : " << name << endl;
		cout << "Email : " << email << endl;
		cout << "Average Feedback : " << AverageFeedback << endl;
		cout << "Assigned Courses : " << endl;
		bool any = false;
		for (int i = 0; i < number; i++) {
			if (list[i] != nullptr) {
				cout << " - " << list[i] << endl;
				any = true;
			}
		}
		if (!any)
			cout << " No courses assigned yet." << endl;
	}

	//Feedback sytem 

	void Feedback();
	~Teacher() {
		for (int i = 0; i < number; i++) {
			delete[] list[i];
		}
		delete[] list;
	}
	void assignCourse(string courseID) {
		if (courseID.empty())
			throw invalid_argument("Course ID cannot be empty !");
		for (int i = 0; i < number; i++) {
			if (list[i] == nullptr) {
				list[i] = new char[courseID.length() + 1];
				strcpy(list[i], courseID.c_str());
				cout << "Course " << courseID << " assigned to " << name << " !" << endl;
				return;
			}
		}
		cout << "Cannot assign more courses ! Max limit is " << number << endl;
	}

	void save_to_file() {
		ofstream Teachers("Teachers.txt",ios::app);
		if (Teachers.is_open())
		{
			Teachers << ID << "|" << name << "|" << email << "|" << AverageFeedback << endl;
			Teachers.close();
		}
		else
		{
			cout << "File Not Found " << endl;
			
		}
	}
	float getAverageFeedback() { 
		return AverageFeedback;
	}
	void setAverageFeedback(float f) {
		this->AverageFeedback = f;
	}
};