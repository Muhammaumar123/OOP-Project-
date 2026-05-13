#pragma once 
#include<iostream>
using namespace std;
class Venue {
	string RoomID;
	int capacity;
	bool hasComputers;
	
public:
	Venue() {
		RoomID = "";
		capacity = 0;
		hasComputers = 0;
	}
	Venue(string RoomID,int Capacity , bool HasComputers) {
		this->RoomID = RoomID;
		this->capacity = Capacity;
		this->hasComputers = HasComputers;
	}
	string getRoomID() {
		return RoomID;
	}
	string gethasComputer() {
		string Availability = (hasComputers == 0) ? "Not Available !" : "Computers are Available";
		return Availability;
	}
	int getCapacity() {
		return this->capacity;
	}
};