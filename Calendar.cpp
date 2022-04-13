#include "Calendar.hpp"
#include <iostream>

Calendar::Calendar(int sz) 
:arraySize(new int(sz)), lastIndex(new int(-1)) {
    
}
Calendar::Calendar(const Calendar& cal) {
    
}
Calendar::~Calendar() {
    for (int i = 0; i < *arraySize; i++) {
        delete eventDynArray[i];
        eventDynArray[i] = nullptr;
    }
    delete eventDynArray;
    eventDynArray = nullptr;
    delete arraySize;
    arraySize = nullptr;
    delete lastIndex;
    lastIndex = nullptr;
}
Calendar& Calendar::operator=(const Calendar& c) {
    *this->arraySize = *c.arraySize;
    *this->eventDynArray = *c.eventDynArray;
    return *this;
}
Event& Calendar::operator[](int i) {
    return *eventDynArray[i];
}
Event& Calendar::operator[](int i) const {
    return *eventDynArray[i];
}
std::ostream& operator<<(std::ostream& os, const Calendar& c) {
    os << "Calendar contains " << *c.lastIndex << " events.\n";
    os << "--------------------------------------------------\n";
    for (int i = 0; i < *c.lastIndex; i++) {
        os << "Event #" << i << "\n";
        os << "Describption : \n";
        os << "\t" << c.eventDynArray[i]->GetDescription() << "\n";
        os << "Date and Time info : \n";
        os << "\t" << c.eventDynArray[i]->GetDateTime() << "\n";
    }
    os << "--------------------------------------------------\n";
    return os;
}
void Calendar::addEvent() {

}
void Calendar::removeEvent() {

}
