#ifndef EVENT
#define EVENT

#include <vector>

class Pet;

class Event {
    public:
        virtual void call(std::vector<Pet*> &pets) { };
        Event* setOwner(Pet* owner_);
    protected:
        Pet* owner;
};

class DoNothing : public Event { };

class AgeAllByOne : public Event {
    public:
        void call(std::vector<Pet*> &pets) override;
};

class AgeAllButMeTo100 : public Event {
    public:
        void call(std::vector<Pet*> &pets) override;
};

#endif