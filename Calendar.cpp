#include "Calendar.hpp"
#include <iostream>

Calendar::Calendar(int sz) 
:arraySize(new int(sz)){
    
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
    os << "Calendar << " << std::endl;
    return os;
}
void Calendar::addEvent() {

}
void Calendar::removeEvent() {

}
