#ifndef SOLVER_H
#define SOLVER_H
#include "Card.h"
#include "World.h"
#include <vector>
struct Set {
    Card card1;
    Card card2;
    Card card3;
};

class Solver {
private:
    static bool isSet(const Card &card1, const Card &card2, const Card &card3);

public:
    static std::vector<Set> solve(const std::vector<Card> &cards);
};
#endif // SOLVER_H
