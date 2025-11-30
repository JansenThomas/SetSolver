#include "Solver.h"
#include <iostream>

std::vector<Set> Solver::solve(const std::vector<Card> &cards) {
    std::cout << "Solving for " << cards.size() << " cards." << std::endl;
    std::vector<Set> solutions;
    for (size_t i = 0; i < cards.size(); ++i) {
        for (size_t j = i + 1; j < cards.size(); ++j) {
            for (size_t k = j + 1; k < cards.size(); ++k) {
                if (isSet(cards[i], cards[j], cards[k])) {
                    solutions.push_back(Set{cards[i], cards[j], cards[k]});
                }
            }
        }
    }
    return solutions;
}
bool Solver::isSet(const Card &card1, const Card &card2, const Card &card3) {
    if (card1.index == card2.index || card1.index == card3.index || card2.index == card3.index) {
        return false;
    }
    if ((card1.number == card2.number && card2.number == card3.number) ||
        (card1.number != card2.number && card2.number != card3.number && card1.number != card3.number)) {
    } else {
        return false;
    }
    if ((card1.shape == card2.shape && card2.shape == card3.shape) ||
        (card1.shape != card2.shape && card2.shape != card3.shape && card1.shape != card3.shape)) {
    } else {
        return false;
    }
    if ((card1.shading == card2.shading && card2.shading == card3.shading) ||
        (card1.shading != card2.shading && card2.shading != card3.shading && card1.shading != card3.shading)) {
    } else {
        return false;
    }
    if ((card1.color == card2.color && card2.color == card3.color) ||
        (card1.color != card2.color && card2.color != card3.color && card1.color != card3.color)) {
    } else {
        return false;
    }
    return true;
}