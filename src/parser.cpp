#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Parser::Parser(const std::string& filename) : filename(filename) {}

bool Parser::parse() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    std::string line, word;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '*' || line[0] == '.') continue;
        
        std::istringstream iss(line);
        Component comp;
        iss >> comp.name;
        comp.type = comp.name[0];
        
        while (iss >> word) {
            if (isdigit(word[0]) || word[0] == '-') {
                comp.params["value"] = std::stod(word);
            } else if (word != "DC") {
                comp.nodes.push_back(word);
            }
        }
        
        components.push_back(comp);
    }
    
    extractNodes();
    return true;
}

void Parser::parseLine(const std::string& line) {
}

void Parser::extractNodes() {
    for (const auto& comp : components) {
        for (const auto& node : comp.nodes) {
            bool found = false;
            for (const auto& n : nodes) {
                if (n == node) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                nodes.push_back(node);
            }
        }
    }
}