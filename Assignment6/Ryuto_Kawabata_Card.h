#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
    // Comment 1: Private data members to store the face and suit of the card as integer indices
    int face;
    int suit;

public:
    // Comment 2: Constructor that takes face and suit indices and initializes the card
    Card(int faceValue, int suitValue);

    // Comment 3: Static arrays that store the string representations of faces and suits
    static const string faces[13];
    static const string suits[4];

    // Comment 4: toString method that returns a string representation of the card
    string toString() const;
};

#endif // CARD_H