#include "Calendar.hpp"
#include <iostream>

Calendar::Calendar(int sz) {

}

Calendar::Calendar(const Calendar& cal) {

}

Calendar::~Calendar() {

}

Calendar& Calendar::operator=(const Calendar&) {
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
