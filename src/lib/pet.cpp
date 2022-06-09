#include "pet.h"
#include "event.h"

Pet::Pet(std::string name_, int age_, Event *event_) :
    name(name_), age(age_) { 
    event = event_->setOwner(this);
};