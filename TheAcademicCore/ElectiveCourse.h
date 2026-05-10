#pragma once
#include"Course.h"
#include<iostream>
#include<fstream>
#include"Exam.h"
class ElectiveCourse : public Course {

public:
	ElectiveCourse() {
		courseID = "";
		teacherID = "";
		courseName = "";
		creditHours = 0.0;
		capacity = 0;
	}
	//Core Course can be any so I will let the user decide what he wants the capacity and the credit hours to be 
	ElectiveCourse(string courseID, string teacherID, string courseName, float creditHours, int capacity) {
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
	//ElectiveCourse has an exam so need some exam stuff here
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
		return 2;
	}
	float FinalGrade(string StudentID) override{
		float finalGrade;
		float Mid1Total = 0, Mid1Max = 0;
		float Mid2Total = 0, Mid2Max = 0;
		float FinalTotal = 0, FinalMax = 0;
		float QuizTotal = 0, QuizMax = 0;
		float AssgnTotal = 0, AssgnMax = 0;

		for (Assessment* x : Assessments) {
			if (x->getStudentID() == StudentID) {
				if (x->getType() == "Mid1") {
					Mid1Total += x->getRawScore();
					Mid1Max += x->getMaxScore();
				}
				else if (x->getType() == "Mid2") {
					Mid2Total += x->getRawScore();
					Mid2Max += x->getMaxScore();
				}
				else if (x->getType() == "Quiz")
				{
					QuizTotal += x->getRawScore();
					QuizMax += x->getMaxScore();
				}
				else if (x->getType() == "Assignment") {
					AssgnTotal += x->getRawScore();
					AssgnMax += x->getMaxScore();
				}
				else if (x->getType() == "Final") {
					FinalTotal += x->getRawScore();
					FinalMax += x->getMaxScore();
				}
			}
		}//Now the marks have beeen stored

		//time to calculate the percentages
		//using ternary operator becuz it is easy 

		float Mid1Percentage = (Mid1Max > 0) ? (Mid1Total / Mid1Max) * 100 : 0;
		float Mid2Percentage = (Mid2Max > 0) ? (Mid2Total / Mid2Max) * 100 : 0;
		float FinalPercentage = (FinalMax > 0) ? (FinalTotal / FinalMax) * 100 : 0;
		float QuizPercentage = (QuizMax > 0) ? (QuizTotal / QuizMax) * 100 : 0;
		float AssgnPercentage = (AssgnMax > 0) ? (AssgnTotal / AssgnMax) * 100 : 0;


		finalGrade = (Mid1Percentage * 0.10) + (Mid2Percentage * 0.10) + (FinalPercentage * 0.40) + (QuizPercentage * 0.10) + (AssgnPercentage * 0.30);
		return finalGrade;
	}
	void save_to_file() {
		ofstream ElectiveCourses("ElectiveCourse.txt",ios::app);
		if (ElectiveCourses.is_open()) {
			ElectiveCourses << courseID << " " << "|" << " " << courseName << " " << "|" << " " << teacherID << " " << "|" << " " << creditHours << " " << "|" << " " << capacity<<" "<<"|"<<" "<<"Elective" << endl;
		}
		else
		{
			cout << "File Not Found !" << endl;
			ElectiveCourses.close();
		}
	}
};