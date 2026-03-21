#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::cout << "Monte Carlo SPICE Simulator v1.0" << std::endl;
    std::cout << "====================================" << std::endl;

    if (argc < 2){
        std::cout << "Usage: mc_spice <netlist_file>" << std::endl;
        return 1;
    }

    std::string netlistFile = argv[1];
    std::cout << "Load netlist: " << netlistFile << std::endl;

    // TODO: Add parser, solver, and monte carlo here later

    std::cout << "Parser not added yet" << std::endl;

    return 0;
}