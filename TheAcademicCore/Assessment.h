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
};