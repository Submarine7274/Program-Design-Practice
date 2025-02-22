import java.util.Scanner;
public class ArrayAdd { 
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int length1 =sc.nextInt();
        int[] array1 = new int[length1];
        for(int i = 0;i <length1; i++){
            array1[i] = sc.nextInt();
        }
        int length2 =sc.nextInt();
        int[] array2 = new int[length2];
        for(int i = 0;i <length2; i++){
            array2[i] = sc.nextInt();
        }
        if(length1 != length2){
            System.out.println("Error: Arrays must have the same length for addition.");
            return;
        }
        int[] resultarray = addArray(array1, array2);
        for(int value: resultarray){
            System.out.print(value + " ");
        }
        sc.close();
    }
    public static int[] addArray(int[] array1, int[] array2){
        int[] result = new int [array1.length];
        for(int i =0; i <array1.length; i++){
            result[i] = array1[i]+ array2[i];
        }
        return result;
    }
}
