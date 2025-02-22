/*Write the following function:

void remove_fi1ename(char *ur1);

url points to a string containing a URL that ends with a file name (such as "http://wvrw.knking.com/index.html"). 
The function should modify the string by removing the file name and the preceding slash. 
(In this example, theresult will be "http://www.knking.com".) 
Incorporate the “search for the end of a string“ idiom into your function. 
Hint: Have the function replace the last slash in the string by a null character.
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void remove_fi1ename(char *ur1);
int main (void){
    char fi1ename[100];
    fgets(fi1ename,sizeof(fi1ename), stdin);
    size_t len = strlen(fi1ename);
    if(fi1ename[len-1] == '\n'){
        fi1ename[len-1]='\0';
    }
    remove_fi1ename(fi1ename);
    return 0;
}
void remove_fi1ename(char *ur1){
    char *position = strrchr(ur1,'/');
    if(position){
        *position = '\0';
    }
    printf("%s", ur1);
}