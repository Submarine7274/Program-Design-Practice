import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;
public class TheNumberFormat2 {
    public static void main(String[] args){
        NumberFormat nt = NumberFormat.getCurrencyInstance(Locale.TAIWAN);
        NumberFormat us = NumberFormat.getCurrencyInstance(Locale.US);
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        System.out.println(us.format(x));
        System.out.print(nt.format(x));
        sc.close();
    }
}