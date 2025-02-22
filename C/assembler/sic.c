#include <stdio.h>

int main (int argc, char *argv[]){
    if (argc < 3){
        printf("Enter .exe name input file name output file name");
        return 1;
    }
    FILE *input = fopen(argv[1],"r");
    if(input == NULL){
        printf("Input file went wrong.");
        return 1;
    }
    FILE *output = fopen(argv[2], "a+");
    if(output == NULL){
        printf("Output file went wrong.");
        fclose(input);
        return 1;
    }
    char buffer[100];
    int start_location;
    printf("Loc 	");
    //fscanf(input,"%d",&start_location);
    //printf("%d", start_location);
    while(fgets(buffer, sizeof(buffer), input) != NULL){
        printf("%s", buffer);
    }
    fclose(input);
    fclose(output);
    return 0;
}