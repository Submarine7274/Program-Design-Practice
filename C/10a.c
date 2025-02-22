/*The following function supposedly creates an identical copy of a string. What's wrong with 
the function‘?
char *dup1icate{const char *p)
{
char *q;
strcpy(q, p); 
return q;
}
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char *dup1icate(const char *p);
int main (void){
    char input[100];
    char *copy;
    fgets(input,sizeof(input) ,stdin);
    copy = dup1icate(input);
    printf("%s", copy);
    free(copy);
    return 0;
}
char *dup1icate(const char *p)
{
char *q= malloc(strlen(p)+1);
strcpy(q, p); 
return q;
}

