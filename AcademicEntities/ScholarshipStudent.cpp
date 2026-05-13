#include"student.h"
#include"../TheAcademicCore/Course.h"
#include<iostream>
#include"ScholarshipStudent.h"
using namespace std;
void ScholarshipStudent::viewTranscript() {
	cout << "====================================" << endl;
	cout << "Transcript for : " << name << " " << "|" << " " << ID << endl;
	cout << "Scholarship Status : " << status << endl;
	if (enrolledCourses.empty()) {
		cout << "This student is not enrolled in any courses yet." << endl;
		return;
	}
	for (Course* Courses : enrolledCourses) {
		cout << endl << Courses->getCourseName() << " " << "|" << " " << Courses->getCourseID() << " " << "|" << " " << Courses->getCreditHours() << " " << "|" << " " << Courses->FinalGrade(this->ID) << "%" << endl;
	}
	cout << "====================================" << endl;
}