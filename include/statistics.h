#pragma once
#include <vector>

class Statistics {
public:
    static double mean(const std::vector<double>& data);
    static double stddev(const std::vector<double>& data);
    static double min(const std::vector<double>& data);
    static double max(const std::vector<double>& data);
    
    static void printSummary(const std::vector<double>& data, const std::string& name);
};