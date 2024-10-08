#ifndef EVENT_H
#define EVENT_H

enum EventType {
    ARRIVAL,
    COMPLETION
};

class Event {
public:
    double eventTime; // Time of the event
    EventType type;   // Type of the event (ARRIVAL or COMPLETION)

    // Constructor
    Event(double time, EventType eventType) : eventTime(time), type(eventType) {}

    // Method to display event information (optional)
    void display() const;
};

#endif // EVENT_H






