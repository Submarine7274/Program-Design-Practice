/*這題有不同寫法 可以用多個if else來窮舉 也可以用找最大邊後再看看是不是直角三角形*/
#include <stdio.h>
int main (void){
    int edge[3],largestEdge=0;  //宣告三個邊長陣列 跟最大邊變數
    for(int i=0;i<3;i++){
        scanf("%d", &edge[i]);
    }
    for(int i=0;i<3;i++){
        if(edge[i]>edge[largestEdge]){
            largestEdge = i;
        }
    }
    int a = edge[(largestEdge +1) %3];
    int b = edge[(largestEdge +2) %3];
    int c = edge[largestEdge];
    //畢氏定理 a^2 + b^2 = c^2
    if ((a*a + b*b) == (c*c)){
        printf("%d", c);
    }
    else{
        printf("Not a right triangle");
    }
    return 0;
}

/* #include <stdio.h> 這邊是另一種寫法 用多個if else來窮舉
int main (void){
    int edge[3];
    for(int i=0;i<3;i++){
        scanf("%d", &edge[i]);
    }
    if ((edge[0] * edge[0]) == ((edge[1] * edge[1]) + (edge[2] * edge[2]))){
        printf("%d", edge[0]);
    }
    else if((edge[1] * edge[1]) == ((edge[0] * edge[0]) + (edge[2] * edge[2]))){
        printf("%d", edge[1]);
    }
    else if((edge[2] * edge[2]) == ((edge[0] * edge[0]) + (edge[1] * edge[1]))){
        printf("%d", edge[2]);
    }
    else{
        printf("Not a right triangle");
    }
    return 0;
} */