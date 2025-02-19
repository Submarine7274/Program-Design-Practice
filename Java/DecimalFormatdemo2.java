import java.text.DecimalFormat;
import java.util.Scanner;
public class DecimalFormatdemo2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        DecimalFormat percent = new DecimalFormat("0.00%");
        double x = sc.nextDouble();
        System.out.print(percent.format(x));
        sc.close();
    }
}