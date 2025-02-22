#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 8
const char *planets[NUM_PLANETS] = {
    "Mercury", "Venus", "Earth", "Mars", "Jupiter",
    "Saturn", "Uranus", "Neptune"
};

int main(void) {
    char input[50];
    bool found = false;

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    for (int i = 0; i < NUM_PLANETS; i++) {
        if (strcmp(input, planets[i]) == 0) {
            printf("%s is a planet.\n", input);
            found = true;
            break;
        }
    }

    if (found == false) {
        printf("%s is not a planet.\n", input);
    }

    return 0;
}
