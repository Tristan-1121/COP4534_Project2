#include "simulation.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file1> <input_file2>" << std::endl;
        return 1;
    }

    // Open and read from the first input file
    std::ifstream inputFile1(argv[1]);
    std::ifstream inputFile2(argv[2]);

    int n, m;          // Number of servers and events
    double lambda, mu; // Arrival and service rates

    if (inputFile1 >> n >> m >> lambda >> mu) {
        Simulation simulation(n, m, lambda, mu);
        simulation.run(); // This should work correctly if all constructors are set
    } else {
        std::cerr << "Error reading from input file." << std::endl;
    }

    return 0;
}






