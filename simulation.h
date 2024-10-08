#ifndef SIMULATION_H
#define SIMULATION_H

#include "event.h"
#include "priorityQueue.h"  // Include your priority queue header
#include <random>

class Simulation {
public:
    Simulation(size_t numServers, int numEvents, double lambda, double mu);
    void run();

private:
    void processEvent(Event& event);
    void displayFinalStatistics();
    double serviceDistribution();

    size_t n;                  // Number of servers
    int eventCount;           // Number of events to simulate
    double lambda;            // Arrival rate
    double mu;                // Service rate

    double totalServiceTime;   // Total service time
    double totalWaitTime;      // Total wait time
    int totalCustomersServed;   // Total customers served
    int totalCustomersArrived;  // Total customers arrived
    double totalSimulationTime; // Total simulation time

    PriorityQueue pq;          // Your priority queue for events
};

#endif // SIMULATION_H















