#include "DateTime.hpp"
#include <ctime>

DateTime::DateTime()
:DateTime(currentDate(), currentTime()) {}

DateTime::DateTime(const std::string d, const std::string t) 
:datestamp(new std::string(d)), timestamp(new std::string(t)) {}


DateTime::DateTime(const DateTime& dt)
:datestamp(new std::string(*dt.datestamp)), timestamp(new std::string(*dt.timestamp)) {}

DateTime::~DateTime() {
    delete datestamp;
    datestamp = nullptr;
    delete timestamp;
    timestamp = nullptr;
}

std::string DateTime::getDate() const {
    return *datestamp;
}

std::string DateTime::getTime() const {
    return *timestamp;
}

std::string DateTime::currentTime() {
    time_t epochs = time(nullptr);
    std::string timeStr = ctime(&epochs);

    return timeStr.substr(11, 8);// + timeStr.substr()
}

std::string DateTime::currentDate() {
    time_t epochs = time(nullptr);
    std::string timeStr = ctime(&epochs);
    return timeStr.substr(0, 10) + timeStr.substr(19, 5);
}

DateTime& DateTime::operator=(const DateTime& other){
    cout << "called the = assignment operator! \n";

    return *this;
}
bool DateTime::operator<(const DateTime& other) const{
    cout << "called the < assignment operator! \n";

    return false;
};
bool DateTime::operator<=(const DateTime& other) const{
    cout << "called the <= assignment operator! \n";
    return false;
}
bool DateTime::operator>(const DateTime& other) const{
    cout << "called the > assignment operator! \n";
    return false;
}
bool DateTime::operator>=(const DateTime& other) const{
    cout << "called the >= assignment operator! \n";
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int this_year = stoi( (*(this->datestamp)).substr(11,4) );
    string this_month_str = ( (*(this->datestamp)).substr(4,3) );
    int this_month;
    for(int i = 0; i <12; i++){
        if(months[i]==this_month_str){
            this_month = i+1;
            break;
        }
    }
    int this_date = stoi( (*(this->datestamp)).substr(8,2) );

//----------------------------------------------------------------
    int other_year = stoi( (*(other.datestamp)).substr(11,4) );
    string other_month_str = ( (*(other.datestamp)).substr(4,3) );
    int other_month;
    for(int i = 0; i <12; i++){
        if(months[i]==other_month_str){
            other_month = i+1;
            break;
        }
    }
    int other_date = stoi( (*(other.datestamp)).substr(8,2) );
//----------------------------------------------------------------
    int this_hour = stoi( (*(this->timestamp)).substr(0,2) );
    int this_minute = stoi( (*(this->timestamp)).substr(3,2) );
    int this_sec = stoi( (*(this->timestamp)).substr(6,2) );
//----------------------------------------------------------------
    int other_hour = stoi( (*(other.timestamp)).substr(0,2) );
    int other_minute = stoi( (*(other.timestamp)).substr(3,2) );
    int other_sec = stoi( (*(other.timestamp)).substr(6,2) );
//----------------------------------------------------------------
    if(this_year >= other_year and this_month >= other_month and this_date >= other_date){ 
        if(this_hour >= other_hour and this_minute >= other_minute and this_sec >= other_sec){
            return true;
        }
    }
    return false;
};
bool DateTime::operator==(const DateTime& other) const{
    cout << "called the == assignment operator! \n";
    if(*(this->datestamp) == *(other.datestamp)){
        if(*(this->timestamp) == *(other.timestamp)){
            return true;
        }
    }
    return false;
};
bool DateTime::operator!=(const DateTime& other) const{
    cout << "called the != assignment operator! \n";
    if(*(this->datestamp) == *(other.datestamp)){
        if(*(this->timestamp) == *(other.timestamp)){
            return false;
        }
    }
    return true;
};
