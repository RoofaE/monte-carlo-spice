#include <iostream>
#include "parser.h"
#include "circuit.h"
#include "solver.h"
#include "monte_carlo.h"
#include "statistics.h"

int main(int argc, char* argv[]) {
    std::cout << "Monte Carlo SPICE Simulator v1.0\n" << std::endl;
    
    if (argc < 2) {
        std::cout << "Usage: mc_spice <netlist> [iterations]" << std::endl;
        return 1;
    }
    
    int iterations = 1000;
    if (argc >= 3) {
        iterations = std::stoi(argv[2]);
    }
    
    Parser parser(argv[1]);
    if (!parser.parse()) return 1;
    
    std::cout << "Parsed " << parser.getComponents().size() << " components" << std::endl;
    
    Circuit circuit;
    for (const auto& comp : parser.getComponents()) {
        if (comp.name[0] == 'V' && comp.params.count("value")) {
            if (comp.nodes.size() >= 2) {
                circuit.addVoltageSource(comp.name, comp.nodes[0], comp.nodes[1], 
                                        comp.params.at("value"));
            }
        } else if (comp.name[0] == 'R' && comp.params.count("value")) {
            if (comp.nodes.size() >= 2) {
                circuit.addResistor(comp.name, comp.nodes[0], comp.nodes[1],
                                   comp.params.at("value"));
            }
        }
    }
    
    std::cout << "Circuit has " << circuit.getNumNodes() << " nodes" << std::endl;
    
    MonteCarloEngine mc(iterations, 0.10);
    auto results = mc.run(circuit);
    
    const auto& nodeNames = circuit.getNodeNames();
    for (int nodeIdx = 0; nodeIdx < nodeNames.size(); nodeIdx++) {
        std::vector<double> voltages;
        for (const auto& result : results) {
            if (nodeIdx < result.outputVoltages.size()) {
                voltages.push_back(result.outputVoltages[nodeIdx]);
            }
        }
        
        if (!voltages.empty() && nodeNames[nodeIdx] != "0") {
            std::string nodeName = "V(" + nodeNames[nodeIdx] + ")";
            Statistics::printSummary(voltages, nodeName);
        }
    }
    
    int passed = 0;
    for (const auto& result : results) {
        if (result.passed) passed++;
    }
    double yield = (100.0 * passed) / results.size();
    
    std::cout << "\nYield Analysis" << std::endl;
    std::cout << "Passed: " << passed << "/" << results.size() << std::endl;
    std::cout << "Yield: " << yield << "%" << std::endl;
    
    return 0;
}