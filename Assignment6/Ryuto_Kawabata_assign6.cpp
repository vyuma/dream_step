#include <iostream>
#include "Ryuto_Kawabata_DeckOfCards.h"

using namespace std;

int main() {
    DeckOfCards myDeck;

    myDeck.shuffle(); // Shuffle the deck before dealing cards

    cout << "Dealing all 52 cards from the shuffled deck:" << endl;

    int cardCount = 0;
    while (myDeck.moreCards()) {
        Card dealtCard = myDeck.dealCard();
        cout << dealtCard.toString() << endl;
        // Keep track of how many cards we've dealt
        ++cardCount;
    }

    cout << "\nDealt " << cardCount << " cards from the deck." << endl;

    return 0;
}