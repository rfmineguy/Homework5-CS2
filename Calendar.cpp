#include "Calendar.hpp"
#include "DateTime.hpp"

#include <iostream>
#include <algorithm>

Calendar::Calendar(int sz)
:arraySize(new int(sz)), lastIndex(new int(-1))  {
    eventDynArray = new Event*[*arraySize];
    //construct the dynamic array's dynamic members
    for (int i = 0; i < *arraySize; i++) {
        eventDynArray[i] = new Event();
    }
}
Calendar::Calendar(const Calendar& cal) {
    
}
Calendar::~Calendar() {
    // std::cout << "Calendar destructor" << std::endl;
    //delete the dynamic objects in the array
    for (int i = 0; i < *arraySize; i++) {
        if (eventDynArray[i]) {
            // std::cout << "Deleting event" << std::endl;
            delete eventDynArray[i];
        }
        eventDynArray[i] = nullptr;
    }
    delete eventDynArray;
    eventDynArray = nullptr;
    delete arraySize;
    arraySize = nullptr;
    delete lastIndex;
    lastIndex = nullptr;
}
Calendar& Calendar::operator=(const Calendar& c) {
    *this->arraySize = *c.arraySize;
    *this->eventDynArray = *c.eventDynArray;
    return *this;
}
Event& Calendar::operator[](int i) {
    return *eventDynArray[i];
}
Event& Calendar::operator[](int i) const {
    return *eventDynArray[i];
}
std::ostream& operator<<(std::ostream& os, const Calendar& c) {
    if(*c.lastIndex==-1){
        os << "Calendar contains 0 events.\n";
    }
    else{
        os << "Calendar contains " << *c.lastIndex << " events.\n";
    }
    os << "--------------------------------------------------\n";
    for (int i = 0; i < *c.lastIndex; i++) {
        os << "Event #" << i+1 << "\n";
        os << "Description : \n";
        os << "\t" << c.eventDynArray[i]->GetDescription() << "\n";
        os << "Date and Time info : \n";
        os << "\t" << c.eventDynArray[i]->GetDateTime() << "\n";
    }
    os << "--------------------------------------------------\n";
    return os;
}
void Calendar::addEvent() {
    // std::cout << "Last Index = " << *lastIndex << std::endl;
    if (*lastIndex >= *arraySize) {
        std::cout << "Not enough space in the calendar for a new event" << std::endl;
        return;
    }
    
    int userChoice = -1;
    do {
        userChoice = -1;
        std::cout << "1. New event\n";
        std::cout << "2. New event using current time and date\n";
        char userChoiceC;
        std::cin >> userChoiceC;
        std::cin.ignore();
        if (isdigit(userChoiceC))
            userChoice = userChoiceC - '0';
    } while(userChoice == -1 || userChoice <= 0 || userChoice > 2);
    

    if (*lastIndex < 0) {
        *lastIndex = 0;
    }
    switch (userChoice) {
    case 1: {
                std::string eventDescriptionStr, dateStr, timeStr;
                std::cout << "Please enter a description for your new event : ";
                std::getline(std::cin, eventDescriptionStr);
                std::cout << "Please enter a date for your new event(Wed 01/21/2001) format : ";
                std::getline(std::cin, dateStr);
                std::cout << "Please enter a time for your new event(10:21:13) format: ";
                std::getline(std::cin, timeStr);

                if (eventDynArray[*lastIndex]) {
                    eventDynArray[*lastIndex]->SetDescription(eventDescriptionStr);
                    eventDynArray[*lastIndex]->SetDateTime(DateTime(dateStr, timeStr));
                }
                break;
            }
    case 2: {
                std::string eventDescriptionStr;
                std::cout << "Please enter a description for your new event : ";
                std::getline(std::cin, eventDescriptionStr);
                std::cout << "Using current time and date\n";
                
                // std::cout << *lastIndex << std::endl;
                if (eventDynArray[*lastIndex]) {
                    // std::cout << "Event not nullptr" << std::endl;
                    eventDynArray[*lastIndex]->SetDescription(eventDescriptionStr);
                    //eventDynArray[*lastIndex]->SetDateTime(DateTime(DateTime::currentDate(), DateTime::currentTime()));
                }
                // std::cout << "passed setDescription\n";
                break;
            }
    }
    (*lastIndex)++;

    sort(eventDynArray, eventDynArray + *lastIndex + 1, [](Event* a, Event* b) {return a->GetDateTime() < b->GetDateTime(); });

}
void Calendar::removeEvent() {
   
    int userInt;
    if (*lastIndex == -1) {
        std::cout << "No events in the calendar" << std::endl;
        return;
    }
    do {
        std::cout << "Enter the index of the event you'd like to remove : ";
        std::cin >> userInt;
        std::cin.clear();
        std::cin.ignore();
    } while(userInt < 0 || userInt >= *lastIndex);

    delete eventDynArray[userInt];
    for (int i = userInt; i < *arraySize; i++) {
        eventDynArray[i] = eventDynArray[i+1];
    }
    (*lastIndex)--;

    /*
    std::cout << "Last Index = " << *lastIndex << std::endl;
    if (*lastIndex < 0) {
        std::cerr << "No events in the calendar. You can't remove anything.\n";
        return;
    }
    int removeIndex = -1;
    do {
        std::cout << "Enter the index of the event you'd like to remove :";
        std::cin >> removeIndex;
        std::cin.ignore();
    } while (removeIndex < 0 || removeIndex >= *lastIndex); //should this be > *lastIndex?
    
    delete eventDynArray[removeIndex];
    eventDynArray[removeIndex] = new Event("", DateTime());
    Event* temp = eventDynArray[removeIndex];
    for (int i = removeIndex; i < *lastIndex; i++) {
        eventDynArray[i] = eventDynArray[i+1];
    }
    eventDynArray[*lastIndex - 1] = temp;
    // delete eventDynArray[*lastIndex];
    //eventDynArray[*lastIndex] = nullptr;
    //DateTime dt_last = DateTime("Wed 12/29/9999", "23:59:59");
    //eventDynArray[*lastIndex] = new Event("oblivion", dt_last);
    (*lastIndex)--;
    if (*lastIndex == 0)
        *lastIndex = -1;
    */
}
