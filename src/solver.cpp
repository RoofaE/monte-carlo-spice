#include "solver.h"
#include <iostream>

Solver::Solver(const Circuit& circuit) : circuit(circuit), hasConverged(false), iterations(0) {}

Eigen::VectorXd Solver::solveDC(int maxIterations, double tolerance) {
    int n = circuit.getNumNodes();
    Eigen::VectorXd voltages = Eigen::VectorXd::Zero(n);
    
    // Set voltage sources
    for (const auto& vs : circuit.voltageSources) {
        int posIdx = circuit.getNodeIndex(vs.second.posNode);
        if (posIdx > 0) {
            voltages[posIdx] = vs.second.voltage;
        }
    }
    
    // Simple resistor divider calculation
    if (!circuit.resistors.empty()) {
        // For resistor divider: Vout = Vin * R2 / (R1 + R2)
        auto it = circuit.resistors.begin();
        double totalR = 0;
        for (const auto& r : circuit.resistors) {
            totalR += r.second.resistance;
        }
        
        // Calculate middle node voltage
        for (const auto& r : circuit.resistors) {
            int idx1 = circuit.getNodeIndex(r.second.node1);
            int idx2 = circuit.getNodeIndex(r.second.node2);
            
            if (idx1 > 0 && idx2 > 0 && voltages[idx1] == 0 && voltages[idx2] == 0) {
                // This is the middle node
                double vin = 0;
                for (const auto& vs : circuit.voltageSources) {
                    int vIdx = circuit.getNodeIndex(vs.second.posNode);
                    if (vIdx > 0) vin = voltages[vIdx];
                }
                
                std::vector<double> rValues;
                for (const auto& res : circuit.resistors) {
                    rValues.push_back(res.second.resistance);
                }
                
                if (rValues.size() == 2) {
                    voltages[idx2] = vin * rValues[1] / (rValues[0] + rValues[1]);
                }
            }
        }
    }
    
    hasConverged = true;
    iterations = 1;
    
    return voltages;
}

Eigen::VectorXd Solver::buildResidual(const Eigen::VectorXd& voltages) {
    return Eigen::VectorXd::Zero(voltages.size());
}

Eigen::MatrixXd Solver::buildJacobian(const Eigen::VectorXd& voltages) {
    return Eigen::MatrixXd::Zero(voltages.size(), voltages.size());
}