#include "Game.h"
#include <iostream>

int main() {
    Game game;
    std::vector<GameEntity*> entities = game.initGame(3, 2, 10, 10);

    // Display the initial entities
    std::cout << "Initial entities:" << std::endl;
    for (GameEntity* entity : entities) {
        std::cout << "Position: (" << std::get<0>(entity->getPos()) << ", " << std::get<1>(entity->getPos()) << ") Type: " << entity->getType() << std::endl;
    }

    game.gameLoop(5, 2.5);

    // Display the updated entities after the game loop
    std::cout << "\nUpdated entities:" << std::endl;
    for (GameEntity* entity : game.get_entities()) {
        std::cout << "Position: (" << std::get<0>(entity->getPos()) << ", " << std::get<1>(entity->getPos()) << ") Type: " << entity->getType() << std::endl;
    }

    // Clean up the dynamically allocated entities
    for (GameEntity* entity : entities) {
        delete entity;
    }

    return 0;
}