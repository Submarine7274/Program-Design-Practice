#include <stdbool.h>
#include <stdio.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    //bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, suit_index, rank_index;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    // 給定的牌色和號碼數列
    int mySuit[] = {0, 2, 1, 2, 2, 0, 1, 1, 3, 3, 2, 0, 1, 2, 3, 2, 0, 1, 3, 0};
    int myRank[] = {3, 1, 10, 1, 5, 4, 6, 2, 12, 0, 11, 1, 5, 7, 0, 12, 2, 8, 5, 10};


    // 輸入發牌數
    //printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    // 輸入mySuit和myRank數列開始發牌的index
    //printf("Enter mySuit index to start dealing: ");
    scanf("%d", &suit_index);
    //printf("Enter myRank index to start dealing: ");
    scanf("%d", &rank_index);

    //printf("Your hand:");

    for (int i = 0; i < num_cards; i++) {
        int suit = mySuit[(suit_index + i) % 20];  // 以循環方式取得牌色
        int rank = myRank[(rank_index + i) % 20];  // 以循環方式取得號碼
        printf("%c%c ", rank_code[rank], suit_code[suit]);
        //if (!in_hand[suit][rank]) {
            //in_hand[suit][rank] = true;
            //printf("%c%c ", rank_code[rank], suit_code[suit]);
        //}
    }

    //printf("\n");

    return 0;
}