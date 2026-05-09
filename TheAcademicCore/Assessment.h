# pragma once
class Assessment {
protected:
	string courseID;
	float maxScore;
	float rawScore;
public:
	virtual void display() = 0;
};