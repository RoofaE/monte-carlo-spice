#pragma once
#include <vector>
#include "circuit.h"

class MonteCarloEngine {
public:
    struct Result {
        std::vector<double> outputVoltages;
        bool passed;
    };
    
    MonteCarloEngine(int numIterations, double variationPercent);
    
    std::vector<Result> run(const Circuit& circuit);
    
private:
    int numIterations;
    double variationPercent;
};