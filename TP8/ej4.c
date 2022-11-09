/*
 * Simular un juego de naipes de 52 cartas, en el cual se mezcle el mazo y se 
 * tomen las 5 primeras cartas, indicando si se obtuvo alguna de las 
 * siguientes configuraciones:
 * PAR:  hay sólo dos de las cinco cartas con igual valor
 * PIERNA:  hay sólo tres de las cinco cartas de igual valor
 * POKER: hay cuatro cartas con igual valor
 */

#include <stdio.h>
#include "/home/uriel/PI/random.h"
#define DECK_SIZE   52 /* TYPES*VALS */
#define TYPES   4
#define VALS    13
#define ROUND_SIZE  5

typedef enum {
    HEART=0,
    SPADE,
    CLUBS,
    DIAMOND
} Type;

typedef struct TCard {
    Type type;
    char value;
} TCard;

typedef TCard TDeck[DECK_SIZE];
typedef TCard TRound[ROUND_SIZE];

char * names[] = {"0", "PAR", "PIERNA", "POKER"};

void newDeck(TDeck deck);
void shuffleDeck(TDeck deck);
int roundValue(TRound round);
void updateDeck(TRound round, TDeck deck);
void printDeck(TRound round);
void printWelcome();

int main()
{
    randomize();
    
    printWelcome();

    TDeck deck;
    TRound round;
    newDeck(deck);

    int rnd_value;
    /* Mientras el usuario quiera jugar */
    unsigned char c;
    do {
        shuffleDeck(deck);
        updateDeck(round, deck);
        rnd_value = roundValue(round);
        printDeck(round); 
        printf("Your round results: %s\n", names[rnd_value]); 
        puts("Press SPACE to play again.");
    } while ((c = getchar()) != EOF);
    return 0;
}

void printWelcome()
{
    puts("-----------------");
    puts("Welcome to POKER!");
    puts("-----------------");
}

void printDeck(TRound round) 
{
    puts("--- DECK ---");
    puts("TYPE\tNUMBER");
    for (int i = 0; i < ROUND_SIZE; i++) {
       printf("%d\t%d\n", round[i].type, round[i].value); 
    }
}
void newDeck(TDeck deck)
{
    for (int i = 0; i < DECK_SIZE; i++) {
        /* Forma que vi por juani */
        deck[i].type = i % TYPES; 
        deck[i].value = i % VALS;
    }
}

void shuffleDeck(TDeck deck)
{
    TCard swpCard;
    for (int i = 0, random; i < DECK_SIZE; i++) {
       int rand = randInt(0, i);
       swpCard = deck[rand];
       deck[rand] = deck[i];
       deck[i] = swpCard;
    }
}

int roundValue(TRound round) 
{
    int ctr = 0, match_ctr = 0;

    for (int i = 0; i < ROUND_SIZE-1; i++) {
        ctr = 0;
        for (int j = 0; j < ROUND_SIZE; j++) {
            // Check igual valor y que no sean la misma carta. */
            if ( i != j && round[i].value == round[j].value) 
                ctr++;
        }
        match_ctr = (ctr > match_ctr) ? ctr : match_ctr ;
    }

    return match_ctr;
}

void updateDeck(TRound round, TDeck deck)
{
    unsigned int cards_ctr = DECK_SIZE-1;
    for (int i = 0; i < ROUND_SIZE; i++) {
        int rand = randInt(0, i);
        round[i] = deck[rand];
        deck[rand] = deck[cards_ctr];
        cards_ctr--;
    }

}
