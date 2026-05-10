#include"student.h"
#include"Course.h"
#include<iostream>
#include"RegularStudent.h"
using namespace std;
void RegularStudent::viewTranscript() {
	cout << "====================================" << endl;
	cout << "Transcript for : " << name << " " << "|" << " " << ID;
	if (enrolledCourses.empty()) {
		cout << "This student is not enrolled in any courses yet." << endl;
		return;
	}
	for (Course*Courses : enrolledCourses ) {
		cout << Courses->getCourseName() << " " << "|" << " " << Courses->getCourseID() << " " << "|" << " " << Courses->getCreditHours() << " " << "|" << " " << Courses->FinalGrade(this->ID) <<"%" << endl;
	}
	cout<< "====================================" << endl;
}