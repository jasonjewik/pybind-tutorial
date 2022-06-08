#include "pet.h"

void Pet::setName(const std::string &name_) { 
    name = name_; 
}

const std::string &Pet::getName() const {
    return name;
}

void Pet::setAge(int age_) {
    age = age_;
}

int Pet::getAge() const {
    return age;
}