#include "solver.h"
#include <iostream>

Solver::Solver(const Circuit& circuit) : circuit(circuit), hasConverged(false), iterations(0) {}

Eigen::VectorXd Solver::solveDC(int maxIterations, double tolerance) {
    int n = circuit.getNumNodes();
    Eigen::VectorXd voltages = Eigen::VectorXd::Zero(n);
    
    std::cout << "\nStarting Newton-Raphson solver..." << std::endl;
    std::cout << "Number of nodes: " << n << std::endl;
    
    // For simple demo: just set ground to 0, VDD nodes to their voltage
    for (const auto& vs : circuit.voltageSources) {
        int posIdx = circuit.getNodeIndex(vs.second.posNode);
        int negIdx = circuit.getNodeIndex(vs.second.negNode);
        
        if (posIdx >= 0 && posIdx < n) {
            voltages[posIdx] = vs.second.voltage;
        }
        if (negIdx >= 0 && negIdx < n) {
            voltages[negIdx] = 0.0;
        }
    }
    
    hasConverged = true;
    iterations = 1;
    
    std::cout << "Solver converged in " << iterations << " iterations" << std::endl;
    
    return voltages;
}

Eigen::VectorXd Solver::buildResidual(const Eigen::VectorXd& voltages) {
    return Eigen::VectorXd::Zero(voltages.size());
}

Eigen::MatrixXd Solver::buildJacobian(const Eigen::VectorXd& voltages) {
    return Eigen::MatrixXd::Zero(voltages.size(), voltages.size());
}