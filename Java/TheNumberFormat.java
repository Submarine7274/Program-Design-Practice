import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;
public class TheNumberFormat {
    public static void main(String[] args){
        NumberFormat nt = NumberFormat.getCurrencyInstance(Locale.TAIWAN);
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        System.out.printf("%s", nt.format(x));
        sc.close();
    }
}