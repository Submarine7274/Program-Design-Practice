#include <stdio.h>

int main(void) {
    int ts;
    float cm;
    printf("Enter value of trade: ");
    scanf("%d", &ts);
    
    if (ts < 2500) {
        cm = ts * 0.017 + 30;
    } else if (ts < 6250) {
        cm = ts * 0.0066 + 56;
    } else if (ts < 20000) {
        cm = ts * 0.0034 + 76;
    } else if (ts < 50000) {
        cm = ts * 0.0022 + 100;
    } else if (ts < 500000) {
        cm = ts * 0.0011 + 155;
    } else {
        cm = ts * 0.0009 + 255;
    }

    if (cm < 39) {
        cm = 39;
    }

    printf("Commission: $%.2f", cm);
    return 0;
}