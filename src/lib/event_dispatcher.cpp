#include "event_dispatcher.h"
#include "event.h"
#include "pet.h"

bool EventDispatcher::dispatch(std::vector<Pet*> &pets) {
    if (!pq.empty()) {
        pq.top().event->call(pets);
        pq.pop();
        return true;
    }
    return false;
}