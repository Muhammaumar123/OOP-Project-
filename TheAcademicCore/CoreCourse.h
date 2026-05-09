#pragma once
#include"Course.h"
#include<iostream>
#include<fstream>
#include"Exam.h"
class CoreCourse : public Course {
public:
	CoreCourse() {
		courseID="";
		teacherID="";
		courseName="";
		creditHours=0.0;
		capacity=0;
	}
	//Core Course can be any so I will let the user decide what he wants the capacity and the credit hours to be 
	CoreCourse(string courseID, string teacherID, string courseName, float creditHours, int capacity) { 
		this->courseID = courseID;
		this->teacherID = teacherID;
		this->courseName = courseName;
		this->creditHours = creditHours;
		this->capacity = capacity;
	}
	void enrollStudents(student* enroll) { 
		if (EnrolledStudents.size() > capacity) {
			cout << "Capacity Full ! Cannot Enroll more students." << endl;
			return;
		}

			for (student* x : EnrolledStudents)
			{
				if (x->getID() == enroll->getID())
				{
					cout << "Student already enrolled.";
					return;
				}
			}
			
		EnrolledStudents.push_back(enroll);
		cout << enroll->getName() << " enrolled successfully!" << endl;
		
	}
	//CoreCOurse has an exam so need some exam stuff here
	

};