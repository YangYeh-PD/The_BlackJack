#include <ctime>
#include <bits/stdc++.h>    // for using shuffle()
#include "Deck.h"
#include "Cardset.h"
using namespace std;

cardset::cardset(void) {
    // Initialize the card
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; j++) {
            card[i * 13 + j].suit = i;
            card[i * 13 + j].number = j + 1;
        }
    }
    // shuffle the deck
    unsigned int seed = time(NULL);
    shuffle(card, card + 52, default_random_engine(seed));
}
cardset::~cardset() {};
deck *cardset::getCardSet(void) {
    return card;
}
