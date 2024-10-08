#include "simulation.h"
#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

// Constructor
Simulation::Simulation(int numServers, int totalEvents)
    : numServers(numServers), totalEvents(totalEvents) {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));
}

// Method to run the simulation
void Simulation::run() {
    for (int i = 0; i < totalEvents; ++i) {
        double eventTime = static_cast<double>(std::rand() % 100); // Example event time generation
        Event event(eventTime);
        pq.push(event); // Push the event into the priority queue
    }

    // Process events in the queue
    while (!pq.empty()) {
        Event event = pq.pop(); // Get the next event
        processEvent(event);    // Process the event
    }
}

// Method to process an event
void Simulation::processEvent(const Event& event) {
    std::cout << "Processing event at time: " << event.eventTime << std::endl;
    // Add more event handling logic here
}

