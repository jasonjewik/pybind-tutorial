#include "event.h"
#include "pet.h"

Event* Event::setOwner(Pet* owner_) {
    owner = owner_;
    return this;
}

void AgeAllByOne::call(std::vector<Pet*> &pets) {
    for (auto it = pets.begin(); it != pets.end(); ++it)
        (*it)->setAge((*it)->getAge() + 1);
};

void AgeAllButMeTo100::call(std::vector<Pet*> &pets) {
    for (auto it = pets.begin(); it != pets.end(); ++it)
        (*it)->setAge(*it == owner ? (*it)->getAge() : 100);
};