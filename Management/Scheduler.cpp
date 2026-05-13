#include"Scheduler.h"
#include<iostream>
using namespace std;
void scheduler::displaySchedule() {
	cout << "====================================" << endl;
	cout << "         SCHEDULE                   " << endl;
	cout << "====================================" << endl;
	if (sec.empty()) {
		cout << "No sections loaded." << endl;
		return;
	}
	for (Section* s : sec) {
		cout << "Section  : " << s->getSectionName() << endl;
		cout << "Course   : " << s->getCourseID() << endl;
		cout << "Teacher  : " << s->getTeacherID() << endl;
		cout << "Venue    : " << s->getVenueID() << endl;
		cout << "Timeslot : " << s->getTimeSlot() << endl;
		cout << "Capacity : " << s->getCapacity() << endl;
		cout << "------------------------------------" << endl;
	}
	cout << "====================================" << endl;
}