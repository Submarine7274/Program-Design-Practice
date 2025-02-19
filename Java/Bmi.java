import java.util.Scanner;
public class Bmi{
    public static void main (String[] args){
        double result, height, weight;
        Scanner sc = new Scanner(System.in);
        height = sc.nextDouble();
        weight = sc.nextDouble();
        //System.out.printf("%f\n", height);
        //System.out.printf("%f\n", weight);
        height /= 100;
        //System.out.printf("%f\n", height);
        result = (double)weight /(height * height);
        //System.out.printf("%f\n", result);
        result =(int) (result *10);                     //結果要先乘以10才可以轉成整數
        //System.out.printf("%f\n", result);
        result = (double) result /10;
        System.out.printf("%.1f", result);
    }
}