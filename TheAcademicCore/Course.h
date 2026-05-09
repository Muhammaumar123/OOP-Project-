#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../AcademicEntities/student.h"    
#include "Assessment.h"                   
using namespace std;
class Course {
protected:
    string	courseID;
	string	teacherID;
	string courseName;
	float creditHours;
	int capacity;
	vector<student*> EnrolledStudents;
public:
	Course() {
		courseID="";
		teacherID="";
		courseName="";
		creditHours=0.0;
		capacity=0;
	}
	string getCourseID() { 
		return courseID;
	}
	string getCourseName() { 
		return courseName;
	}
	string getTeacherID() {
		return teacherID;
	}
	void setTeacherID(string id) { 
		this->teacherID = id;
	}
	int getCreditHours() {
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
	virtual void display() = 0;
};