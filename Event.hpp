#include <string>
#include "DateTime.hpp"

class Event {
    public:
        Event();
        Event(std::string desc);
        Event(std::string desc, DateTime dt);
        Event(const Event& e);
        ~Event();

        Event& operator=(const Event& e);
        friend std::ostream& operator<<(std::ostream& os, const Event& e);

        std::string GetDescription() const;
        DateTime GetDateTime() const;

        void SetDescription(const std::string& _desc);
        void SetDateTime(const DateTime& _dt);

    private:
        std::string* description;
        DateTime* dtInfo;
};
