#ifndef CARD_H
#define CARD_H
enum Color {
    RED,
    GREEN,
    PURPLE
};

enum Shape {
    OVAL,
    SQUIGGLE,
    DIAMOND
};

enum Shading {
    SOLID,
    STRIPED,
    OPEN
};

struct Card {
    Color color;
    Shape shape;
    Shading shading;
    int number;
    int index;
};

#endif // CARD_H