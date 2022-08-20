#include "Deck.h"
#include "Cardset.h"
#include "Player.h"

void player::drawCard(int number, cardset & cardset_) {
    hands = new deck[number];
    for (int i = 0; i < number; i++) {
        hands[i] = cardset_.card[surface + i];
    }
    quantity += number;
    surface += number;
}
void player::drawCard(cardset & cardset_) {
    deck *temp = new deck[quantity + 1];
    for (int i = 0; i < quantity; i++) {
        temp[i] = hands[i];
    }
    delete [] hands;
    hands = temp;
    hands[quantity] = cardset_.card[surface];
    ++quantity;
    ++surface;
}

void player::setSurface(int num) {
    surface = num;
}
int player::getSurface(void) {
    return surface;
}

player & player::calSum(void) {
    bool condition = true;
    bool convert = false;
    top: ;
    summation = 0;
    for (int i = 0; i < quantity; ++i) {
        if ((hands[i].number == 1) && condition && !convert) {
            summation += 11;
            convert = true;
        } else if (hands[i].number == 11 || hands[i].number == 12 || hands[i].number == 13) {
            summation += 10;
        } else {
            summation += hands[i].number;
        }
    }
    if (summation > 21 && condition) {
        condition = false;
        goto top;
    }
    return *this;
}
int player::getSum(void) {
    return summation;
}
