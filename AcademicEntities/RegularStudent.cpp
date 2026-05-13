#include"student.h"
#include"../TheAcademicCore/Course.h"
#include<iostream>
#include"RegularStudent.h"
using namespace std;
void RegularStudent::viewTranscript() {
	cout << "====================================" << endl;
	cout << "Transcript for : " << name << " " << "|" << " " << ID<<endl;
	if (enrolledCourses.empty()) {
		cout << "This student is not enrolled in any courses yet." << endl;
		return;
	}
	for (Course*Courses : enrolledCourses ) {
		cout << endl<<Courses->getCourseName() << " " << "|" << " " << Courses->getCourseID() << " " << "|" << " " << Courses->getCreditHours() << " " << "|" << " " << Courses->FinalGrade(this->ID) <<"%" << endl;
	}
	cout<< "====================================" << endl;
}