#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SUITS 4
#define RANKS 13
#define CARDS 5

int num_in_rank[RANKS];
int num_in_suits[SUITS];
bool straight= false, flush = false, four = false, three = false;
int pairs = 0;

void read_card(void);
void analyze(void);
void result(void);

int main(void){
    while(1){
    read_card();
    analyze();
    result();
    }
}

void read_card(void){
    bool exist_cards[RANKS][SUITS];
    bool badcard;
    int card_read = 0;
    int rank,suit;
    for(rank = 0; rank< RANKS; rank++){
        num_in_rank[rank]=0;
        for(suit =0; suit<SUITS; suit++){
            exist_cards[rank][suit]=false;
        }
    }
    for(suit = 0; suit< SUITS; suit++){
        num_in_suits[suit]=0;
    }
    while(read_card <CARDS){
        badcard = false;
        printf("Enter a card: ");
        char rank_ch = getchar();
        switch (rank_ch)
        {
        case'0': exit(EXIT_SUCCESS);
            break;
        case'2': rank = 0; break;
        case'3': rank = 1; break;
        case'4': rank = 2; break;
        case'5': rank = 3; break;
        case'6': rank = 4; break;
        case'7': rank = 5; break;
        case'8': rank = 6; break;
        case'9': rank = 7; break;
        case't': case'T': rank = 8; break;
        case'j': case'J': rank = 9; break;
        case'q': case'Q': rank = 10; break;
        case'k': case'K': rank = 11; break;
        case'a': case'A': rank = 12; break;
        default:
        badcard = true;
            break;
        }
        char suit_ch=getchar();
        switch (suit_ch)
        {
        case'c': case'C': suit = 0;break;
        case'd': case'D': suit = 1;break;
        case'h': case'H': suit = 2;break;
        case's': case'S': suit = 3;break;
        
        default:
        badcard = true;
            break;
        }
    char ch;
    while((ch = getchar())!= '\n'){
        if (ch = ' '){
            badcard = true;
        }
    }
    if(badcard){
        printf("Ignore");
    }
    else if(exist_cards[rank][suit]){
        printf("Ignore");
    }
    else{
        num_in_rank[rank]++;
        num_in_suits[suit]++
    }
    }
}