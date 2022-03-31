#include "Event.hpp"

Event::Event()
    :description(new std::string("")), dtInfo(new DateTime()){}

Event::Event(std::string desc) 
    :description(new std::string(desc)), dtInfo(new DateTime()){}

Event::Event(std::string desc, DateTime dt)
    :description(new std::string(desc)), dtInfo(new DateTime(dt)) {}

Event::Event(const Event& e) 
:description(new std::string(*e.description)), dtInfo(new DateTime(*e.dtInfo)) {
    this->description = new std::string(*e.description);
}

Event::~Event() {
    delete description;
    description = nullptr;
    delete dtInfo;
    dtInfo = nullptr;
}

