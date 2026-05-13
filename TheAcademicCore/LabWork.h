#pragma once
#include"Assessment.h"
#include<string>
#include <iostream>  
#include<fstream>
class LabWork :public Assessment {
	int LabWorkNo;
	string type;
	float wt;
public:
	LabWork() {
		type = "LabWork";
		maxScore = 0.0;
		rawScore = 0.0;
		courseID = "";
		LabWorkNo = 0;
		wt = 0.0;
	}
	LabWork(int LabWorkNo, string studentID , float rawScore, float maxScore, string courseID, float wt, string type = "LabWork")
	{
		this->LabWorkNo = LabWorkNo;
		this->rawScore = rawScore;
		this->maxScore = maxScore;
		this->courseID = courseID;
		this->studentID = studentID;
		this->type = type;
		this->wt = wt;
	}
	void display()override {
		cout << "Course ID :" << courseID;
		cout << endl << "Type : " << type;
		cout << endl << "Max Score : " << maxScore;
		cout << endl << "Raw Score : " << rawScore;
		cout << endl << "Weightage : " << wt;
		cout << endl;
	}
	void save_to_file() {
		ofstream LabWorks("LabWorks.txt",ios::app);
		if (LabWorks.is_open())
		{
			LabWorks << courseID << " " << "|" << " " << LabWorkNo << " " << "|" << " " << rawScore << " " << "|" << " " << maxScore << " " << "|" << " " << type << " " << "|" << " " << "Weightage : " << " " << "|" << " " << wt << endl;
			LabWorks.close();
		}
		else
		{
			cout << "File Not Found !"; cout << endl;
			
		}
	}
	string getType() override {
		return type;
	}
};