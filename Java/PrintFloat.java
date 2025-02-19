import java.util.Scanner;
public class PrintFloat {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        float f = sc.nextFloat();
        System.out.printf("Start%10.2fEnd\n", f);
        System.out.printf("Start%-10.2fEnd", f);
        sc.close();
    }
}
