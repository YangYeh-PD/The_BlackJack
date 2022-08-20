#include <iostream>
using namespace std;

#ifndef PLAYER
#define PLAYER
class player {
    friend ostream & operator << (ostream & out, player plyr);
    public:
        player(int quan = 0, deck *hand = NULL, int sum = 0): quantity(quan), hands(hand), summation(sum) {};
        ~player() {};
        void drawCard(int number, cardset & cardset_);
        void drawCard(cardset & cardset_);
        void setSurface(int num);
        static int getSurface(void);
        player & calSum(void);
        int getSum(void);
    private:
        static int surface;
        int quantity;
        int summation;
        deck *hands;
};
#endif