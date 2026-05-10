#include <iostream>
#include <fstream>


#include "AcademicEntities/RegularStudent.h"
#include "AcademicEntities/ScholarshipStudent.h"
#include "AcademicEntities/ExchangeStudent.h"
#include "AcademicEntities/Teacher.h"
// The Academic Core
#include "TheAcademicCore/Assessment.h"
#include "TheAcademicCore/Course.h"
#include "TheAcademicCore/Exam.h"
#include "TheAcademicCore/Quiz.h"
#include"TheAcademicCore/CoreCourse.h"
using namespace std;
int main() {
	RegularStudent obj("M Umar Imran", "muhammadumarimran43@gmail.com", 4.0, "787878");
	CoreCourse mycourse;
	mycourse.getCourseName()="Mycourse";
	mycourse.getCourseID() = "7878";
	mycourse.setCreditHours(3.0);
	mycourse.setCapacity(50);
	mycourse.enrollStudents(&obj);
	obj.addCourse(&mycourse);
	cout << endl << endl << endl;
	obj.viewTranscript();
	system("pause");
	return 0;
}