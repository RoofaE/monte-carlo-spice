#pragma once
#include <string>
#include <vector>
#include <map>

class Parser {

public:
    struct Component {
        std::string type;
        std::string name;
        std::vector<std::string> nodes;
        std::map<std::string, double> params;
    };

    Parser(const std::string& filename);
    bool parse();

    const std::vector<Component>& getComponents() const {return components;}
    const std::vector<std::string>& getNodes() const {return nodes;}

private:
    std::string filename;
    std::vector<Component> components;
    std::vector<std::string> nodes;

    void parseLine(const std::string& line);
    void extractNodes();
};