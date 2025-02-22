#include<stdio.h>
int main (void){
    int mi = 0, mx = 100, a, m;
    printf("Enter the answer number(0-100):\n");
    scanf("%d", &a);
    printf("Game start!\n");
    printf("\n");
    do {
        printf("Enter a number(%d-%d):\n",mi ,mx);
        scanf("%d", &m);
        if (m < a && mi < m) {
            mi = m;
            }
        else if (m > a && mx > m){
            mx = m;
            }
        else if (m == a) {printf("BANG!");
        }
    }
    while(m != a);
    return 0;
}