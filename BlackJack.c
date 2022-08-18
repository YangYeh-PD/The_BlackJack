#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
	int number;
	const char *suit;   // Which can store a string
} deck;

void player_result(int, int, deck*);
void computer_result(int, int, deck*);
int player_sum(deck*);
int computer_sum(deck*);
void judge(int, int);

const int Number[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const char *Suit[4] = {"CLUB", "DIAMONDS", "HEARTS", "SPADES"};
int cover_card, ply_hand, ply_sum, com_hand, com_sum, continuous;
char restart = 'Y';

int arr[52];
deck card[52];

int main(int argc, char *argv[]) {
    top: ;
    cover_card = 0;
    ply_hand = 0;
    ply_sum = 0;
    com_hand = 0;
    com_sum = 0;
	// Establish a deck
	for (int i = 0; i < 52; i++) {
		card[i].number = Number[i % 13];
		card[i].suit = Suit[i / 13];
	}

    // Generate a random numbers of array
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        arr[i] = rand();
    }

    // Sorting the cards corresond to the random numbers of array
    // By Selection Sort
    int buffer;
    deck buffer_card;

    for (int i = 0; i < 52; i++) {
        for (int j = i; j < 52; j++) {
            if (arr[j] < arr[i]) {
                // Swap int arr
                buffer = arr[i];
                arr[i] = arr[j];
                arr[j] = buffer;
                // Swap deck card
                buffer_card = card[i];
                card[i] = card[j];
                card[j] = buffer_card;
            }
        }
    }

    deck *player, *computer;

    // Player Turn
    player = malloc(sizeof(deck));

    // Draw two cards to player
    for (ply_hand = 0; ply_hand < 2; ply_hand++) {
        player = realloc(player, sizeof(deck) * (ply_hand + 1));
        player[ply_hand] = card[cover_card];
        cover_card++;
    }
    ply_sum = player_sum(player);
    player_result(ply_hand, ply_sum, player);

    // Draw two cards to computer
    computer = malloc(sizeof(deck));

    for (com_hand = 0; com_hand < 2; com_hand++) {
        computer = realloc(computer, sizeof(deck) * (com_hand + 1));
        computer[com_hand] = card[cover_card];
        cover_card++;
    }
    com_sum = computer_sum(computer);
    

    // Ask whether user wants to hit or stay
    printf("\nHit or stay? (Hit = 1, Stay = 0) : ");
    scanf("%d", &continuous);

    while (continuous) {
        player = realloc(player, sizeof(deck) * (ply_hand + 1));
        player[ply_hand] = card[cover_card];

        printf("You draw ");
        if (player[ply_hand].number > 10 || player[ply_hand].number == 1) {
            switch (player[ply_hand].number) {
                case 1:     printf("%s-%s\n", "ACE", player[ply_hand].suit);
                            break;
                case 11:    printf("%s-%s\n", "JACK", player[ply_hand].suit);
                            break;
                case 12:    printf("%s-%s\n", "QUEEN", player[ply_hand].suit);
                            break;
                case 13:    printf("%s-%s\n", "KING", player[ply_hand].suit);
                            break;
                default:    break;
            }
        } else {
            printf("%d-%s\n", player[ply_hand].number, player[ply_hand].suit);
        }
    
        ply_hand++;
        cover_card++;
        ply_sum = player_sum(player);
        player_result(ply_hand, ply_sum, player);
        printf("\nHit or stay? (Hit = 1, Stay = 0) : ");
        scanf("%d", &continuous);
    }

    printf("\n");

    // Computer Turn
    // Computer determine whether it wants to hit or stay
    computer_result(com_hand, com_sum, computer);
    printf("\n");
    (com_sum < 17) ? (continuous = true) : (continuous = false);

    while (continuous) {
        computer = realloc(computer, sizeof(deck) * (com_hand + 1));
        computer[com_hand] = card[cover_card];

        printf("Dealer draw ");
        if (computer[com_hand].number > 10 || computer[com_hand].number == 1) {
            switch (computer[com_hand].number) {
                case 1:     printf("%s-%s\n", "ACE", computer[com_hand].suit);
                            break;
                case 11:    printf("%s-%s\n", "JACK", computer[com_hand].suit);
                            break;
                case 12:    printf("%s-%s\n", "QUEEN", computer[com_hand].suit);
                            break;
                case 13:    printf("%s-%s\n", "KING", computer[com_hand].suit);
                            break;
                default:    break;
            }
        } else {
            printf("%d-%s\n", computer[com_hand].number, computer[com_hand].suit);
        }
        printf("\n");

        com_hand++;
        cover_card++;
        com_sum = computer_sum(computer);
        (com_sum < 17) ? (continuous = true) : (continuous = false);
        computer_result(com_hand, com_sum, computer);
        printf("\n");
    }

    judge(ply_sum, com_sum);

    printf("\n");
    printf("Want to play again? (Y/N): ");
    while (getchar() != '\n');
    scanf("%c", &restart);
    
    if (restart == 'Y' || restart == 'y') {
        printf("\n");
        printf("-------------------------------------------");
        printf("\n");
        goto top;
    }
    return 0;
}

void player_result(int ply_hand, int ply_sum, deck *player) {
    // Print out player's sum
    if (ply_sum == 21) {
		printf("Your current value is Blackjack! (21)\n");
    } else if (ply_sum > 21) {
        printf("Your current value is Bust! (>21)\n");
    } else {
        printf("Your current value is %d\n", ply_sum);
    }
    // Print out player's hands
    printf("with the hand: ");
    for (int i = 0; i < ply_hand; i++) {
        if (player[i].number > 10 || player[i].number == 1) {
            switch (player[i].number) {
                case 1:     printf("%s-%s ", "ACE", player[i].suit);
                            break;
                case 11:    printf("%s-%s ", "JACK", player[i].suit);
                            break;
                case 12:    printf("%s-%s ", "QUEEN", player[i].suit);
                            break;
                case 13:    printf("%s-%s ", "KING", player[i].suit);
                            break;
                default:    break;
            }
        } else {
            printf("%d-%s ", player[i].number, player[i].suit);
        }
    }
    printf("\n");
}
void computer_result(int com_hand, int com_sum, deck *computer) {
    // Print out computer's sum
    if (com_sum == 21) {
		printf("Dealer's current value is Blackjack! (21)\n");
    } else if (com_sum > 21) {
        printf("Dealer's current value is Bust! (>21)\n");
    } else {
        printf("Dealer's current value is %d\n", com_sum);
    }
    // Print out computer's hands
    printf("with the hand: ");
    for (int i = 0; i < com_hand; i++) {
        if (computer[i].number > 10 || computer[i].number == 1) {
            switch (computer[i].number) {
                case 1:     printf("%s-%s ", "ACE", computer[i].suit);
                            break;
                case 11:    printf("%s-%s ", "JACK", computer[i].suit);
                            break;
                case 12:    printf("%s-%s ", "QUEEN", computer[i].suit);
                            break;
                case 13:    printf("%s-%s ", "KING", computer[i].suit);
                            break;
                default:    break;
            }
        } else {
            printf("%d-%s ", computer[i].number, computer[i].suit);
        }
    }
    printf("\n");
}

int player_sum(deck *player) {
    bool repeat_ = false;
    repeat: ;
        int sum = 0;
        for (int i = 0; i < ply_hand; i++) {
            if (player[i].number > 10 || player[i].number == 1) {
                if (player[i].number == 1) {
                    if (repeat_) {
                        sum += 1;
                    } else {
                        sum += 11;
                    }
                } else {
                    sum += 10;
                }
            } else {
                sum += player[i].number;
            }
        }
    
    if (sum > 21 && !repeat_) {
        repeat_ = true;
        goto repeat;
    }
    return sum;
}
int computer_sum(deck *computer) {
    bool repeat_ = false;
    repeat: ;
        int sum = 0;
        for (int i = 0; i < com_hand; i++) {
            if (computer[i].number > 10 || computer[i].number == 1) {
                if (computer[i].number == 1) {
                    if (repeat_) {
                        sum += 1;
                    } else {
                        sum += 11;
                    }
                } else {
                    sum += 10;
                }
            } else {
                sum += computer[i].number;
            }
        }

    if (sum > 21 && !repeat_) {
        repeat_ = true;
        goto repeat;
    }
    return sum;
}

void judge(int ply_sum, int com_sum) {
    if (ply_sum > 21) {
        printf("*** Dealer wins ***\n");
    } else if (ply_sum <= 21 && com_sum > 21) {
        printf("*** You beat the dealer! ***\n");
    } else if (ply_sum <= 21 && com_sum <= 21) {
        if ((21 - ply_sum) < (21 - com_sum)) {
            printf("*** You beat the dealer! ***\n"); 
        } else if ((21 - ply_sum) > (21 - com_sum)) {
            printf("*** Dealer wins ***\n");
        } else {
            printf("*** You tied the dealer, nobody wins. ***\n");
        }
    }
}