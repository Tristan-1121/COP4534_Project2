#ifndef SIMULATION_H
#define SIMULATION_H

#include "event.h"
#include "customer.h"
#include "priorityQueue.h"
#include <iostream>

class Simulation {
public:
    Simulation(int numServers, int totalEvents, double arrivalRate, double serviceRate);
    void run();

private:
    int n;             // Number of servers
    int m;             // Total number of events
    double lambda;     // Arrival rate
    double mu;         // Service rate
    PriorityQueue pq; // Priority queue for event handling

    void processEvent(Event& event, double& currentTime);
    double generateArrivalTime();  // Generate a random arrival time
    double generateServiceTime();   // Generate a random service time
    void printFinalStatistics();     // Print final statistics of the simulation
};

#endif // SIMULATION_H













