#ifndef MINE_H
#define MINE_H

#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity {
public:
    Mine(int x, int y) : GameEntity(x, y, 'M') {}

Explosion explode() {
    setType('X');  // Change the Mine type to 'X' after exploding
    int x,y;
    std::tie(x, y) = getPos();
    return Explosion(x, y);
}
};

#endif // MINE_H