#include "event.h"
#include <iostream>

// Implementation of Event's display method
void Event::display() const {
    std::cout << "Event Time: " << eventTime << std::endl;
}
