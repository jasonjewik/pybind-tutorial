#include "person.h"

void Person::setName(const std::string &name_) { 
    name = name_; 
}

const std::string &Person::getName() const {
    return name;
}

void Person::setAge(int age_) {
    age = age_;
}

int Person::getAge() const {
    return age;
}