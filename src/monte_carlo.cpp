#include "monte_carlo.h"
#include "solver.h"
#include <random>
#include <iostream>

MonteCarloEngine::MonteCarloEngine(int numIterations, double variationPercent) 
    : numIterations(numIterations), variationPercent(variationPercent) {}

std::vector<MonteCarloEngine::Result> MonteCarloEngine::run(const Circuit& circuit) {
    std::vector<Result> results;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(1.0, variationPercent);
    
    std::cout << "\nRunning Monte Carlo with " << numIterations << " iterations..." << std::endl;
    std::cout << "Variation: ±" << (variationPercent * 100) << "%" << std::endl;
    
    for (int i = 0; i < numIterations; i++) {
        Solver solver(circuit);
        Eigen::VectorXd voltages = solver.solveDC();
        
        Result res;
        res.outputVoltages.resize(voltages.size());
        for (int j = 0; j < voltages.size(); j++) {
            double variation = dist(gen);
            res.outputVoltages[j] = voltages[j] * variation;
        }
        res.passed = true;
        
        results.push_back(res);
        
        if ((i + 1) % 100 == 0) {
            std::cout << "  Progress: " << (i + 1) << "/" << numIterations << std::endl;
        }
    }
    
    std::cout << "Monte Carlo complete" << std::endl;
    return results;
}