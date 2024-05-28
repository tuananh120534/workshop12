#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    // Create a Ship and a Mine
    Ship myShip(3, 3);
    Mine myMine(5, 5);

    // Move the Ship
    myShip.move(2, 2);

    // Explode the Mine
    Explosion explosion = myMine.explode();

    // Apply the Explosion to the Ship
    explosion.apply(myShip);

    // Print Ship and Mine details
    std::cout << "Ship Position: (" << std::get<0>(myShip.getPos()) << ", " << std::get<1>(myShip.getPos()) << ") Type: " << myShip.getType() << std::endl;
    std::cout << "Mine Position: (" << std::get<0>(myMine.getPos()) << ", " << std::get<1>(myMine.getPos()) << ") Type: " << myMine.getType() << std::endl;

    return 0;
}