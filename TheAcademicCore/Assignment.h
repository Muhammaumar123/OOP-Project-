#pragma once
#include "Assessment.h"
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

class Assignment : public Assessment {
	string type;
	float wt;
public:
	Assignment() {
		this->type = "";//Solo or grouped
		this->courseID = "";
		this->maxScore = 0.0;
		this->rawScore = 0.0;
		wt = 0.0;
	}
	Assignment(string CourseID, float maxScore, float rawScore,float wt) {
		this->type = "Assignment";
		this->courseID = CourseID;
		this->maxScore = maxScore;
		this->rawScore = rawScore;
		this->wt = wt;
	}
	void display() override {
		cout << "Course ID :" << courseID;
		cout << endl << "Type : " << type;
		cout << endl << "Max Score : " << maxScore;
		cout << endl << "Raw Score : " << rawScore;
		cout << endl << "Weightage : " << wt;
		cout << endl;
	}
	void save_to_file() {
		ofstream Assignments("Assignments.txt");
		if (Assignments.is_open())
		{
			Assignments << courseID << " " << "|" << " " << rawScore << " " << "|" << " " << maxScore << " " << "|" << " " << type << " " << "|"<<" "<<"Weightage : "<<wt<<endl;
		}
		else
		{
			cout << "File Not Found !"; cout << endl;
			Assignments.close();
		}
	}
	string getType()override {
		return type;
	}
};