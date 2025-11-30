#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Card.h"
class World {
private:
    Card randomCard();
    std::vector<Card> cards;

public:
    World(std::vector<Card> cards);
    World();
    ~World();
    std::vector<Card> getCards();
    World randomWorld();
    void printWorld();
};
#endif