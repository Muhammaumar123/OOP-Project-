#pragma once
#include"student.h"
#include<fstream>
# include<string>
//student.h has already inherited Abstract class
class ScholarshipStudent :public student{
	string type;
	float minGPA;
	float GPA;
	string status;
public:
	ScholarshipStudent() {
		GPA = 0.0;
		minGPA = 3.2;
		type = "Scholarship Student";
		name = "";
		email = "";
		ID = "";
		status = "";
	}
	ScholarshipStudent(float GPA, string ID, string name, string email, string type = "Scholarship Student") {
		this->type = type;
		
		minGPA = 3.2;
		this->GPA = GPA;
		this->name = name;
		this->email = email;
		this->status = (GPA<minGPA)?"Probation":"Active";
	}
	void save_to_file() {
		ofstream ScholarshipStud("ScholarshipStudent.txt", ios::app);

		if (ScholarshipStud.is_open())
		{
			ScholarshipStud << ID << "|" << name << "|" << type << "|" << GPA << "|" << email<< "|" << status << "\n";
			ScholarshipStud.close();
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
		if (GPA < minGPA)
		{
			this->status = (GPA < minGPA) ? "Probation" : "Active";
			cout << "GPA : " << GPA <<" " << "    Less Than the threshold ! " << endl;
		}
		else if(minGPA == GPA)
		{
			this->status = "At Risk";
			cout << "GPA : " << GPA <<" "<< "At Risk of crossing the threshold" << endl;
		}
		else
		{
			this->status = (GPA < minGPA) ? "Probation" : "Active";
			cout << "GPA : " << GPA << " " << "In safe zone !" << endl;
		}
	}
	float calculateGPA()override {
		if (GPA < minGPA)
			status = "Probation";
		else if (GPA == minGPA)
			status = "At Risk";
		else
			status = "Active";
		return GPA;
	}
	void viewTranscript() override {/*need some more data first*/}
};