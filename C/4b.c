/*Write a program named reverse. c: that echoes its command-line arguments in reverse
order. Running the program by typing
reverse void and null
should produce the following output:
null and void
*/
#include<stdio.h>
int main (int argc ,char *argv[]){
    if(argc >2){
        for(int i =argc -1; i >0; i--){
            printf("%s", argv[i]);
            if(i >1){
            printf(" ");
            }
        }
    }
    return 0;
}