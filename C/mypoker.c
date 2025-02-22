#include<stdio.h>
#include<stdlib.h>
typedef enum {
    c,d,h,s
}suit;
typedef struct{
    char* suit;
    int rank;
}CARD;
void read(void);
void analyze(void);
void result(void);

int main (void){
    for(;;){
        read();
        analyze();
        result();
    }
}
void read(void){
    int card_in_hand=0;
    char rank_c, suit_c;
    CARD card[5];
    while(card_in_hand <5){
        scanf("%c%c", &rank_c,&suit_c);

    }
}