import java.util.Scanner;
public class Bill2{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String item1 = sc.next();
        int quantity1 = sc.nextInt();
        double price1 = sc.nextDouble();
        double subTotal1 = quantity1 *price1;
        String item2 = sc.next();
        int quantity2 = sc.nextInt();
        double price2 = sc.nextDouble();
        double subTotal2 = quantity2 *price2;
        String item3 = sc.next();
        int quantity3 = sc.nextInt();
        double price3 = sc.nextDouble();
        double subTotal3 = quantity3 *price3;
        double total = subTotal1 + subTotal2 + subTotal3;
        System.out.printf("%s %d %.0f %.0f\n", item1, quantity1, price1, subTotal1);
        System.out.printf("%s %d %.0f %.0f\n", item2, quantity2, price2, subTotal2);
        System.out.printf("%s %d %.0f %.0f\n", item3, quantity3, price3, subTotal3);
        System.out.printf("sum %.0f", total);
        sc.close();
    }
}