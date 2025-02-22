#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define RANKS 13
#define SUITS 4

int num_in_rank[RANKS], num_in_suit[SUITS];
bool badcard = false, straight=false, flush=false, fourkind =false, threekind = false, duplicate = false;
int pairs =0;
void readCard(void);
void analysisCard(void);
void result(void);
int main (void){
    for(;;){
        readCard();
        analysisCard();
        result();
    }
}

void readCard(void){
    bool EXIST[RANKS][SUITS] ={false};
    int card_in_hand = 0;
    char rankc, suitc, ch;
    int rank,suit;
    for (int i = 0; i < RANKS; i++) num_in_rank[i] = 0;
    for (int i = 0; i < SUITS; i++) num_in_suit[i] = 0;
    badcard = false;
    duplicate = false;
    while(card_in_hand <5){
        //printf("Enter a card: ");
        rankc =getchar();
        switch (rankc){
        case '2': rank =0; break;
        case '3': rank =1; break;
        case '4': rank =2; break;
        case '5': rank =3; break;
        case '6': rank =4; break;
        case '7': rank =5; break;
        case '8': rank =6; break;
        case '9': rank =7; break;
        case 'T': case 't': rank = 8;break;
        case 'J': case 'j': rank = 9;break;
        case 'Q': case 'q': rank = 10;break;
        case 'K': case 'k': rank = 11;break;
        case 'A': case 'a': rank = 12;break;
        default:
        badcard =true;
        break;
        }
        suitc = getchar();
        switch (suitc){
        case 'C': case 'c': suit = 0;break;
        case 'D': case 'd': suit = 1;break;
        case 'H': case 'h': suit = 2;break;
        case 'S': case 's': suit = 3;break;
        default:
        badcard =true;
        break;
        }
        while((ch = getchar()) != '\n'){
            if(ch != ' '){
                badcard =true;
            }
        }
        if(EXIST[rank][suit]){
            duplicate =true;
        }
        
        EXIST[rank][suit] =true;
        num_in_rank[rank]++;
        num_in_suit[suit]++;
        card_in_hand++;
    }
}
void analysisCard(void){
    int consec = 0, rank=0;
    for(int suit =0; suit <4; suit++ ){
        if(num_in_suit[suit] ==5){
            flush =true;
        }
    }
    while(num_in_rank[rank] ==0){
        rank++;
    }
    for(;rank <13&&num_in_rank[rank] >0; rank++){
        consec++;
    }
    if(consec ==5){
        straight =true;
    }
    for(rank =0; rank <13; rank++){
        if(num_in_rank[rank] ==4){
            fourkind =true;
        }
        else if(num_in_rank[rank] ==3){
            threekind = true;
        }
        else if(num_in_rank[rank] ==2){
            pairs++;
        }
    }
}
void result(void){
    if(badcard ==true){
        printf("type11\n");
    }
    else if(duplicate ==true){
        printf("type10\n");
    }
    else if(straight == true &&flush == true){
        printf("type1\n");
    }
    else if(fourkind == true){
        printf("type2\n");
    }
    else if(threekind == true && pairs >0){
        printf("type3\n");
    }
    else if(flush == true){
        printf("type4\n");
    }
    else if(straight == true){
        printf("type5\n");
    }
    
    else if(threekind == true){
        printf("type6\n");
    }
    else if(pairs ==2){
        printf("type7\n");
    }
    else if(pairs ==1){
        printf("type8\n");
    }
    else{
        printf("type9\n");
    }
}