import java.util.Scanner;
public class Float{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        float f = sc.nextFloat();
        System.out.printf("%.1f", (10 * f));
        sc.close();
    }
}