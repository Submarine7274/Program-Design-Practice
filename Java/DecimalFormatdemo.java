import java.util.Scanner;
import java.text.DecimalFormat;
public class DecimalFormatdemo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        DecimalFormat f2 = new DecimalFormat("0.00");
        DecimalFormat f3 = new DecimalFormat("0.000");
        double x = sc.nextDouble();
        System.out.println(f2.format(x));
        System.out.print(f3.format(x));
        sc.close();
    }
}
