#include <iostream>
#include "parser.h"
#include "circuit.h"
#include "solver.h"

int main(int argc, char* argv[]) {
    std::cout << "Monte Carlo SPICE Simulator v1.0\n" << std::endl;
    
    if (argc < 2) {
        std::cout << "Usage: mc_spice <netlist>" << std::endl;
        return 1;
    }
    
    // Parse netlist
    Parser parser(argv[1]);
    if (!parser.parse()) return 1;
    
    std::cout << "Parsed " << parser.getComponents().size() << " components" << std::endl;
    std::cout << "Found " << parser.getNodes().size() << " nodes" << std::endl;
    
    // Build circuit
    Circuit circuit;
    for (const auto& comp : parser.getComponents()) {
        if (comp.name[0] == 'V') {
            if (comp.nodes.size() >= 2 && comp.params.count("value")) {
                circuit.addVoltageSource(comp.name, comp.nodes[0], comp.nodes[1], 
                                        comp.params.at("value"));
            }
        }
    }
    
    std::cout << "\nCircuit has " << circuit.getNumNodes() << " nodes: ";
    for (const auto& node : circuit.getNodeNames()) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    
    // Solve DC operating point
    Solver solver(circuit);
    Eigen::VectorXd voltages = solver.solveDC();
    
    // Print results
    std::cout << "\n=== DC Operating Point ===" << std::endl;
    const auto& nodeNames = circuit.getNodeNames();
    for (int i = 0; i < voltages.size(); i++) {
        std::cout << "V(" << nodeNames[i] << ") = " << voltages[i] << " V" << std::endl;
    }
    
    return 0;
}