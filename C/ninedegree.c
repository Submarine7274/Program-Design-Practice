#include <stdio.h>

int sum(int number);     
int degrees(int number); 

int main(void) {
    int number;
    scanf("%d", &number);

    int result = degrees(number);
    printf("%d\n", result);

    return 0;
}

// 計算一個數字的位數總和
int sum(int number) {
    int total = 0;
    while (number > 0) {
        total += number % 10;  // 取出最後一位數字
        number /= 10;          // 去掉最後一位數字
    }
    return total;
}

// 計算 9-degree
int degrees(int number) {
    int degree = 0;  // 初始化 9-degree

    while (number % 9 == 0) {   // 檢查是否能被 9 整除
        degree++;               // 增加 degree 計數
        number /= 9;            // 更新數字為除以 9 的結果

        if (sum(number) % 9 != 0) {  
            break;  // 如果位數總和不能被 9 整除，結束迴圈
        }
    }

    return degree;  // 返回計算的 9-degree
}
