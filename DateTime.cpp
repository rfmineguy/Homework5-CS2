#include "DateTime.hpp"
#include <ctime>

DateTime::DateTime()
:DateTime(CurrentDate(), CurrentTime()) {}

DateTime::DateTime(const std::string& d, const std::string& t) 
:datestamp(new std::string(d)), timestamp(new std::string(t)) {}

DateTime::DateTime(const DateTime& dt)
:datestamp(new std::string(*dt.datestamp)), timestamp(new std::string(*dt.timestamp)) {}

DateTime::~DateTime() {
    delete datestamp;
    datestamp = nullptr;
    delete timestamp;
    timestamp = nullptr;
}

std::string DateTime::GetDateTime() const {
    return *datestamp;
}

std::string DateTime::GetTime() const {
    return *timestamp;
}

std::string DateTime::CurrentTime() {
    time_t epochs = time(nullptr);
    return ctime(&epochs);
}

std::string DateTime::CurrentDate() {
    time_t epochs = time(nullptr);
    return ctime(&epochs);
}
