#ifndef GAME_H
#define GAME_H

#include "GameEntity.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"
#include <vector>

class Game {
public:
   

std::vector<GameEntity*> get_entities() const {
    return entities;
}

void set_entities(const std::vector<GameEntity*>& entities) {
    this->entities = entities;
}

std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
    entities.clear(); // Clear existing entities

    // Create Ship and Mine objects with random positions and add them to the entities vector
    for (int i = 0; i < numShips; ++i) {
        Utils a;
        std::tuple<int, int> pos = a.generateRandomPos(gridWidth, gridHeight);
        entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
    }

    for (int i = 0; i < numMines; ++i) {
        Utils a;
        std::tuple<int, int> pos = a.generateRandomPos(gridWidth, gridHeight);
        entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
    }

    return entities;
}

void gameLoop(int maxIterations, double mineDistanceThreshold) {
    for (int iter = 1; iter <= maxIterations; ++iter) {
        // Move all Ship objects
        for (GameEntity* entity : entities) {
            if (entity->getType() == 'S') {
                // Cast to Ship and move
                Ship* ship = dynamic_cast<Ship*>(entity);
                if (ship) {
                    ship->move(1, 0);
                }
            }
        }

        // Check for Mine explosions
        for (GameEntity* shipEntity : entities) {
            if (shipEntity->getType() == 'S') {
                Ship* ship = dynamic_cast<Ship*>(shipEntity);
                for (GameEntity* mineEntity : entities) {
                    if (mineEntity->getType() == 'M') {
                        Mine* mine = dynamic_cast<Mine*>(mineEntity);
                        Utils a;
                        double distance = a.calculateDistance(shipEntity->getPos(), mineEntity->getPos());
                        if (distance <= mineDistanceThreshold) {
                            Explosion explosion = mine->explode();
                            explosion.apply(*ship);
                        }
                    }
                }
            }
        }
    }
}


private:
    std::vector<GameEntity*> entities;
};

#endif // GAME_H