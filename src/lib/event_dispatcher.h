#ifndef EVENT_DISPATCHER
#define EVENT_DISPATCHER

#include <vector>
#include <queue>

class Event;
class Pet;

struct EventWithPriority {
    Event *event;
    int priority;

    EventWithPriority(Event *event_, int priority_)
        : event(event_), priority(priority_) { };
};

class EventComparator {
    public:
        bool operator() (const EventWithPriority &l, const EventWithPriority &r) const {
            return (l.priority < r.priority);
        }
};

typedef std::priority_queue<EventWithPriority, std::vector<EventWithPriority>, EventComparator> mypq_type;

class EventDispatcher {
    public:
        bool dispatch(std::vector<Pet*> &pets);
        void push(EventWithPriority evtpr) { pq.push(evtpr); };
    private:
        mypq_type pq;
};

#endif