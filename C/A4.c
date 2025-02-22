/*Write a program that asks the user to enter an interactional dialing code and then looks it up
in the country_codee array (see Section 16.3). 
If it finds the code. the program should display the name of the corresponding country: 
if not, the program should print an error message.
*/
#include<stdio.h>
#include<stdbool.h>
typedef struct{
    char *country;
    int code;
}country_codes;

int main (void){
    bool found =false;
    const country_codes country_code[] =
    {{"Argentina", 54}, {"Bangladesh", 880},
    {"Brazil", 55}, {"Burma (Myanmar)", 95},
    {"China", 86}, {"Colombia", 57},{"Taiwan", 886},
    {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
    {"Ethiopia", 251}, {"France", 33},
    {"Germany", 49}, {"India", 91},
    {"Indonesia", 62}, {"Iran", 98},
    {"Italy", 39}, {"Japan", 81},
    {"Mexico", 52}, {"Nigeria", 234},
    {"Pakistan", 92}, {"Philippines", 63},
    {"Poland", 48}, {"Russia", 7},
    {"South Africa", 27}, {"South Korea", 82},
    {"Spain", 34}, {"Sudan", 249},
    {"Thailand", 66}, {"Turkey", 90},
    {"Ukraine", 380}, {"United Kingdom", 44},
    {"United States", 1}, {"Vietnam", 84}};
    int input_code;
    scanf("%d", &input_code);
    int countries = sizeof(country_code) / sizeof(country_code[0]);
    for(int i =0; i<countries; i++){
        if(country_code[i].code ==input_code){
            printf("%s", country_code[i].country);
            found = true;
            break;
        }
    }
    if(!found){
        printf("error");
    }
    return 0;
}