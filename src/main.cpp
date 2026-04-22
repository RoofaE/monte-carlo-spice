#include <iostream>
#include "parser.h"

int main(int argc, char* argv[]) {
    std::cout << "Monte Carlo SPICE Simulator v1.0\n" << std::endl;
    
    if (argc < 2) {
        std::cout << "Usage: mc_spice <netlist>" << std::endl;
        return 1;
    }
    
    Parser parser(argv[1]);
    if (!parser.parse()) return 1;
    
    std::cout << "Parsed " << parser.getComponents().size() << " components" << std::endl;
    std::cout << "Found " << parser.getNodes().size() << " nodes" << std::endl;
    
    std::cout << "\nSolver below" << std::endl;
    return 0;
}