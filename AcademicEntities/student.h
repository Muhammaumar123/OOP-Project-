# pragma once
# include"Abstract.h"
class student :public Abstract {
public:
	virtual float calculateGPA() = 0;
	virtual void viewTranscript() = 0;
};