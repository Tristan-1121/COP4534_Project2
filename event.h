#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    double eventTime;  // Time of the event
    // Additional members can be added as needed

    // Constructor
    Event(double time) : eventTime(time) {}

    // Method to display event information (optional)
    void display() const;
};

#endif // EVENT_H

