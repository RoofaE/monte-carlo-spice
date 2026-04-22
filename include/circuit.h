#pragma once
#include <vector>
#include <map>
#include <string>
#include <Eigen/Dense>

class Circuit {
public:
    Circuit();
    
    void addNode(const std::string& name);
    void addVoltageSource(const std::string& name, const std::string& posNode, 
                         const std::string& negNode, double voltage);
    void addResistor(const std::string& name, const std::string& node1,
                    const std::string& node2, double resistance);
    void addMOSFET(const std::string& name, const std::string& drain, 
                   const std::string& gate, const std::string& source,
                   const std::string& bulk, const std::string& modelName,
                   double width, double length);
    
    int getNodeIndex(const std::string& name) const;
    int getNumNodes() const { return nodeNames.size(); }
    
    const std::vector<std::string>& getNodeNames() const { return nodeNames; }
    
    struct VSource {
        std::string posNode;
        std::string negNode;
        double voltage;
    };
    
    struct Resistor {
        std::string node1;
        std::string node2;
        double resistance;
    };
    
    std::map<std::string, VSource> voltageSources;
    std::map<std::string, Resistor> resistors;

private:
    std::vector<std::string> nodeNames;
    std::map<std::string, int> nodeIndexMap;
};