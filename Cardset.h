#ifndef CARDSET
#define CARDSET
class cardset {
    friend class player;
    public:
        cardset(void);
        ~cardset();
        deck *getCardSet(void);
    private:
        deck card[52];
};
#endif