#include "circuit.h"

Circuit::Circuit() {
    // Ground node is always node 0
    addNode("0");
}

void Circuit::addNode(const std::string& name) {
    if (nodeIndexMap.find(name) == nodeIndexMap.end()) {
        nodeIndexMap[name] = nodeNames.size();
        nodeNames.push_back(name);
    }
}

void Circuit::addVoltageSource(const std::string& name, const std::string& posNode, 
                              const std::string& negNode, double voltage) {
    addNode(posNode);
    addNode(negNode);
    // Store voltage source
    voltageSources[name] = {posNode, negNode, voltage};
}

void Circuit::addMOSFET(const std::string& name, const std::string& drain, 
                       const std::string& gate, const std::string& source,
                       const std::string& bulk, const std::string& modelName,
                       double width, double length) {
    addNode(drain);
    addNode(gate);
    addNode(source);
    addNode(bulk);
    // Store MOSFET
}

int Circuit::getNodeIndex(const std::string& name) const {
    auto it = nodeIndexMap.find(name);
    if (it != nodeIndexMap.end()) {
        return it->second;
    }
    return -1;
}