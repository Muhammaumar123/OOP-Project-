#include<iostream>
#include<vector>
#include<string>
#include"AcademicEntities/RegularStudent.h"
#include"AcademicEntities/ScholarshipStudent.h"
#include"AcademicEntities/ExchangeStudent.h"
#include"AcademicEntities/Teacher.h"
#include"TheAcademicCore/CoreCourse.h"
#include"TheAcademicCore/ElectiveCourse.h"
#include"TheAcademicCore/LabCourse.h"
#include"TheAcademicCore/Exam.h"
#include"TheAcademicCore/Quiz.h"
#include"TheAcademicCore/Assignment.h"
#include"TheAcademicCore/LabWork.h"
#include"Management/Scheduler.h"
#include"Management/DatabaseManager.h"
using namespace std;


vector<student*> students;
vector<Teacher*> teachers;
vector<Course*> courses;
vector<Section*> sections;
vector<Venue*> venues;
DatabaseManager db;
scheduler sch;
//some extra functions for ease

student* findStudent(string ID) {
	for (student* s : students) {
		if (s->getID() == ID)
			return s;
	}
	return nullptr;
}

Teacher* findTeacher(string ID) {
	for (Teacher* t : teachers) {
		if (t->getID() == ID)
			return t;
	}
	return nullptr;
}

Course* findCourse(string ID) {
	for (Course* c : courses) {
		if (c->getCourseID() == ID)
			return c;
	}
	return nullptr;
}

//Admin

void adminAddStudent() {
	int choice;
	cout << "=====================================" << endl;
	cout << "1. Regular Student" << endl;
	cout << "2. Scholarship Student" << endl;
	cout << "3. Exchange Student" << endl;
	cout << "Enter choice : ";
	cin >> choice;
	string name, ID, email;
	float GPA, percentage;
	cout << "Enter Name : "; 
	getline(cin>>ws, name);
	cout << "Enter ID : "; 
	cin >> ID;
	cout << "Enter Email : "; 
	cin >> email;
	if (choice == 1) {
		cout << "Enter GPA : ";
		cin >> GPA;
		students.push_back(new RegularStudent(name, email, GPA, ID));
		cout << "Regular Student added !" << endl;
	}
	else if (choice == 2) {
		cout << "Enter GPA : "; 
		cin >> GPA;
		students.push_back(new ScholarshipStudent(GPA, ID, name, email));
		cout << "Scholarship Student added !" << endl;
	}
	else if (choice == 3) {
		cout << "Enter Percentage : "; 
		cin >> percentage;
		students.push_back(new ExchangeStudent(percentage, name, email, ID));
		cout << "Exchange Student added !" << endl;
	}
	else {
		cout << "Invalid choice !" << endl;
	}
	cout << "=====================================" << endl;
}

void adminRemoveStudent() {
	string ID;
	cout << "Enter Student ID to remove : "; 
	cin >> ID;
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->getID() == ID) {
			delete students[i];
			students.erase(students.begin() + i);
			cout << "Student removed !" << endl;
			return;
		}
	}
	cout << "Student not found !" << endl;
}

void adminAddTeacher() {
	string name, ID, email;
	cout << "=====================================" << endl;
	cout << "Enter Name : "; 
	getline(cin >> ws, name);
	cout << "Enter ID : "; 
	cin >> ID;
	cout << "Enter Email : "; 
	cin >> email;
	Teacher* newTeacher = new Teacher(name, ID, email);
	cout << "Teacher added !" << endl;
	cout << "Now Assign Courses to Teacher \n";
	string courseID;
	cout << "Enter the Course ID:\n";
	cin >> courseID;
	newTeacher->assignCourse(courseID);
	teachers.push_back(newTeacher);
	cout << "=====================================" << endl;
}

void adminRemoveTeacher() {
	string ID;
	cout << "Enter Teacher ID to remove : "; 
	cin >> ID;
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i]->getID() == ID) {
			delete teachers[i];
			teachers.erase(teachers.begin() + i);
			cout << "Teacher removed !" << endl;
			return;
		}
	}
	cout << "Teacher not found !" << endl;
}

void adminAddCourse() {
	int choice;
	cout << "=====================================" << endl;
	cout << "1. Core Course" << endl;
	cout << "2. Elective Course" << endl;
	cout << "3. Lab Course" << endl;
	cout << "Enter choice : ";
	cin >> choice;
	string courseID, teacherID, courseName;
	float creditHours;
	int capacity;
	cout << "Enter Course ID : ";
	cin >> courseID;
	cout << "Enter Teacher ID : ";
cin >> teacherID;
	cout << "Enter Course Name : "; 
getline(cin>>ws, courseName);
	cout << "Enter Credit Hours : "; 
cin >> creditHours;
	cout << "Enter Capacity : "; 
	cin >> capacity;
	if (choice == 1) {
		courses.push_back(new CoreCourse(courseID, teacherID, courseName, creditHours, capacity));
		cout << "Core Course added !" << endl;
	}
	else if (choice == 2) {
		courses.push_back(new ElectiveCourse(courseID, teacherID, courseName, creditHours, capacity));
		cout << "Elective Course added !" << endl;
	}
	else if (choice == 3) {
		courses.push_back(new LabCourse(courseID, teacherID, courseName, creditHours, capacity));
		cout << "Lab Course added !" << endl;
	}
	else {
		cout << "Invalid choice !" << endl;
	}
	cout << "=====================================" << endl;
}

void adminAddSection() {
	string venueID, sectionName, courseID, teacherID, timeslot;
	int capacity;
	cout << "=====================================" << endl;
	cout << "Enter Section Name : "; 
        getline(cin>>ws, sectionName);
	cout << "Enter Course ID : "; 
   cin >> courseID;
	cout << "Enter Teacher ID : "; 
      cin >> teacherID;
	cout << "Enter Timeslot : "; 
	cin >> timeslot;
	cout << "Enter Capacity : "; 
     cin >> capacity;
	Section* s = new Section("", sectionName, courseID, "", teacherID, timeslot);
	s->setCapacity(capacity);
	sections.push_back(s);
	cout << "Section added !" << endl;
	cout << "=====================================" << endl;
}

void adminAddVenue() {
	string roomID;
	int capacity;
	bool hasComputers;
	cout << "=====================================" << endl;
	cout << "Enter Room ID : "; 
	cin >> roomID;
	cout << "Enter Capacity : ";
	cin >> capacity;
	cout << "Has Computers ? (1 = Yes, 0 = No) : "; cin >> hasComputers;
	venues.push_back(new Venue(roomID, capacity, hasComputers));
	cout << "Venue added !" << endl;
	cout << "=====================================" << endl;
}

void adminViewAll() {
	cout << "=====================================" << endl;
	cout << "             STUDENTS                    " << endl;
	cout << "=====================================" << endl;
	for (student* s : students)
		s->displayProfile();
	cout << "=====================================" << endl;
	cout << "            TEACHERS                    " << endl;
	cout << "=====================================" << endl;
	for (Teacher* t : teachers)
		t->displayProfile();
	cout << "=====================================" << endl;
	cout << "            COURSES                     " << endl;
	cout << "=====================================" << endl;
	for (Course* c : courses)
		c->display();
}

void adminAssignVenues() {
	sch.loadSections(sections);
	sch.loadVenues(venues);
	sch.assignVenues();
	sch.displaySchedule();
}

void adminSaveAll() {
	db.saveAllStudents(students);
	db.saveAllTeachers(teachers);
	db.saveAllCourses(courses);
	db.saveAllSections(sections);
	db.saveAllVenues(venues);
	cout << "All data saved !" << endl;
}

void adminLoadAll() {
	students = db.loadStudents();
	teachers = db.loadTeachers();
	courses = db.loadCourses();
	sections = db.loadSections();
	venues = db.loadVenues();
	cout << "All data loaded !" << endl;
}

void adminMode() {
	int choice;
	do {
		cout << "=====================================" << endl;
		cout << "           ADMIN MODE                " << endl;
		cout << "=====================================" << endl;
		cout << "1.  Add Student" << endl;
		cout << "2.  Remove Student" << endl;
		cout << "3.  Add Teacher" << endl;
		cout << "4.  Remove Teacher" << endl;
		cout << "5.  Add Course" << endl;
		cout << "6.  Add Section" << endl;
		cout << "7.  Add Venue" << endl;
		cout << "8.  Assign Venues and Display Schedule" << endl;
		cout << "9.  View All" << endl;
		cout << "10. Save All" << endl;
		cout << "11. Load All" << endl;
		cout << "0.  Back" << endl;
		cout << "Enter choice : "; cin >> choice;
		if (choice == 1) adminAddStudent();
		else if (choice == 2) adminRemoveStudent();
		else if (choice == 3) adminAddTeacher();
		else if (choice == 4) adminRemoveTeacher();
		else if (choice == 5) adminAddCourse();
		else if (choice == 6) adminAddSection();
		else if (choice == 7) adminAddVenue();
		else if (choice == 8) adminAssignVenues();
		else if (choice == 9) adminViewAll();
		else if (choice == 10) adminSaveAll();
		else if (choice == 11) adminLoadAll();
	} while (choice != 0);
}
//Teacher

void teacherMode() {
	string ID;
	cout << "Enter Your Teacher ID : "; 
	cin >> ID;
	Teacher* t = findTeacher(ID);
	if (t == nullptr) {
		cout << "Teacher not found !" << endl;
		return;
	}
	int choice;
	do {
		cout << "=====================================" << endl;
		cout << "         TEACHER MODE                " << endl;
		cout << "Welcome : " << t->getName() << endl;
		cout << "=====================================" << endl;
		cout << "1. View My Courses and Sections" << endl;
		cout << "2. View Enrolled Students in a Course" << endl;
		cout << "3. Add Assessment" << endl;
		cout << "4. Update Feedback" << endl;
		cout << "0. Back" << endl;
		cout << "Enter choice : "; 
		cin >> choice;

		if (choice == 1) {
			cout << "=====================================" << endl;
			for (Course* c : courses) {
				if (c->getTeacherID() == ID)
					c->display();
			}
			for (Section* s : sections) {
				if (s->getTeacherID() == ID)
					s->Display();
			}
			cout << "=====================================" << endl;
		}
		else if (choice == 2) {
			string courseID;
			cout << "Enter Course ID : "; 
			cin >> courseID;
			Course* c = findCourse(courseID);
			if (c == nullptr) {
				cout << "Course not found !" << endl;
			}
			else {
				CoreCourse* cc = dynamic_cast<CoreCourse*>(c);
				ElectiveCourse* ec = dynamic_cast<ElectiveCourse*>(c);
				LabCourse* lc = dynamic_cast<LabCourse*>(c);
				if (cc) cc->list();
				else if (ec) ec->list();
				else if (lc) lc->list();
			}
		}
		else if (choice == 3) {
			string courseID, studentID;
			cout << "Enter Course ID : "; 
			cin >> courseID;
			cout << "Enter Student ID : "; 
			cin >> studentID;
			Course* c = findCourse(courseID);
			if (c == nullptr) {
				cout << "Course not found !" << endl;
			}
			else {
				int aChoice;
				cout << "1. Exam" << endl;
				cout << "2. Quiz" << endl;
				cout << "3. Assignment" << endl;
				cout << "4. LabWork" << endl;
				cout << "Enter choice : "; 
				cin >> aChoice;
				float maxScore, rawScore, wt;
				cout << "Enter Max Score : "; 
				cin >> maxScore;
				cout << "Enter Raw Score : ";
				cin >> rawScore;
				cout << "Enter Weightage : ";
				cin >> wt;
				if (aChoice == 1) {
					string type;
					cout << "Enter Exam Type (Mid1/Mid2/Final) : "; 
					cin >> type;
					c->addAssessment(new Exam(type, studentID, courseID, maxScore, rawScore, wt));
				}
				else if (aChoice == 2) {
					int quizNo;
					cout << "Enter Quiz No : ";
					cin >> quizNo;
					c->addAssessment(new Quiz(quizNo, rawScore, maxScore, studentID, courseID, wt));
				}
				else if (aChoice == 3) {
					c->addAssessment(new Assignment(courseID, studentID, maxScore, rawScore, wt));
				}
				else if (aChoice == 4) {
					int labNo;
					cout << "Enter Lab Work No : "; 
					cin >> labNo;
					c->addAssessment(new LabWork(labNo, studentID, rawScore, maxScore, courseID, wt));
				}
				cout << "Assessment added !" << endl;
			}
		}
		else if (choice == 4) {
			t->Feedback();
		}
	} while (choice != 0);
}

//student 

void studentMode() {
	string ID;
	cout << "Enter Your Student ID : ";
	cin >> ID;
	student* s = findStudent(ID);
	if (s == nullptr) {
		cout << "Student not found !" << endl;
		return;
	}
	int choice;
	do {
		cout << "=====================================" << endl;
		cout << "         STUDENT MODE                " << endl;
		cout << "Welcome : " << s->getName() << endl;
		cout << "=====================================" << endl;
		cout << "1. View Profile" << endl;
		cout << "2. View Transcript" << endl;
		cout << "3. View Enrolled Courses" << endl;
		cout << "4. Enroll in a Course" << endl;
		cout << "0. Back" << endl;
		cout << "Enter choice : ";
		cin >> choice;

		if (choice == 1) {
			s->displayProfile();
		}
		else if (choice == 2) {
			s->viewTranscript();
		}
		else if (choice == 3) {
			cout << "=====================================" << endl;
			for (Course* c : courses) {
				for (int i = 0; i < c->getEnrollmentCount(); i++) {
					c->display();
				}
			}
			cout << "=====================================" << endl;
		}
		else if (choice == 4) {
			string courseID;
			cout << "Enter Course ID to enroll in : "; cin >> courseID;
			Course* c = findCourse(courseID);
			if (c == nullptr) {
				cout << "Course not found !" << endl;
			}
			else {
				CoreCourse* cc = dynamic_cast<CoreCourse*>(c);
				ElectiveCourse* ec = dynamic_cast<ElectiveCourse*>(c);
				LabCourse* lc = dynamic_cast<LabCourse*>(c);
				if (cc) cc->enrollStudents(s);
				else if (ec) ec->enrollStudents(s);
				else if (lc) lc->enrollStudents(s);
				s->addCourse(c);
			}
		}
	} while (choice != 0);
}



int main() {
	int choice;
	do {
		cout << "=====================================" << endl;
		cout << "    UNIVERSITY MANAGEMENT SYSTEM     " << endl;
		cout << "=====================================" << endl;
		cout << "1. Admin Mode" << endl;
		cout << "2. Teacher Mode" << endl;
		cout << "3. Student Mode" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter choice : "; 
		cin >> choice;
		if (choice == 1) {
			adminMode();
		}
		else if (choice == 2) {
			teacherMode();
		}
		else if (choice == 3) {
			studentMode();
		}
		else if (choice!=0) {
			cout << "Invalid Choice !"<<endl;
		}
	} while (choice != 0);

	cout << "Goodbye !" << endl;
	return 0;
}