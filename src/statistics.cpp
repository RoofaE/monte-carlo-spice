#include "statistics.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double Statistics::mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double val : data) {
        sum += val;
    }
    return sum / data.size();
}

double Statistics::stddev(const std::vector<double>& data) {
    double avg = mean(data);
    double sum = 0.0;
    for (double val : data) {
        sum += (val - avg) * (val - avg);
    }
    return std::sqrt(sum / data.size());
}

double Statistics::min(const std::vector<double>& data) {
    return *std::min_element(data.begin(), data.end());
}

double Statistics::max(const std::vector<double>& data) {
    return *std::max_element(data.begin(), data.end());
}

void Statistics::printSummary(const std::vector<double>& data, const std::string& name) {
    std::cout << "\n=== " << name << " Statistics ===" << std::endl;
    std::cout << "Mean:   " << mean(data) << std::endl;
    std::cout << "StdDev: " << stddev(data) << std::endl;
    std::cout << "Min:    " << min(data) << std::endl;
    std::cout << "Max:    " << max(data) << std::endl;
}