#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"

class Ship : public GameEntity {
public:
    Ship(int x, int y) : GameEntity(x, y, 'S') {}

void move(int dx, int dy) {
    // Update the ship's position
    int currentX, currentY;
    std::tie(currentX, currentY) = getPos();
    setPos(currentX + dx, currentY + dy);
}
};

#endif // SHIP_H