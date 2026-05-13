#include"Teacher.h"
#include<iostream>
using namespace std;
void Teacher::Feedback() {
	float rating;
	cout << "====================================" << endl;
	cout << "Enter feedback rating for : " << name << " (0 - 5) : ";
	cin >> rating;
	if (rating < 0 || rating > 5) {
		cout << "Invalid rating ! Must be between 0 and 5." << endl;
		return;
	}
	if (AverageFeedback == 0.0) {
		AverageFeedback = rating;
	}
	else {
		AverageFeedback = (AverageFeedback + rating) / 2;
	}
	cout << "Feedback recorded ! New Average : " << AverageFeedback << endl;
	cout << "====================================" << endl;
}