#include <iostream>

#include "event_dispatcher.h"
#include "event.h"
#include "pet.h"

int main() {
    EventDispatcher event_dispatcher;

    std::vector<Pet*> pets;
    pets.push_back(new Pet("Domino", 2, new AgeAllButMeTo100()));
    pets.push_back(new Pet("Jake the Dog", 32, new DoNothing()));
    pets.push_back(new Pet("Patrick Star", 12, new AgeAllByOne()));
    
    std::cout << "===== START =====\n";
    for (auto it = pets.begin(); it != pets.end(); ++it) {
        std::cout << "Name: " << (*it)->getName() << ", Age: " << (*it)->getAge() << "\n";
        event_dispatcher.push(EventWithPriority((*it)->getEvent(), (*it)->getAge()));
    }

    int i = 0;
    while (event_dispatcher.dispatch(pets)) {
        std::cout << "===== DISPATCH " << i << " =====\n";
        for (auto it = pets.begin(); it != pets.end(); ++it)
            std::cout << "Name: " << (*it)->getName() << ", Age: " << (*it)->getAge() << "\n";
        ++i;
    }

    // We expect Jake to go first, followed by Patrick, then Domino
    // since events are dispatched according to their age, descending
    
    return 0;
}