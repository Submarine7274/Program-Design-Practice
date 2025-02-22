#include <stdio.h>

// 函式: 生成螺旋矩陣
void generateSpiralMatrix(int n) {
    int matrix[n][n];
    
    // 定義四個方向：右、下、左、上
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int row = 0, col = 0, direction = 0, count = 1;

    // 初始化矩陣元素為 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    // 填充螺旋矩陣
    for (int i = 0; i < n * n; i++) {
        matrix[row][col] = count++;
        
        // 計算下一個位置
        int nextRow = row + directions[direction][0];
        int nextCol = col + directions[direction][1];

        // 檢查下一個位置是否合法並且未被訪問過
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && matrix[nextRow][nextCol] == 0) {
            row = nextRow;
            col = nextCol;
        } else {
            // 換下一個方向
            direction = (direction + 1) % 4;
            row += directions[direction][0];
            col += directions[direction][1];
        }
    }

    // 輸出螺旋矩陣
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n;

    // 輸入矩陣的大小
    scanf("%d", &n);

    // 生成並輸出螺旋矩陣
    generateSpiralMatrix(n);

    return 0;
}