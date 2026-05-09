#pragma once
#include"Assessment.h"
#include<string>
#include <iostream>  
#include<fstream>
class Quiz :public Assessment {
	int QuizNo;
	string type;
public:
	Quiz() {
		type = "Quiz";
		maxScore = 0.0;
		rawScore = 0.0;
		courseID = "";
		QuizNo = 0;
	}
	Quiz(int QuizNo, float rawScore, float maxScore, string courseID, string type = "Quiz")
	{
		this->QuizNo = QuizNo;
		this->rawScore = rawScore;
		this->maxScore = maxScore;
		this->courseID = courseID;
		this->type = type;
	}
	void display()override {
		cout << "Course ID :" << courseID;
		cout << endl << "Type : " << type;
		cout << endl << "Max Score : " << maxScore;
		cout << endl << "Raw Score : " << rawScore;
		cout << endl;
	}
	void save_to_file() {
		ofstream Quizzes("Quizzes.txt");
		if (Quizzes.is_open())
		{
			Quizzes << courseID << " " << "|" << " " << QuizNo << " " << "|" << " " << rawScore << " " << "|" << " " << maxScore << " " << "|" << " " << type << " " << endl;
		}
		else
		{
			cout << "File Not Found !"; cout << endl;
			Quizzes.close();
		}
	}
};