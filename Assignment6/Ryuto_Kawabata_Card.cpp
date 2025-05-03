#include "Ryuto_Kawabata_Card.h"

using namespace std;

// Comment 5: Initialize the static array of face names
const std::string Card::faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", 
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Comment 6: Initialize the static array of suit names
const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int faceValue, int suitValue) : face(faceValue), suit(suitValue) {
    if (faceValue < 0 || faceValue > 12 || suitValue < 0 || suitValue > 3) {
        face = 0;
        suit = 0;
    }
}

string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}