#pragma once
#include"Course.h"
#include<iostream>
#include<fstream>
#include"Exam.h"
#include"LabWork.h"
class LabCourse : public Course {

public:
	LabCourse() {
		courseID = "";
		teacherID = "";
		courseName = "";
		creditHours = 0.0;
		capacity = 0;
	}
	//Core Course can be any so I will let the user decide what he wants the capacity and the credit hours to be 
	LabCourse(string courseID, string teacherID, string courseName, float creditHours, int capacity) {
		this->courseID = courseID;
		this->teacherID = teacherID;
		this->courseName = courseName;
		this->creditHours = creditHours;
		this->capacity = capacity;
	}
	void enrollStudents(student* enroll) {
		if (EnrolledStudents.size() >= capacity) {
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
	//LabCourse has an exam so need some exam stuff here
	void display() override {
		cout << "Course ID    : " << courseID << endl;
		cout << "Course Name  : " << courseName << endl;
		cout << "Teacher ID   : " << teacherID << endl;
		cout << "Credit Hours : " << creditHours << endl;
		cout << "Capacity     : " << capacity << endl;
		cout << "Enrolled     : " << EnrolledStudents.size() << "/" << capacity << endl;
	}
	void list() {
		for (student* x : EnrolledStudents) {
			cout << x->getID() << " - " << x->getName() << endl;
		}
	}
	int getExamDuration() override {
		return 3;
	}
	float FinalGrade(string StudentID) override {
		float finalGrade;
		float LabWMax = 0.0, LabWTotal = 0.0;
		float FinalTotal = 0, FinalMax = 0;
		float QuizTotal = 0, QuizMax = 0;
		float AssgnTotal = 0, AssgnMax = 0;

		for (Assessment* x : Assessments) {
			if (x->getStudentID() == StudentID) {
				
			 if (x->getType() == "Quiz")
				{
					QuizTotal += x->getRawScore();
					QuizMax += x->getMaxScore();
				}
			 else if (x->getType() == "LabWork") {
				 LabWTotal += x->getRawScore();
				 LabWMax += x->getMaxScore();
			 }
				else if (x->getType() == "Final") {
					FinalTotal += x->getRawScore();
					FinalMax += x->getMaxScore();
				}
			}
		}//Now the marks have beeen stored

		//time to calculate the percentages
		//using ternary operator becuz it is easy 

		
		float FinalPercentage = (FinalMax > 0) ? (FinalTotal / FinalMax) * 100 : 0;
		float QuizPercentage = (QuizMax > 0) ? (QuizTotal / QuizMax) * 100 : 0;
		float LabWPercent = (LabWMax > 0) ? (LabWTotal /LabWMax) * 100 : 0;



		finalGrade =  (FinalPercentage * 0.40) + (QuizPercentage * 0.10)+(LabWPercent*0.50);
		return finalGrade;
	}
	void save_to_file() {
		ofstream LabCourses("LabCourse.txt",ios::app);
		if (LabCourses.is_open()) {
			LabCourses << courseID << " " << "|" << " " << courseName << " " << "|" << " " << teacherID << " " << "|" << " " << creditHours << " " << "|" << " " << capacity <<" "<<"|"<<" "<<"LabCourse" << endl;
			LabCourses.close();
		}
		else
		{
			cout << "File Not Found !" << endl;
			
		}
	}
};