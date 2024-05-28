#include <iostream>
#include "Utils.h"

int main() {
    // Generate random positions
    Utils a,b;
    std::tuple<int, int> pos1 = a.generateRandomPos(10, 10);
    std::tuple<int, int> pos2 = b.generateRandomPos(10, 10);

    // Calculate distance between positions
    double distance = a.calculateDistance(pos1, pos2);

    // Print the generated positions and distance
    std::cout << "Position 1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")\n";
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")\n";
    std::cout << "Distance: " << distance << std::endl;

    return 0;
}