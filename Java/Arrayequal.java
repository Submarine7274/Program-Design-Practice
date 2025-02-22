import java.util.Scanner;
public class Arrayequal {
    public static void main(String[] args){
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
        boolean isEqual = cmparr(array1, array2);
        System.out.print(isEqual);
        sc.close();
    }
    public static boolean cmparr(int[] array1,int[] array2){
        if(array1.length != array2.length){
            return false;
        }
        for(int i = 0; i <array1.length; i++){
            if(array1[i] != array2[i]){
                return false;
            }
        }
        return true;
    }
}
