#include"student.h"
#include"../TheAcademicCore/Course.h"
#include<iostream>
#include"ExchangeStudent.h"
using namespace std;
void ExchangeStudent::viewTranscript() {
	cout << "====================================" << endl;
	cout << "Transcript for : " << name << " " << "|" << " " << ID << endl;
	cout << "Result : " << P_F << " " << "|" << " " << "Percentage : " << percentage << "%" << endl;
	if (enrolledCourses.empty()) {
		cout << "This student is not enrolled in any courses yet." << endl;
		return;
	}
	for (Course* Courses : enrolledCourses) {
		cout << endl << Courses->getCourseName() << " " << "|" << " " << Courses->getCourseID() << " " << "|" << " " << Courses->getCreditHours() << " " << "|" << " " << P_F << endl;
	}
	cout << "====================================" << endl;
}