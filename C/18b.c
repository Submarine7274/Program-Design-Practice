/*Write a program that accepts a date from the user in the form III!!!/dd/_‘t-‘_\-‘_1’}' and then displays
it in the form month dd, _t~_ry_i-. 
where mom‘: is the name of the month:
Enter a date {mm/dd/yyyy]: 2/17[2D1l
You entered the date February 17, 2011
Store the month names in an array that contains pointers to strings.
*/
#include <stdio.h>
#include<string.h>
int main (void){
    int input_day, input_month, input_year;
    char *output_month[12]= {"January", "February", "March", "April","May","June", "July", "August","September","October","November","December"};
    printf("Enter a date : (mm/dd/yyyy)");
    scanf("%2d/%2d/%4d",&input_month,&input_day,&input_year);
    if (input_month < 1 || input_month > 12) {
    printf("Error: Invalid month.\n");
    return 1; 
    }
    printf("You entered the date %s %2d,%4d", output_month[input_month-1], input_day, input_year);
   return 0;
}