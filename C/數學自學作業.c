#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 3) + 2 * x - 1.5; 
}

double f_derivative(double x) {
    return 3 * pow(x, 2) + 2;
}

void newton_method(double x) {
    int i;
    double xn, epsilon = 1e-10; 

    printf("x1 = %.10f\n", x);

    for (i = 1; ; ++i) {
        xn = x - f(x) / f_derivative(x);
        printf("x%d = %.10f\n", i + 1, xn);

        if (fabs(xn - x) < epsilon) {
            printf("在 x%d = %.10f 有跟x%d小數點後10位有相同結果\n", i + 1, xn, i);
            printf("將結果 %.10f 帶入原函數 f(x) = x³ + 2x - 1.5 中的結果為: %.10f\n", xn, f(xn));
            break;
        }

        x = xn;
    }
}

int main() {
    printf("我的學號為:ACS112111, 我的函數為x\u00B3 + 2x - 1.5\n");
    double x1 = 1.0; 
    newton_method(x1);

    return 0;
}