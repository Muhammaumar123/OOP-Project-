#pragma once
#include "Assessment.h"
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

class Exam : public Assessment {
	string type;
public:
	Exam() {
		this->type = "";
		this->courseID = "";
		this->maxScore=0.0;
		this->rawScore=0.0;
	}
	Exam(string type, string CourseID, float maxScore, float rawScore) {
		this->type = type;
		this->courseID = CourseID;
		this->maxScore = maxScore;
		this->rawScore = rawScore;
	}
	void display() override {
		cout << "Course ID :" << courseID;
		cout << endl << "Type : " << type;
		cout << endl << "Max Score : " << maxScore;
		cout << endl << "Raw Score : " << rawScore;
		cout << endl;
	}
	void save_to_file() {
		ofstream Exams("Exams.txt");
		if (Exams.is_open())
		{
	         Exams << courseID  << " " << "|" << " " << rawScore << " " << "|" << " " << maxScore << " " << "|" << " " << type << " " << endl;
		}
		else
		{
			cout << "File Not Found !"; cout << endl;
			Exams.close();
		}
	}
};