#include "circuit.h"

Circuit::Circuit() {
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
    voltageSources[name] = {posNode, negNode, voltage};
}

void Circuit::addResistor(const std::string& name, const std::string& node1,
                         const std::string& node2, double resistance) {
    addNode(node1);
    addNode(node2);
    resistors[name] = {node1, node2, resistance};
}

void Circuit::addMOSFET(const std::string& name, const std::string& drain, 
                       const std::string& gate, const std::string& source,
                       const std::string& bulk, const std::string& modelName,
                       double width, double length) {
    addNode(drain);
    addNode(gate);
    addNode(source);
    addNode(bulk);
}

int Circuit::getNodeIndex(const std::string& name) const {
    auto it = nodeIndexMap.find(name);
    if (it != nodeIndexMap.end()) {
        return it->second;
    }
    return -1;
}