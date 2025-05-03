#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>
#include "Ryuto_Kawabata_Card.h"

using namespace std;

class DeckOfCards {
private:
    // Comment 7] A vector to store the 52 Cards objects representing a complete deck
    vector<Card> deck;

    // Comment 8: An integer to keep track of the next card to be dealt
    int currentCard;

public:
    DeckOfCards();

    void shuffle();

    Card dealCard();

    bool moreCards() const;
};

#endif // DECK_OF_CARDS_H