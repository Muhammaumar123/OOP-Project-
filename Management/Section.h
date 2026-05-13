#pragma once
#include<iostream>
class Section {
	string SectionName;
	string TeacherID;
	string CourseID;
	string CourseName;
	string VenueID;
	int Capacity;
	string timeslot;
public:
	Section() {
		this->VenueID = "";
		this->SectionName = "";
		this->CourseID = "";
		this->CourseName = "";
		this->TeacherID = "";
	}
	Section(string VenueID,string SectionName, string CourseID,string CourseName,string TeacherID,string timeslot) {
		this->VenueID = VenueID;
		this->SectionName = SectionName;
		this->CourseID = CourseID;
		this->CourseName = CourseName;
		this->TeacherID = TeacherID;
		this->timeslot = timeslot;
	}
	void Display() {
		cout << "======================" << endl;
		cout << "VenueID : " << VenueID << endl;
		cout << "Section Name :" << SectionName << endl;
		cout << "Course ID : " << CourseID<< endl;
		cout << "Course Name : " << CourseName << endl;
		cout << "Teacher ID : " << TeacherID << endl;
		cout << "======================" << endl;
	}
	string getSectionName() {
		return SectionName;
	}
	void setSectionName(string SectionNaam) {
		this->SectionName = SectionNaam;
	}
	string getTeacherID() {
		return TeacherID; 
	}
	string getCourseID() {
		return CourseID; 
	}
	string getVenueID() { 
		return VenueID;
	}
	void setVenueID(string VenueID) {
		this->VenueID = VenueID;
	}
	void setCapacity(int capacity) {
		this->Capacity = capacity;
	}
	int getCapacity() {
		return Capacity;
	}
	string getTimeSlot() {
		return timeslot;
	}
	void setTimeSlot(string time_slot) {
		this->timeslot = time_slot;
	}
};