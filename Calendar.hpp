#include "Event.hpp"

class Calendar {
    public:
        Calendar(int sz = 100);
        Calendar(const Calendar& cal);
        ~Calendar();

        Calendar& operator=(const Calendar&);
        Event& operator[](int i);
        Event& operator[](int i) const;
        friend std::ostream& operator<<(std::ostream& os, const Calendar&);

        void addEvent();
        void removeEvent();

    private:
        int* arraySize;
        int* lastIndex;
        Event** eventDynArray;
};
