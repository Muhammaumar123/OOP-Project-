#pragma once
#include<iostream>
#include<vector>
#include"../Management/Venue.h"
#include"../Management/Section.h"
#include<fstream>
#include<string>
using namespace std;
class scheduler {
    string timeSlots[12] = {
        // thse are Morning slots
        "Mon 9:00-12:00",
        "Tue 9:00-12:00",
        "Wed 9:00-12:00",
        "Thu 9:00-12:00",

        // these Afternoon slots
        "Mon 13:00-16:00",//in this i used 24 hour format like FAST
        "Tue 13:00-16:00",
        "Wed 13:00-16:00",
        "Thu 13:00-16:00",

    };
    vector<Section*>sec;
    vector<Venue*>ven;
public:
   
    void loadSections(vector<Section*>s) {
        sec = s;
    }
    void loadVenues(vector<Venue*>v) {
        ven = v;
    }
    bool hasVenueConflict(string VenueID,string time_slot) {
        for (Section* s : sec) {
            if (s->getVenueID()==VenueID&&s->getTimeSlot()==time_slot) {
                return true;
            }
        }
        return false;
    }
    bool hasCapacityConflict(int Venuecapacity ) {
        for (Section*s :sec) {
            if (s->getCapacity() > Venuecapacity)
                return true;
        }
   
            return false;
    }
    bool hasTeacherConflict(string teacherID, string timeSlot) {
        for (Section* s : sec) {
            if (s->getTeacherID() == teacherID &&
                s->getTimeSlot() == timeSlot) {
                return true; 
            }
        }
        return false;
    }
    string AllotNextSlot(string TeacherID, string VenueID)
    {
        for (int i = 0; i < 8; i++)
        {
            if (!hasVenueConflict(VenueID, timeSlots[i]) && !hasTeacherConflict(TeacherID, timeSlots[i])) {
                return timeSlots[i];
            }
        }
        return "None left";
    }
    bool venueFits (Venue*V,Section*s){
       if(V->getCapacity()<s->getCapacity()){
           return false;
        }
       return true;
    }
    void assignVenues() {
        for (Section* s : sec) {
            bool assigned = false;

            for (Venue* v : ven) {
                if (!venueFits(v, s)) { 
                    continue;
                }
                if (hasVenueConflict(v->getRoomID(), s->getTimeSlot())) {
                    continue;
                }

                s->setVenueID(v->getRoomID());
                assigned = true;
                cout << "Assigned " << v->getRoomID()
                    << " to section " << s->getSectionName() << endl;
                break;
            }

            if (!assigned) {
                
                string newSlot = AllotNextSlot(s->getTeacherID(), "");

                if (newSlot == "None left") {
                    cout << "Could not schedule section "
                        << s->getSectionName() << " — no slots or venues left." << endl;
                    continue;
                }

               
                s->setTimeSlot(newSlot);

                for (Venue* v : ven) {
                    if (!venueFits(v, s)) {
                        continue;
                    }
                    if (hasVenueConflict(v->getRoomID(), newSlot)) {
                        continue;
                    }

                    s->setVenueID(v->getRoomID());
                    cout << "Rescheduled section " << s->getSectionName()<< " to " << newSlot<< " in " << v->getRoomID() << endl;
                    break;
                }
            }
        }
    }
    void displaySchedule();
};