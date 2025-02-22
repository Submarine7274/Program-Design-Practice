#include <stdio.h>

int main(void) {
    const int numEmployees = 10;
    int salaries[numEmployees];
    int sum = 0;

    // 輸入員工薪水
    //printf("Enter salaries of 10 employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        scanf("%d", &salaries[i]);
        sum += salaries[i];
    }

    // 計算平均薪水
    double average = (double)sum / numEmployees;

    printf("%.2f\n", average);

    // 計算高於平均薪水的員工數量
    int aboveAverageCount = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (salaries[i] > average) {
            aboveAverageCount++;
        }
    }

    printf("%d", aboveAverageCount);

    return 0;
}