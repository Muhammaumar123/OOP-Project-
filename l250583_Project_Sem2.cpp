#include <iostream>
#include <fstream>

// Academic Entities
#include "AcademicEntities/RegularStudent.h"
#include "AcademicEntities/ScholarshipStudent.h"
#include "AcademicEntities/ExchangeStudent.h"
#include "AcademicEntities/Teacher.h"

// The Academic Core
#include "TheAcademicCore/Assessment.h"
#include "TheAcademicCore/Course.h"
#include "TheAcademicCore/Exam.h"
#include "TheAcademicCore/Quiz.h"

using namespace std;
int main() {
	Assessment* obj = new Quiz(1,2,100,"709", "Quiz");
	obj->display();

	system("pause");
	return 0;
}