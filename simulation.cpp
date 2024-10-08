#include "simulation.h"
#include <iostream>
#include <random>

Simulation::Simulation(int numServers, int totalEvents, double arrivalRate, double serviceRate)
    : n(numServers), m(totalEvents), lambda(arrivalRate), mu(serviceRate) {}

void Simulation::run() {
    double currentTime = 0.0;
    

    for (int i = 0; i < m; ++i) {
        double arrivalTime = generateArrivalTime();
        Event arrivalEvent(arrivalTime, ARRIVAL); // Using the new Event constructor
        pq.enqueue(arrivalEvent);
    }

    while (!pq.isEmpty()) {
        Event event = pq.dequeue();
        processEvent(event, currentTime);
    }

    printFinalStatistics();
}

void Simulation::processEvent(Event& event, double& currentTime) {
    if (event.type == ARRIVAL) {
        // Handle arrival
        std::cout << "Processing arrival event at time: " << event.eventTime << std::endl;
        currentTime = event.eventTime;

        // Generate a service time
        double serviceTime = generateServiceTime();
        Event completionEvent(currentTime + serviceTime, COMPLETION); // Using the new Event constructor
        pq.enqueue(completionEvent);
    } else if (event.type == COMPLETION) {
        // Handle completion
        std::cout << "Processing completion event at time: " << event.eventTime << std::endl;
        currentTime = event.eventTime;

        // Logic for completion can be added here
    }
}

double Simulation::generateArrivalTime() {
    // Generate arrival time based on lambda (Exponential distribution)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> d(lambda);
    return d(gen);
}

double Simulation::generateServiceTime() {
    // Generate service time based on mu (Exponential distribution)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> d(mu);
    return d(gen);
}

void Simulation::printFinalStatistics() {
    // Placeholder for final statistics logic
    std::cout << "Final statistics will be displayed here." << std::endl;
}












