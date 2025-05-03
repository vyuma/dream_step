
#include "Ryuto_Kawabata_DeckOfCards.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

DeckOfCards::DeckOfCards() : currentCard(0) {
    // Comment 9: Initialize the deck with 52 cards
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit));
        }
    }
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

void DeckOfCards::shuffle() {
    // Comment 10: Shuffle algorighm - for each card in the deck, swap it with another randomly selected card
    for (size_t i = 0; i < deck.size(); ++i) {
        int j = rand() % 52;
        swap(deck[i], deck[j]); // Swap the cards
    }
    currentCard = 0; // Reset the current card index after shuffling
}

Card DeckOfCards::dealCard() {
    if (!moreCards()) {
        return deck[deck.size() - 1]; // Return the last card if no more cards are available
    }

    return deck[currentCard++];
}

bool DeckOfCards::moreCards() const {
    return currentCard < deck.size(); // Check if there are more cards to deal
}