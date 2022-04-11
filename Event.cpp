#include "Event.hpp"

Event::Event()
    :description(new std::string("")), dtInfo(new DateTime()){}

Event::Event(std::string desc) 
    :description(new std::string(desc)), dtInfo(new DateTime()){}

Event::Event(std::string desc, DateTime dt)
    :description(new std::string(desc)), dtInfo(new DateTime(dt)) {}

Event::Event(const Event& e) 
    :description(new std::string(*e.description)), dtInfo(new DateTime(*e.dtInfo)) {}

Event& Event::operator=(const Event& e) {
    this->description = new std::string(*e.description);
    this->dtInfo = new DateTime(*e.dtInfo);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Event& e) {
    os << "Event:\n";
    os << "\t Description : " << *e.description << "\n";
    os << "\t DateTime Info : " << *e.dtInfo << "\n";
    return os;
}

Event::~Event() {
    delete description;
    description = nullptr;
    delete dtInfo;
    dtInfo = nullptr;
}

std::string Event::GetDescription() const {
    return *description;
}

DateTime Event::GetDateTime() const {
    return *dtInfo;
}

void Event::SetDescription(const std::string& _desc) {
    *description = _desc;
}

void Event::SetDateTime(const DateTime& _dt) {
    *dtInfo = _dt;
}
