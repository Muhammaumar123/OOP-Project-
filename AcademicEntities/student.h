# pragma once
# include"Abstract.h"
#include<vector>
class Course;
class student :public Abstract {
	protected:
		vector<Course*>enrolledCourses;
public:
	virtual float calculateGPA() = 0;
	virtual void viewTranscript() = 0;
	void addCourse(Course* c) {
		enrolledCourses.push_back(c);
	}
};