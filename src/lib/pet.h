#ifndef PET
#define PET

#include <string>

class Event;

class Pet {
    public:
        Pet(std::string name_, int age_, Event *event_);
        const std::string &getName() const { return name; };
        void setName(std::string name_) { name = name_; };
        int getAge() const { return age; };
        void setAge(int age_) { age = age_; };
        Event *getEvent() { return event; }
    private:
        std::string name;
        int age;
        Event *event;
};

#endif