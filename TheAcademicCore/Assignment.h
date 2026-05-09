#pragma once
#include "Assessment.h"
#include <string>
#include <iostream>
using namespace std;

class Assignment : public Assessment {
	string type;
public:
	Assignment() {
		this->type = "";//Solo or gr
		this->courseID = "";
		this->maxScore = 0.0;
		this->rawScore = 0.0;
	}
	Assignment(string type, string CourseID, float maxScore, float rawScore) {
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
};