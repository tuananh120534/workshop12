#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <tuple>

class Utils {
public:
    std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        static bool seeded = false; // Only seed the random number generator once
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
    int x = std::rand() % gridWidth;
    int y = std::rand() % gridHeight;
    return std::make_tuple(x, y);
}

double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    int x1, y1, x2, y2;
    std::tie(x1, y1) = pos1;
    std::tie(x2, y2) = pos2;
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
};

#endif // UTILS_H