import java.util.Scanner;
public class ArrayAddintwoD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row1 = sc.nextInt();
        int col1 = sc.nextInt();
        int[][] array1 = new int[row1][col1];
        for(int i = 0; i <row1; i++){
            for(int j=0; j< col1; j++){
                array1[i][j] = sc.nextInt();
            }
        }
        int row2 = sc.nextInt();
        int col2 = sc.nextInt();
        int[][] array2 = new int[row2][col2];
        for(int i = 0; i <row2; i++){
            for(int j=0; j< col2; j++){
                array2[i][j] = sc.nextInt();
            }
        }
        if(row1 != row2||col1 != col2){
            System.out.println("We need two same size matrix.");
            return;
        }
        int[][] resultarray = addArray(array1, array2);
        for(int i = 0; i <row1; i++){
            for(int j=0; j< col1; j++){
                System.out.print(resultarray[i][j]+" ");
                if(j == (col1-1)){
                    System.out.println(); 
                }
            }
        }
        sc.close();
    }
    public static int[][] addArray(int[][] array1, int[][] array2){
        int row = array1.length;
        int col = array1[0].length;
        int[][] result = new int [row][col];
        for(int i = 0; i <row; i++){
            for(int j=0; j< col; j++){
                result[i][j] = array1[i][j]+array2[i][j];
            }
        }
        return result;
    }
}
