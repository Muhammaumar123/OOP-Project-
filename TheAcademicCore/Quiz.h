#pragma once
#include"Assessment.h"
#include<string>
#include <iostream>  
#include<fstream>
class Quiz :public Assessment {
	int QuizNo;
	string type;
	float wt;
public:
	Quiz() {
		type = "Quiz";
		maxScore = 0.0;
		rawScore = 0.0;
		courseID = "";
		studentID = "";
		QuizNo = 0;
		wt = 0.0;
	}
	Quiz(int QuizNo, float rawScore, float maxScore,string StudentID, string courseID, float wt, string type = "Quiz")
	{
		this->QuizNo = QuizNo;
		this->rawScore = rawScore;
		this->maxScore = maxScore;
		this->courseID = courseID;
		this->studentID = StudentID;
		this->type = type;
		this->wt = wt;
	}
	void display()override {
		cout << "Course ID :" << courseID;
		cout << endl << "Type : " << type;
		cout << endl << "Max Score : " << maxScore;
		cout << endl << "Raw Score : " << rawScore;
		cout << endl << "Weightage : " << wt;
		cout << endl;
	}
	void save_to_file() {
		ofstream Quizzes("Quizzes.txt",ios::app);
		if (Quizzes.is_open())
		{
			Quizzes << courseID << " " << "|" << " " << QuizNo << " " << "|" << " " << rawScore << " " << "|" << " " << maxScore << " " << "|" << " " << type << " " <<"|"<<" "<<"Weightage : "<<" "<<"|"<<" "<<wt << endl;
			Quizzes.close();
		}
		else
		{
			cout << "File Not Found !"; cout << endl;
			
		}
	}
	string getType() override {
		return type;
	}
};