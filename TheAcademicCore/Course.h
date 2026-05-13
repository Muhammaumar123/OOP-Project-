#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
/*#include "../AcademicEntities/student.h"  */  
#include "Assessment.h"                   
using namespace std;
class student;
class Course {
protected:
    string	courseID;
	string	teacherID;
	string courseName;
	float creditHours;
	int capacity;
	vector<student*> EnrolledStudents;
	vector<Assessment*> Assessments;
public:
	Course() {
		courseID="";
		teacherID="";
		courseName="";
		creditHours=0.0;
		capacity=0;
	}
	virtual int getExamDuration() = 0;
	virtual float FinalGrade(string StudentID) = 0;
	string getCourseID() { 
		return courseID;
	}
	string getCourseName() { 
		return courseName;
	}
    const string getTeacherID() {
		return teacherID;
	}
	void setTeacherID(string id) { 
		this->teacherID = id;
	}
	void setCourseName(string name) {
		this->courseName = name; 
	}
	void setCourseID(string id) {
		this->courseID = id;
	}
	void setCreditHours(float creditHours) {
		this->creditHours = creditHours;
	}
	const float getCreditHours() {
		return creditHours; 
	}
	int getCapacity() {
		return capacity; 
	}
	void setCapacity(int c) {
		this->capacity = c;
	}
	int getEnrollmentCount() { 
		return EnrolledStudents.size(); 
	}
	void addAssessment(Assessment*a) {
		Assessments.push_back(a);
	}
	virtual void display() = 0;
};