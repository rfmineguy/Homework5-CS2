#include "Event.hpp"

Event::Event()
    :Event("") {}//description(new std::string("")), dtInfo(new DateTime()){}

Event::Event(std::string desc) 
    :Event(desc, DateTime()) {}//description(new std::string(desc)), dtInfo(new DateTime()) {}

Event::Event(std::string desc, DateTime dt)
    :description(new std::string(desc)), dtInfo(new DateTime(dt)) {
        // std::cout << "Event constructed" << std::endl;
    }

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
    // std::cout << "Event destructed" << std::endl;
}

std::string Event::GetDescription() const {
    return *description;
}

DateTime Event::GetDateTime() const {
    cout << "get date time1" << std::endl;

    return *dtInfo;

}

void Event::SetDescription(const std::string& _desc) {
    std::cout << "Setting description" << std::endl;
    *description = _desc;                           //issue Event.cpp#45
    std::cout << "Set description" << std::endl;
}

void Event::SetDateTime(const DateTime& _dt) {
    cout << "set date time1" << std::endl;
    *dtInfo = _dt;
        cout << "set date time2" << std::endl;

}
