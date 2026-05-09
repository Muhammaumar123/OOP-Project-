#pragma once
#include"student.h"
#include<fstream>
# include<string>
//student.h has already inherited Abstract class
class ExchangeStudent :public student{
	string P_F;
	string type;
	float percentage;
	public:
		ExchangeStudent() {
			 P_F="";
			 type="Exchange Student";
			 percentage=0.0;
		}
		ExchangeStudent(float percentage,string name , string email, string ID,string type="Exchange Student") {
			this->P_F = (percentage >= 50) ? "Pass" : "Fail";
			this->percentage = percentage;
			this->type = type;
			this->name = name;
			this->email = email;
			this->ID = ID;
		}
		float calculateGPA() override {
			return -1;  // not applicable for exchange students
		}
		string getResult() {
			return (percentage >= 50) ? "Pass" : "Fail";
		}
		void save_to_file() {
			ofstream ExchangeStud("ExchangeStudent.txt", ios::app);

			if (ExchangeStud.is_open())
			{
				ExchangeStud << ID << "|" << name << "|" << type << "|" << P_F<<"|"<<percentage << "|" << email << "\n";
				ExchangeStud.close();
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
			cout << "Status : " << P_F << endl;
			cout << "Percentage : " << percentage<< endl;
		}
		void viewTranscript() override {/*need some more data first*/ }
		float getPercentage() { 
			return percentage;
		}
		void setPercentage(float p) {
			this->percentage = p;
			this->P_F = (p >= 50) ? "Pass" : "Fail";
		}
		string getPF() { 
			return P_F;
		}
};