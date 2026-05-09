# pragma once
#include <string>    
#include <iostream>  
using namespace std;
class Assessment {
protected:
	string courseID;
	float maxScore;
	float rawScore;
public:
	virtual void display() = 0;
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
};