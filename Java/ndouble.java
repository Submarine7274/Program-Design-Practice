import java.util.Scanner;
public class ndouble{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double db = sc.nextDouble();
        double reciprocal = 1 / db;
        System.out.printf("%.0f", reciprocal);
    }
}