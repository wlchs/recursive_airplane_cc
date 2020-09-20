#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>

int main() {
    auto connections = std::vector<std::pair<std::string, std::string>>{
        {"BUD","CDG"},
        {"CDG","LGA"},
        {"BUD","LGA"},
        {"LGA","XYZ"},
        {"LGA","BUD"},
        {"CDG","CRY"}
    };

    auto distances = std::map<std::string, uint>{};
    auto nodes = std::queue<std::pair<std::string, uint8_t>>{};
    nodes.push({"BUD", 0});
    uint maxDistance = 0;

    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();

        if (distances.find(node.first) != distances.end()) continue;
        if (node.second > maxDistance) maxDistance = node.second;
        distances[node.first] = node.second;

        for (auto &&next : connections)
        {
            if (next.first != node.first) continue;
            nodes.push({next.second, node.second + 1});
        }
        
    }

    for (auto &&airport : distances)
    {
        std::cout << airport.first << ": " << airport.second << std::endl;
    }

    std::cout << "Max distance: " << maxDistance << std::endl;
    
    return 0;
}