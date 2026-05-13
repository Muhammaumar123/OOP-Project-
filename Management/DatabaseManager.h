#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include"../AcademicEntities/RegularStudent.h"
#include"../AcademicEntities/ScholarshipStudent.h"
#include"../AcademicEntities/ExchangeStudent.h"
#include"../AcademicEntities/Teacher.h"
#include"../TheAcademicCore/CoreCourse.h"
#include"../TheAcademicCore/ElectiveCourse.h"
#include"../TheAcademicCore/LabCourse.h"
#include"../Management/Section.h"
#include"../Management/Venue.h"
using namespace std;
class DatabaseManager {
public:


	void saveAllStudents(vector<student*>& students) {
		for (student* s : students) {//Lemme tell you why I used dynamic cast , It is becuz i made a vector of student and it is an abstract class so for the compiler to know that which student I am talking about I just used dynamic_cast
			RegularStudent* r = dynamic_cast<RegularStudent*>(s);
			ScholarshipStudent* sc = dynamic_cast<ScholarshipStudent*>(s);
			ExchangeStudent* e = dynamic_cast<ExchangeStudent*>(s);
			if (r) {
				r->save_to_file();
			}
			else if (sc) {
				sc->save_to_file();
			}
			else if (e) {
				e->save_to_file();
			}
		}
	}

	void saveAllCourses(vector<Course*>& courses) {
		for (Course* c : courses) {
			CoreCourse* cc = dynamic_cast<CoreCourse*>(c);
			ElectiveCourse* ec = dynamic_cast<ElectiveCourse*>(c);
			LabCourse* lc = dynamic_cast<LabCourse*>(c);
			if (cc) {
				cc->save_to_file();
			}
			else if (ec) {
				ec->save_to_file();
			}
			else if (lc) {
				lc->save_to_file();
			}
		}
	}

	void saveAllTeachers(vector<Teacher*>& teachers) {
		for (Teacher* t : teachers) {
			t->save_to_file();
		}
	}

	void saveAllSections(vector<Section*>& sections) {
		ofstream file("Sections.txt", ios::app);
		if (file.is_open()) {
			for (Section* s : sections) {
				file << s->getVenueID() << "|" << s->getSectionName() << "|" << s->getCourseID() << "|" << s->getTeacherID() << "|" << s->getTimeSlot() << "|" << s->getCapacity() << "\n";
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void saveAllVenues(vector<Venue*>& venues) {
		ofstream file("Venues.txt", ios::app);
		if (file.is_open()) {
			for (Venue* v : venues) {
				file << v->getRoomID() << "|" << v->getCapacity() << "|" << v->gethasComputer() << "\n";
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	

	vector<student*> loadStudents() {
		vector<student*> students;
		loadRegularStudents(students);
		loadScholarshipStudents(students);
		loadExchangeStudents(students);
		return students;
	}

	vector<Course*> loadCourses() {
		vector<Course*> courses;
		loadCoreCourses(courses);
		loadElectiveCourses(courses);
		loadLabCourses(courses);
		return courses;
	}

	vector<Teacher*> loadTeachers() {
		vector<Teacher*> teachers;
		ifstream file("Teachers.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, email, avgFb;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, email, '|');
				getline(ss, avgFb, '|');
				Teacher* t = new Teacher(name, ID, email);
				t->setAverageFeedback(stof(avgFb));
				teachers.push_back(t);
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
		return teachers;
	}

	vector<Section*> loadSections() {
		vector<Section*> sections;
		ifstream file("Sections.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string venueID, sectionName, courseID, teacherID, timeslot, capacity;
				getline(ss, venueID, '|');
				getline(ss, sectionName, '|');
				getline(ss, courseID, '|');
				getline(ss, teacherID, '|');
				getline(ss, timeslot, '|');
				getline(ss, capacity, '|');
				Section* s = new Section(venueID, sectionName, courseID, "", teacherID, timeslot);
				s->setCapacity(stoi(capacity));
				sections.push_back(s);
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
		return sections;
	}

	vector<Venue*> loadVenues() {
		vector<Venue*> venues;
		ifstream file("Venues.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string roomID, capacity, hasComputers;
				getline(ss, roomID, '|');
				getline(ss, capacity, '|');
				getline(ss, hasComputers, '|');
				Venue* v = new Venue(roomID, stoi(capacity), hasComputers == "Computers are Available");
				venues.push_back(v);
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
		return venues;
	}

private:

	

	void loadRegularStudents(vector<student*>& students) {
		ifstream file("RegularStudent.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, type, GPA, email;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, type, '|');
				getline(ss, GPA, '|');
				getline(ss, email, '|');
				students.push_back(new RegularStudent(name, email, stof(GPA), ID));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void loadScholarshipStudents(vector<student*>& students) {
		ifstream file("ScholarshipStudent.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, type, GPA, email, status;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, type, '|');
				getline(ss, GPA, '|');
				getline(ss, email, '|');
				getline(ss, status, '|');
				students.push_back(new ScholarshipStudent(stof(GPA), ID, name, email));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void loadExchangeStudents(vector<student*>& students) {
		ifstream file("ExchangeStudent.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, type, PF, percentage, email;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, type, '|');
				getline(ss, PF, '|');
				getline(ss, percentage, '|');
				getline(ss, email, '|');
				students.push_back(new ExchangeStudent(stof(percentage), name, email, ID));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void loadCoreCourses(vector<Course*>& courses) {
		ifstream file("CoreCourse.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, teacherID, creditHours, capacity, type;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, teacherID, '|');
				getline(ss, creditHours, '|');
				getline(ss, capacity, '|');
				getline(ss, type, '|');
				courses.push_back(new CoreCourse(ID, teacherID, name, stof(creditHours), stoi(capacity)));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void loadElectiveCourses(vector<Course*>& courses) {
		ifstream file("ElectiveCourse.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, teacherID, creditHours, capacity, type;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, teacherID, '|');
				getline(ss, creditHours, '|');
				getline(ss, capacity, '|');
				getline(ss, type, '|');
				courses.push_back(new ElectiveCourse(ID, teacherID, name, stof(creditHours), stoi(capacity)));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}

	void loadLabCourses(vector<Course*>& courses) {
		ifstream file("LabCourse.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				stringstream ss(line);
				string ID, name, teacherID, creditHours, capacity, type;
				getline(ss, ID, '|');
				getline(ss, name, '|');
				getline(ss, teacherID, '|');
				getline(ss, creditHours, '|');
				getline(ss, capacity, '|');
				getline(ss, type, '|');
				courses.push_back(new LabCourse(ID, teacherID, name, stof(creditHours), stoi(capacity)));
			}
			file.close();
		}
		else {
			cout << "File Not Found !" << endl;
		}
	}
};