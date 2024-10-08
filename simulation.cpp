#include "simulation.h"
#include <random>
#include <iomanip>
#include <iostream>

// Constructor implementation
Simulation::Simulation(size_t numServers, int numEvents, double lambda, double mu)
    : n(numServers), eventCount(numEvents), lambda(lambda), mu(mu),
      totalServiceTime(0), totalWaitTime(0), totalCustomersServed(0),
      totalCustomersArrived(0), totalSimulationTime(0) {}


// Function to run the simulation
void Simulation::run() {
    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Distributions for arrival and service times
    std::exponential_distribution<> arrivalDistribution(lambda);
    std::exponential_distribution<> serviceDistribution(mu);

    double currentTime = 0.0;

    // Generate initial events
    for (int i = 0; i < eventCount; ++i) {
        currentTime += arrivalDistribution(gen); // Schedule next arrival
        Event arrivalEvent(currentTime, EventType::ARRIVAL);
        pq.enqueue(arrivalEvent);
        totalCustomersArrived++;
    }

    // Process events in the priority queue
    while (!pq.isEmpty()) {
        Event event = pq.dequeue();
        processEvent(event);
    }

    // Display final statistics
    displayFinalStatistics();
}

// Method to process an event
void Simulation::processEvent(Event& event) {
    if (event.type == EventType::ARRIVAL) {
        // Handle arrival event
        if (pq.size() < n) { // Check if there are available servers
            // Customer being served immediately
            double serviceTime = serviceDistribution(); // Get service time
            totalServiceTime += serviceTime;

            // Create a completion event
            Event completionEvent(event.eventTime + serviceTime, EventType::COMPLETION);
            pq.enqueue(completionEvent);
        } else {
            // No servers available; customer waits
            totalWaitTime += (event.eventTime - event.eventTime); // You may want to update this logic
        }
    } else if (event.type == EventType::COMPLETION) {
        // Handle completion event
        totalCustomersServed++;
    }
}

// Display final statistics after the simulation
void Simulation::displayFinalStatistics() {
    std::cout << "Total Customers Arrived: " << totalCustomersArrived << std::endl;
    std::cout << "Total Customers Served: " << totalCustomersServed << std::endl;
    std::cout << "Total Service Time: " << totalServiceTime << std::endl;
    std::cout << "Total Wait Time: " << totalWaitTime << std::endl;
    std::cout << "Total Simulation Time: " << totalSimulationTime << std::endl;
}

// Method to get service time based on the service rate (mu)
double Simulation::serviceDistribution() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> serviceDistribution(mu);
    return serviceDistribution(gen);
}














