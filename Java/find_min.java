import java.util.Scanner;
public class find_min {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length =sc.nextInt();
        int[] array=new int [length];
        for(int i = 0; i <length; i++){
            array[i] =sc.nextInt();
        }
        int min = array[0];
        for(int i =0; i<length;i++){
            if(array[i]<min){
                min = array[i];
            }
        }
        System.out.println(min);
        for(int i =0; i<length; i++){
            System.out.println(array[i]-min);
        }
        sc.close();
    }
}
