#include <iostream>
#include <climits>
#include <unistd.h> // for using sleep()
#include "Deck.h"
#include "Cardset.h"
#include "Player.h"
using namespace std;

string suit_name[] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
int player::surface = 0;

ostream & operator << (ostream & out, player plyr) {
    for (int i = 0; i < plyr.quantity; ++i) {
        switch(plyr.hands[i].number) {
            case 1: out << "ACE-" << suit_name[plyr.hands[i].suit];
                     break;
            case 11: out << "JACK-" << suit_name[plyr.hands[i].suit];
                     break;
            case 12: out << "QUEEN-" << suit_name[plyr.hands[i].suit];
                     break;
            case 13: out << "KING-" << suit_name[plyr.hands[i].suit];
                     break;
            default: out << plyr.hands[i].number << "-" << suit_name[plyr.hands[i].suit];
                     break; 
        }
        cout << " ";
    }
    return out;
}

void gameProcess(void);
void printValue(int);
void printCard(deck);

int main(int argc, char *argv[]) {
    char again;
    gameProcess();
    cout << "\nWant to play again? (Y/N): ";
    cin.ignore(INT_MAX, '\n');
    cin >> again;
    while (again == 'Y' || again == 'y') {
        cout << "----------------------------------------\n";
        gameProcess();
        cout << "\nWant to play again? (Y/N): ";
        cin .ignore(INT_MAX, '\n');
        cin >> again;
    }
    return 0;
}

void gameProcess(void) {
    // Game start
    cardset cardset1;
    player customer, computer;
    bool hitStay;

    // Draw two cards to customer and computer
    customer.drawCard(2, cardset1);
    computer.drawCard(2, cardset1);

    cout << "Your current value is ";
    printValue(customer.calSum().getSum());
    cout << "with the hand: " << customer << "\n" << endl;

    // Ask customer to hit or stay
    cout << "Hit or stay? (Hit = 1, Stay = 0) : ";
    cin >> hitStay;

    while (hitStay) {
        customer.drawCard(cardset1);
        cout << "You draw ";
        printCard(cardset1.getCardSet()[customer.getSurface() - 1]);
        cout << "Your current value is ";
        printValue(customer.calSum().getSum());
        cout << "with the hand: " << customer << "\n" << endl;
        cout << "Hit or stay? (Hit = 1, Stay = 0) : ";
        cin >> hitStay;
    }

    // Dealer's turn
    cout << endl;
    sleep(1.5);
    cout << "Dealer current value is ";
    printValue(computer.calSum().getSum());
    cout << "with the hand: " << computer << "\n" << endl;
    sleep(1.5);
    while(computer.calSum().getSum() < 17) {
        computer.drawCard(cardset1);
        cout << "Dealer draws ";
        printCard(cardset1.getCardSet()[computer.getSurface() - 1]);
        cout << "Dealer current value is ";
        printValue(computer.calSum().getSum());
        cout << "with the hand: " << computer << "\n" << endl;
        sleep(1.5);
    }

    // Judge the result
    sleep(1);
    if (customer.getSum() > 21) {
        cout << "*** Dealer wins ***" << endl;
    } else if (computer.getSum() > 21) {
        cout << "*** You beat the dealer ***" << endl;
    } else if (customer.getSum() == computer.getSum()) {
        cout << "*** You tied with dealer, nobody wins ***" << endl;
    } else if (customer.getSum() > computer.getSum()) {
        cout << "*** You beat the dealer ***" << endl;
    } else {
        cout << "*** Dealer wins ***" << endl;
    }
    customer.setSurface(0);
}

void printValue(int value) {
    if (value == 21) {
        cout << "Blackjack! (21)" << endl;
    } else if (value > 21) {
        cout << "Bust! (>21)" << endl;
    } else {
        cout << value << endl;
    }
}

void printCard(deck card) {
    switch(card.number) {
            case 1: cout << "ACE-" << suit_name[card.suit];
                     break;
            case 11: cout << "JACK-" << suit_name[card.suit];
                     break;
            case 12: cout << "QUEEN-" << suit_name[card.suit];
                     break;
            case 13: cout << "KING-" << suit_name[card.suit];
                     break;
            default: cout << card.number << "-" << suit_name[card.suit];
                     break; 
    }
    cout << "\n" << endl;
}