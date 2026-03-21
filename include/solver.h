#pragma once
#include <Eigen/Dense>
#include "circuit.h"

class Solver {
public:
    Solver(const Circuit& circuit);
    
    // Solve DC operating point using Newton-Raphson
    Eigen::VectorXd solveDC(int maxIterations = 50, double tolerance = 1e-6);
    
    bool converged() const { return hasConverged; }
    int getIterations() const { return iterations; }

private:
    const Circuit& circuit;
    bool hasConverged;
    int iterations;
    
    // System equations F(x) = 0
    Eigen::VectorXd buildResidual(const Eigen::VectorXd& voltages);
    
    // Jacobian matrix dF/dx
    Eigen::MatrixXd buildJacobian(const Eigen::VectorXd& voltages);
};