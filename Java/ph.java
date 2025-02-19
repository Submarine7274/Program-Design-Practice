import java.util.Scanner;
public class ph{
    public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    double phH = sc.nextDouble();
    double ph = 14 + Math.log10(phH);
    System.out.printf("%.2f", ph);
    }
}