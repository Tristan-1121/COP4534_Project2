#include "simulation.h"
#include <iostream>

int main() {
    int numServers;        // Number of servers
    int totalEvents;       // Total number of events to simulate

    // Get user input for number of servers and total events
    std::cout << "Enter number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter total number of events: ";
    std::cin >> totalEvents;

    // Create a Simulation instance
    Simulation simulation(numServers, totalEvents);

    // Run the simulation
    simulation.run();

    return 0;
}

