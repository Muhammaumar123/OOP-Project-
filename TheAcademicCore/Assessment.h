# pragma once
#include <string>    
#include <iostream>  
#include"../AcademicEntities/student.h"
using namespace std;
class Assessment {
protected:
	string courseID;
	float maxScore;
	float rawScore;
	string type;
	string studentID;
public:
	virtual void display() = 0;
	virtual string getType() = 0;
	float getRawScore() { 
		return rawScore;
	}
	void setRawScore(float r) { 
		this->rawScore = r;
	}
	float getMaxScore() { 
		return maxScore;
	}
	string getCourseID() {
		return courseID;
	}
	float getPercentage() { 
		return (rawScore / maxScore) * 100;
	}
	string getStudentID() {
		return studentID;
	}
};