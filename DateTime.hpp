#include <string>
using namespace std;
class DateTime {
    public:
        DateTime();
        DateTime(const std::string& d, const std::string& t);
        DateTime(const DateTime& dt);
        ~DateTime();

        DateTime& operator=(const DateTime& dt);
        bool operator<(const DateTime&) const;
        bool operator<=(const DateTime&) const;
        bool operator>(const DateTime&) const;
        bool operator>=(const DateTime&) const;
        bool operator==(const DateTime&) const;
        bool operator!=(const DateTime&) const;
        friend std::ostream& operator<<(const std::ostream&, const DateTime&);

        std::string GetDateTime() const;            //impl
        std::string GetTime() const;                //impl
        
        static std::string CurrentDate();           //impl
        static std::string CurrentTime();           //impl

    private:
        std::string* datestamp;
        std::string* timestamp;
};
