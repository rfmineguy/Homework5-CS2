#ifndef DATE_TIME
#define DATE_TIME

#include <string>
#include <iostream> 

using namespace std;
class DateTime {
    public:
        DateTime();
        DateTime(const std::string d, const std::string t);
        DateTime(const DateTime& dt);
        ~DateTime();

        DateTime& operator=(const DateTime& dt);
        bool operator<(const DateTime&) const;
        bool operator<=(const DateTime&) const;
        bool operator>(const DateTime&) const;
        bool operator>=(const DateTime&) const;
        bool operator==(const DateTime&) const;
        bool operator!=(const DateTime&) const;
        friend std::ostream& operator<<(std::ostream&, const DateTime&);

        std::string getDate() const;            //impl
        std::string getTime() const;                //impl
        
        static std::string currentDate();           //impl
        static std::string currentTime();           //impl

    private:
        std::string* datestamp;
        std::string* timestamp;
};

#endif
