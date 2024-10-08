#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "priorityQueue.h"
#include "FIFOQueue.h"
#include "event.h"

class Simulation {
public:
    Simulation(int numServers, int totalEvents);
    void run();

private:
    int numServers;         // Number of servers
    int totalEvents;        // Total number of events
    PriorityQueue pq;      // Priority Queue for events
    FIFOQueue fifo;        // FIFO Queue for customers

    void processEvent(const Event& event);
};

#endif // SIMULATION_H


