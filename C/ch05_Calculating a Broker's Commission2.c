#include <stdio.h>

int main(void) {
    int ts;
    float cm;
    printf("Enter value of trade: ");
    scanf("%d", &ts);
    
    if (ts < 2000) {
        cm = ts * 0.02 + 50;
    } else if (ts < 6000) {
        cm = ts * 0.015 + 80;
    } else if (ts < 20000) {
        cm = ts * 0.01+ 110;
    } else if (ts < 55000) {
        cm = ts * 0.005 + 180;
    } else if (ts < 1000000) {
        cm = ts * 0.0015 + 200;
    } else {
        cm = ts * 0.0009 + 250;
    }

    if (cm < 70) {
        cm = 70;
    }

    printf("Commission: $%.2f", cm);
    return 0;
}