#include "World.h"
#include "Card.h"
#include <iostream>
#include <cstdlib> // For rand() REMOVE LATER
World::World(std::vector<Card> cards) {
    this->cards = cards;
    // Posibly order them so that the card.index is also index in the vector
}
World::World() {
    // Default constructor implementation
}
World::~World() {
    // Destructor implementation
}
World World::randomWorld() {
    // TESTFUNCTION
    std::vector<Card> cards;
    for (int i = 0; i < 9; i++) {
        Card card = randomCard();
        card.index = i;
        cards.push_back(card);
    }
    return World(cards);
}
std::vector<Card> World::getCards() {
    return cards;
}

Card World::randomCard() {
    // TESTFUNCTION
    Card card;
    card.color = static_cast<Color>(rand() % 3);
    card.shape = static_cast<Shape>(rand() % 3);
    card.shading = static_cast<Shading>(rand() % 3);
    card.number = rand() % 3;
    return card;
}

void World::printWorld() {
    for (const auto &card : cards) {
        std::cout << card.color << " " << card.shape << " " << card.shading << " " << card.number << " " << card.index << "\n";
    }
}
