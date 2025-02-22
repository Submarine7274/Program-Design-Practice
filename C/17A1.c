/*Write the following function:
bool test_extension(const char *file_name,eonst char *extension);
file__narne points to a string containing a file name.
The function should return true if the file's extension matches the string pointed to by extension. 
ignoring the case of let to-rs. For example. 
the call test_e:stensior1{ " memo . txt". "TXT") would returntrue. 
Incorporate the “search for the end of a string" idiom into your function. 
Him: Use the toupper function to convert characters to upper-case before comparing them.
*/
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

bool test_extension(const char *file_name,const char *extension);
int main (void){
    char file_name[100], extension[10];
    fgets(file_name,sizeof(file_name), stdin);
    fgets(extension,sizeof(extension),stdin);
    if(test_extension(file_name,extension)){
        printf("Extension matches.\n");
    }
    else{
        printf("Extension don't matches.\n");
    }
    return 0;
}
bool test_extension(const char *file_name,const char *extension){
    char *dotpostion = strrchr(file_name,'.');
    if(!dotpostion){
        return false;
    }
    dotpostion++;
    char file_extension[10];
    strcpy(file_extension, dotpostion);
    for(unsigned int i = 0; i< strlen(file_extension); i++){
       file_extension[i]=tolower((unsigned char)file_extension[i]);
    }
    char lowerextension[10];
    strcpy(lowerextension,extension);
    for(unsigned int i = 0; i< strlen(lowerextension); i++){
       lowerextension[i]=tolower((unsigned char)lowerextension[i]);
    }
    if(strcmp(file_extension,lowerextension) == 0){
        return true;
    }
    else{
        return false;
    }
}