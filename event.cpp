#include "event.h"
#include <iostream>

// Implementation of Event's display method
void Event::display() const {
    std::cout << "Event Time: " << eventTime 
              << ", Event Type: " << (type == EventType::ARRIVAL ? "Arrival" : "Completion") 
              << std::endl;
}


