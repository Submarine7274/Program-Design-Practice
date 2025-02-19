import java.util.Scanner;

public class ArrayMultiply {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 輸入第一個矩陣
        int row1 = sc.nextInt();
        int col1 = sc.nextInt();
        int[][] matrix1 = new int[row1][col1];
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }

        // 輸入第二個矩陣
        int row2 = sc.nextInt();
        int col2 = sc.nextInt();
        int[][] matrix2 = new int[row2][col2];
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }

        // 檢查矩陣是否可以相乘
        if (col1 != row2) {
            System.out.println("Matrix multiplication is not possible!");
            return;
        }

        // 計算乘積矩陣
        int[][] resultMatrix = multiplyMatrices(matrix1, matrix2);

        // 輸出結果矩陣
        for (int i = 0; i < resultMatrix.length; i++) {
            for (int j = 0; j < resultMatrix[i].length; j++) {
                System.out.print(resultMatrix[i][j] + " ");
            }
            //System.out.println();
        }
        sc.close();
    }

    // 矩陣乘法方法
    public static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2) {
        int rows = matrix1.length; // 第一個矩陣的行數
        int cols = matrix2[0].length; // 第二個矩陣的列數
        int common = matrix1[0].length; // 第一個矩陣的列數 = 第二個矩陣的行數

        int[][] result = new int[rows][cols];

        // 計算乘積矩陣
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < common; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }
}
