import java.text.DecimalFormat;
import java.util.Scanner;
public class DecimalFormatdemo3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        DecimalFormat option = new DecimalFormat("0.0##");
        double x = sc.nextDouble();
        System.out.print(option.format(x));
        sc.close();
    }
}